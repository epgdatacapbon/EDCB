#include "StdAfx.h"
#include "TSBuffUtil.h"

CTSBuffUtil::CTSBuffUtil(void)
{
	this->lastPID = 0xFFFF;
	this->lastCounter = 0xFF;

	this->creatingBuff = NULL;
	this->lastGetBuff = NULL;

	this->duplicateFlag = FALSE;
}

CTSBuffUtil::~CTSBuffUtil(void)
{
	Clear();
	SAFE_DELETE(this->lastGetBuff);
}

void CTSBuffUtil::Clear()
{
	for(size_t i=0; i<this->packetList.size(); i++ ){
		SAFE_DELETE(this->packetList[i]);
	}
	this->packetList.clear();

	this->lastPID = 0xFFFF;
	this->lastCounter = 0xFF;

	SAFE_DELETE(this->creatingBuff);
}

BOOL CTSBuffUtil::CheckCounter(CTSPacketUtil* tsPacket)
{
	if( tsPacket->PID == 0x1FFF ){
		//NULL�p�P�b�g���͈Ӗ��Ȃ�
		this->duplicateFlag = FALSE;
		return TRUE;
	}
	if( this->lastPID != 0xFFFF || this->lastCounter != 0xFF ){
		if( this->lastPID != tsPacket->PID ){
			//PID�ύX���ꂽ�̂ŕs�A��
			this->duplicateFlag = FALSE;
			return FALSE;
		}else{
			if( tsPacket->adaptation_field_control == 0x00 || tsPacket->adaptation_field_control == 0x02 ){
				//�y�C���[�h�����݂��Ȃ��ꍇ�͈Ӗ��Ȃ�
				this->duplicateFlag = FALSE;
				if( tsPacket->adaptation_field_control == 0x02 || tsPacket->adaptation_field_control == 0x03 ){
					if(tsPacket->discontinuity_indicator == 1){
						//�s�A���̔��肪�K�v
						return FALSE;
					}else{
						return TRUE;
					}
				}else{
					return TRUE;
				}
			}
			if( this->lastCounter == tsPacket->continuity_counter ){
				if( tsPacket->adaptation_field_control == 0x01 || tsPacket->adaptation_field_control == 0x03 ){
					if( this->duplicateFlag == FALSE ){
						//�d���H�ꉞ�A���Ɣ���
						this->duplicateFlag = TRUE;
						if( tsPacket->adaptation_field_control == 0x02 || tsPacket->adaptation_field_control == 0x03 ){
							if(tsPacket->discontinuity_indicator == 1){
								//�s�A���̔��肪�K�v
								return FALSE;
							}else{
								return TRUE;
							}
						}else{
							return TRUE;
						}
					}else{
						//�O��d���Ɣ��f���Ă�̂ŕs�A��
						this->duplicateFlag = FALSE;
						return FALSE;
					}
				}
			}
			if( this->lastCounter+1 != tsPacket->continuity_counter ){
				if( this->lastCounter != 0x0F && tsPacket->continuity_counter != 0x00 ){
					//�J�E���^�[����񂾂̂ŕs�A��
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}

DWORD CTSBuffUtil::Add188TS(CTSPacketUtil* tsPacket)
{
	if( tsPacket == NULL ){
		return FALSE;
	}

	//�J�E���^�[�`�F�b�N
	if( CheckCounter(tsPacket) == FALSE ){
		Clear();
	}
	//�X�N�����u���̃`�F�b�N
	if( tsPacket->transport_scrambling_control != 0 ){
		//�X�N�����u���p�P�b�g�Ȃ̂ŉ�͂ł��Ȃ�
		Clear();
		return ERR_NOT_SUPPORT;
	}

	if( this->lastPID == 0xFFFF && this->lastCounter == 0xFF ){
		//����
		if( tsPacket->payload_unit_start_indicator == 1 ){
			if( tsPacket->data_byteSize < 3 ){
				//�T�C�Y������������
				return FALSE;
			}
			if(tsPacket->data_byte[0] == 0x00 && tsPacket->data_byte[1] == 0x00 && tsPacket->data_byte[2] == 0x01){
				//PES
				return ERR_NOT_SUPPORT;
			}else{
				//PSI
				this->lastPID = tsPacket->PID;
				this->lastCounter = tsPacket->continuity_counter;
				return AddSectionBuff(tsPacket);
			}
		}else{
			//�X�^�[�g�ʒu�ł͂Ȃ�
			return ERR_ADD_NEXT;
		}
	}else{
		this->lastPID = tsPacket->PID;
		this->lastCounter = tsPacket->continuity_counter;
		return AddSectionBuff(tsPacket);
	}

}

BOOL CTSBuffUtil::GetSectionBuff(BYTE** sectionData, WORD* dataSize)
{
	SAFE_DELETE(lastGetBuff);
	if( packetList.size() == 0 ){
		return FALSE;
	}

	lastGetBuff = packetList[0];
	packetList.erase(packetList.begin());

	*sectionData = lastGetBuff->data;
	*dataSize = lastGetBuff->dataSize;

	return TRUE;
}

DWORD CTSBuffUtil::AddSectionBuff(CTSPacketUtil* tsPacket)
{
	if( tsPacket == NULL ){
		return FALSE;
	}
	if( tsPacket->data_byteSize == 0 || tsPacket->data_byte == NULL ){
		return ERR_ADD_NEXT;
	}
	if( tsPacket->payload_unit_start_indicator != 1 && creatingBuff == NULL ){
		return ERR_ADD_NEXT;
	}

	BYTE readSize = 0;
	if( tsPacket->payload_unit_start_indicator == 1 ){
		BOOL addBuff = FALSE;
		BYTE pointer_field = tsPacket->data_byte[0];
		readSize++;
		if( pointer_field != 0 ){
			//�}���`�Z�N�V����
			if( creatingBuff != NULL ){
				if( creatingBuff->dataSize - creatingBuff->copySize == pointer_field ){
					memcpy(creatingBuff->data + creatingBuff->copySize, tsPacket->data_byte + readSize, pointer_field);
					creatingBuff->copySize += pointer_field;
					packetList.push_back(creatingBuff);
					creatingBuff = NULL;
					addBuff = TRUE;
				}else{
					//�T�C�Y�����������̂ŃN���A
					_OutputDebugString(L"multi section size err");
					SAFE_DELETE(creatingBuff);
				}
			}
		}
		readSize+=pointer_field;

		if( readSize + 3 > tsPacket->data_byteSize ){
			//�T�C�Y������������
			_OutputDebugString(L"psi size err");
			if( addBuff == TRUE ){
				return TRUE;
			}else{
				return FALSE;
			}
		}

		SECTION_BUFF* buff = new SECTION_BUFF;
		creatingBuff = buff;
		buff->dataSize = (((WORD)tsPacket->data_byte[readSize+1]&0x0F) << 8 | tsPacket->data_byte[readSize+2]) + 3;
		buff->data = new BYTE[buff->dataSize];

//		_OutputDebugString(L"need size 0x%04x %d\r\n", tsPacket->PID, buff->dataSize);

		if( buff->dataSize <= tsPacket->data_byteSize - readSize ){
			buff->copySize = buff->dataSize;
		}else{
			buff->copySize = tsPacket->data_byteSize - readSize;
		}

		memcpy( buff->data, tsPacket->data_byte+readSize, buff->copySize );

		if( buff->copySize == buff->dataSize ){
			//���̃p�P�b�g�����Ŋ���
			packetList.push_back(creatingBuff);
			creatingBuff = NULL;
			return TRUE;
		}else{
			//���̃p�P�b�g�K�v
			if( addBuff == TRUE ){
				return TRUE;
			}else{
				return ERR_ADD_NEXT;
			}
		}
	}else{
		//�����p�P�b�g�ɂ܂������Ă���
		WORD copySize = 0;
		WORD needSize = creatingBuff->dataSize - creatingBuff->copySize;

		if( needSize <= tsPacket->data_byteSize ){
			copySize = needSize;
		}else{
			copySize = tsPacket->data_byteSize;
		}

		memcpy( creatingBuff->data + creatingBuff->copySize, tsPacket->data_byte, copySize );

		creatingBuff->copySize += copySize;
		if( creatingBuff->dataSize == creatingBuff->copySize ){
			packetList.push_back(creatingBuff);
			creatingBuff = NULL;
			return TRUE;
		}else{
			return ERR_ADD_NEXT;
		}
	}
}

