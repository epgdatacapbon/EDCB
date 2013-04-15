#include "StdAfx.h"
#include "SatelliteDeliverySysDesc.h"

#include "../../../Common/EpgTimerUtil.h"

CSatelliteDeliverySysDesc::CSatelliteDeliverySysDesc(void)
{
}

CSatelliteDeliverySysDesc::~CSatelliteDeliverySysDesc(void)
{
}

BOOL CSatelliteDeliverySysDesc::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}

	//////////////////////////////////////////////////////
	//�T�C�Y�̃`�F�b�N
	//�Œ��descriptor_tag��descriptor_length�̃T�C�Y�͕K�{
	if( dataSize < 2 ){
		return FALSE;
	}
	//->�T�C�Y�̃`�F�b�N

	DWORD readSize = 0;
	//////////////////////////////////////////////////////
	//��͏���
	descriptor_tag = data[0];
	descriptor_length = data[1];
	readSize += 2;

	if( descriptor_tag != 0x43 ){
		//�^�O�l����������
		_OutputDebugString( L"++++CSatelliteDeliverySysDesc:: descriptor_tag err 0x43 != 0x%02X", descriptor_tag );
		return FALSE;
	}

	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CSatelliteDeliverySysDesc:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		frequency = ((double)_BCDtoDWORD(data + readSize, 4, 8))/100000;
		readSize+=4;
		orbital_position = ((double)_BCDtoDWORD(data + readSize, 2, 4))/10;
		readSize+=2;
		west_east_flag = (data[readSize]&0x80)>>7;
		polarisation = (data[readSize]&0x60)>>5;
		modulation = data[readSize]&0x1F;
		readSize++;
		frequency = ((double)_BCDtoDWORD(data + readSize, 4, 7))/10000;
		FEC_inner = data[readSize+3]&0x0F;
		readSize+=4;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}
