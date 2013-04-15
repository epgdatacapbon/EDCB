#include "StdAfx.h"
#include "ContentAvailabilityDesc.h"

CContentAvailabilityDesc::CContentAvailabilityDesc(void)
{
}

CContentAvailabilityDesc::~CContentAvailabilityDesc(void)
{
}

BOOL CContentAvailabilityDesc::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
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

	if( descriptor_tag != 0xDE ){
		//�^�O�l����������
		_OutputDebugString( L"++++CContentAvailabilityDesc:: descriptor_tag err 0xDE != 0x%02X", descriptor_tag );
		return FALSE;
	}

	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CContentAvailabilityDesc:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		copy_restriction_mode = (data[readSize]&0x40)>>6;
		image_constraint_token = (data[readSize]&0x20)>>5;
		retention_mode = (data[readSize]&0x10)>>4;
		retention_state = (data[readSize]&0x0E)>>1;
		encryption_mode = data[readSize]&0x01;
		readSize++;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}
