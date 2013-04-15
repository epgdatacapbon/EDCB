#include "StdAfx.h"
#include "CATTable.h"

#include "../../../Common/EpgTimerUtil.h"
#include "../Descriptor/Descriptor.h"

CCATTable::CCATTable(void)
{
}

CCATTable::~CCATTable(void)
{
	Clear();
}

void CCATTable::Clear()
{
	for( size_t i=0 ;i<descriptorList.size(); i++ ){
		SAFE_DELETE(descriptorList[i]);
	}
	descriptorList.clear();
}

BOOL CCATTable::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}
	Clear();

	//////////////////////////////////////////////////////
	//�T�C�Y�̃`�F�b�N
	//�Œ��table_id��section_length+CRC�̃T�C�Y�͕K�{
	if( dataSize < 7 ){
		return FALSE;
	}
	//->�T�C�Y�̃`�F�b�N

	DWORD readSize = 0;
	//////////////////////////////////////////////////////
	//��͏���
	table_id = data[0];
	section_syntax_indicator = (data[1]&0x80)>>7;
	section_length = ((WORD)data[1]&0x0F)<<8 | data[2];
	readSize+=3;

	if( section_syntax_indicator != 1 || (data[1]&0x40) != 0 ){
		//�Œ�l����������
		_OutputDebugString( L"++CCATTable:: section_syntax err" );
		return FALSE;
	}
	if( table_id != 0x01 ){
		//table_id����������
		_OutputDebugString( L"++CCATTable:: table_id err 0x01 != 0x%02X", table_id );
		return FALSE;
	}
	if( readSize+section_length > dataSize && section_length > 3){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++CCATTable:: size err %d > %d", readSize+section_length, dataSize );
		return FALSE;
	}
	//CRC�`�F�b�N
	crc32 = ((DWORD)data[3+section_length-4])<<24 |
		((DWORD)data[3+section_length-3])<<16 |
		((DWORD)data[3+section_length-2])<<8 |
		data[3+section_length-1];
	if( crc32 != _Crc32(3+section_length-4, data) ){
		_OutputDebugString( L"++CCATTable:: CRC err" );
		return FALSE;
	}

	if( section_length > 4 ){
		version_number = (data[readSize+2]&0x3E)>>1;
		current_next_indicator = data[readSize+2]&0x01;
		section_number = data[readSize+3];
		last_section_number = data[readSize+4];
		readSize += 5;
		if( readSize <= (DWORD)section_length+3-4 ){
			DWORD descriptorSize = (DWORD)(section_length+3-4) - readSize;
			if( descriptorSize > 0 ){
				CDescriptor descriptor;
				if( descriptor.Decode( data+readSize, descriptorSize, &descriptorList, NULL ) == FALSE ){
					_OutputDebugString( L"++CCATTable:: descriptor err" );
					return FALSE;
				}
				readSize+=descriptorSize;
			}
		}
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 3+section_length;
	}

	return TRUE;
}
