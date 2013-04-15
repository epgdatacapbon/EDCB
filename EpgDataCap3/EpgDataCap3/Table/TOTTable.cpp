#include "StdAfx.h"
#include "TOTTable.h"

#include "../../../Common/EpgTimerUtil.h"
#include "../Descriptor/Descriptor.h"

CTOTTable::CTOTTable(void)
{
}

CTOTTable::~CTOTTable(void)
{
}

void CTOTTable::Clear()
{
	for( size_t i=0 ;i<descriptorList.size(); i++ ){
		SAFE_DELETE(descriptorList[i]);
	}
	descriptorList.clear();
}

BOOL CTOTTable::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
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

	if( section_syntax_indicator != 0 ){
		//�Œ�l����������
		_OutputDebugString( L"++CTOTTable:: section_syntax err" );
		return FALSE;
	}
	if( table_id != 0x73 ){
		//table_id����������
		_OutputDebugString( L"++CTOTTable:: table_id err 0x%02X", table_id );
		return FALSE;
	}
	if( readSize+section_length > dataSize && section_length > 3){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++CTOTTable:: size err %d > %d", readSize+section_length, dataSize );
		return FALSE;
	}
	//CRC�`�F�b�N
	crc32 = ((DWORD)data[3+section_length-4])<<24 |
		((DWORD)data[3+section_length-3])<<16 |
		((DWORD)data[3+section_length-2])<<8 |
		data[3+section_length-1];
	if( crc32 != _Crc32(3+section_length-4, data) ){
		_OutputDebugString( L"++CTOTTable:: CRC err" );
		return FALSE;
	}

	if( section_length > 4 ){
		DWORD mjd = ((DWORD)data[readSize])<<8 | data[readSize+1];
		_MJDtoSYSTEMTIME(mjd, &jst_time);
		jst_time.wHour = (WORD)_BCDtoDWORD(data+readSize+2, 1, 2);
		jst_time.wMinute = (WORD)_BCDtoDWORD(data+readSize+3, 1, 2);
		jst_time.wSecond = (WORD)_BCDtoDWORD(data+readSize+4, 1, 2);
		readSize += 5;

		descriptors_loop_length = ((WORD)data[readSize]&0x0F)<<8 | data[readSize+1];
		readSize += 2;

		if( readSize+descriptors_loop_length <= (DWORD)section_length+3-4 && descriptors_loop_length > 0){
			CDescriptor descriptor;
			if( descriptor.Decode( data+readSize, descriptors_loop_length, &descriptorList, NULL ) == FALSE ){
				_OutputDebugString( L"++CTOTTable:: descriptor2 err" );
				return FALSE;
			}
		}

		readSize+=descriptors_loop_length;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 3+section_length;
	}

	return TRUE;
}
