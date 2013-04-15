#include "StdAfx.h"
#include "BITTable.h"

#include "../../../Common/EpgTimerUtil.h"
#include "../Descriptor/Descriptor.h"

CBITTable::CBITTable(void)
{
}

CBITTable::~CBITTable(void)
{
	Clear();
}

void CBITTable::Clear()
{
	for( size_t i=0 ;i<descriptorList.size(); i++ ){
		SAFE_DELETE(descriptorList[i]);
	}
	descriptorList.clear();
	for( size_t i=0 ;i<broadcasterDataList.size(); i++ ){
		SAFE_DELETE(broadcasterDataList[i]);
	}
	broadcasterDataList.clear();
}

BOOL CBITTable::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
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

	if( section_syntax_indicator != 1 ){
		//�Œ�l����������
		_OutputDebugString( L"++CBITTable:: section_syntax err" );
		return FALSE;
	}
	if( table_id != 0xC4 ){
		//table_id����������
		_OutputDebugString( L"++CBITTable:: table_id err 0x%02X", table_id );
		return FALSE;
	}
	if( readSize+section_length > dataSize && section_length > 3){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++CBITTable:: size err %d > %d", readSize+section_length, dataSize );
		return FALSE;
	}
	//CRC�`�F�b�N
	crc32 = ((DWORD)data[3+section_length-4])<<24 |
		((DWORD)data[3+section_length-3])<<16 |
		((DWORD)data[3+section_length-2])<<8 |
		data[3+section_length-1];
	if( crc32 != _Crc32(3+section_length-4, data) ){
		_OutputDebugString( L"++CBITTable:: CRC err" );
		return FALSE;
	}

	if( section_length > 8 ){
		original_network_id = ((WORD)data[readSize])<<8 | data[readSize+1];
		version_number = (data[readSize+2]&0x3E)>>1;
		current_next_indicator = data[readSize+2]&0x01;
		section_number = data[readSize+3];
		last_section_number = data[readSize+4];
		broadcast_view_propriety = (data[readSize+5]&0x10)>>4;
		first_descriptors_length = ((WORD)data[readSize+5]&0x0F)<<8 | data[readSize+6];
		readSize += 7;
		if( readSize+first_descriptors_length <= (DWORD)section_length+3-4 && first_descriptors_length > 0){
			CDescriptor descriptor;
			if( descriptor.Decode( data+readSize, first_descriptors_length, &descriptorList, NULL ) == FALSE ){
				_OutputDebugString( L"++CBITTable:: descriptor err" );
				return FALSE;
			}
			readSize+=first_descriptors_length;
		}
		while( readSize < (DWORD)section_length+3-4 ){
			BROADCASTER_DATA* item = new BROADCASTER_DATA;
			item->broadcaster_id = data[readSize];
			item->broadcaster_descriptors_length = ((WORD)data[readSize+1]&0x0F)<<8 | data[readSize+2];
			readSize+=3;
			if( readSize+item->broadcaster_descriptors_length <= (DWORD)section_length+3-4 && item->broadcaster_descriptors_length > 0){
				CDescriptor descriptor;
				if( descriptor.Decode( data+readSize, item->broadcaster_descriptors_length, &(item->descriptorList), NULL ) == FALSE ){
					_OutputDebugString( L"++CBITTable:: descriptor2 err" );
					return FALSE;
				}
			}

			readSize+=item->broadcaster_descriptors_length;

			broadcasterDataList.push_back(item);
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

