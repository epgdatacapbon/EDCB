#include "StdAfx.h"
#include "TDTTable.h"

#include "../../../Common/EpgTimerUtil.h"
#include "../Descriptor/Descriptor.h"

CTDTTable::CTDTTable(void)
{
}

CTDTTable::~CTDTTable(void)
{
}

BOOL CTDTTable::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}

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
		_OutputDebugString( L"++CTDTTable:: section_syntax err" );
		return FALSE;
	}
	if( table_id != 0x70 ){
		//table_id����������
		_OutputDebugString( L"++CTDTTable:: table_id err 0x%02X", table_id );
		return FALSE;
	}
	if( section_length != 0x0005){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++CTDTTable:: size err %d > %d", readSize+section_length, dataSize );
		return FALSE;
	}

	if( section_length > 4 ){
		DWORD mjd = ((DWORD)data[readSize])<<8 | data[readSize+1];
		_MJDtoSYSTEMTIME(mjd, &jst_time);
		jst_time.wHour = (WORD)_BCDtoDWORD(data+readSize+2, 1, 2);
		jst_time.wMinute = (WORD)_BCDtoDWORD(data+readSize+3, 1, 2);
		jst_time.wSecond = (WORD)_BCDtoDWORD(data+readSize+4, 1, 2);

		readSize += 5;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 3+section_length;
	}

	return TRUE;
}

