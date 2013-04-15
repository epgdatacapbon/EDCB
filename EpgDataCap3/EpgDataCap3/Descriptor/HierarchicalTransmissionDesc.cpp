#include "StdAfx.h"
#include "HierarchicalTransmissionDesc.h"

CHierarchicalTransmissionDesc::CHierarchicalTransmissionDesc(void)
{
}

CHierarchicalTransmissionDesc::~CHierarchicalTransmissionDesc(void)
{
}

BOOL CHierarchicalTransmissionDesc::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
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

	if( descriptor_tag != 0xC0 ){
		//�^�O�l����������
		_OutputDebugString( L"++++CHierarchicalTransmissionDesc:: descriptor_tag err 0xC0 != 0x%02X", descriptor_tag );
		return FALSE;
	}

	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CHierarchicalTransmissionDesc:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		quality_level = data[readSize]&0x01;
		reference_PID = ((WORD)data[readSize+1]&0x1F)<<8 | data[readSize+2];
		readSize += 3;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}
