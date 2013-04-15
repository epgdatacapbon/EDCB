#include "StdAfx.h"
#include "BouquetNameDesc.h"

CBouquetNameDesc::CBouquetNameDesc(void)
{
	nameLength = 0;
	name = NULL;
}

CBouquetNameDesc::~CBouquetNameDesc(void)
{
	SAFE_DELETE_ARRAY(name);
}

BOOL CBouquetNameDesc::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}
	SAFE_DELETE_ARRAY(name);
	nameLength = 0;

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

	if( descriptor_tag != 0x47 ){
		//�^�O�l����������
		_OutputDebugString( L"++++CBouquetNameDesc:: descriptor_tag err 0x47 != 0x%02X", descriptor_tag );
		return FALSE;
	}

	nameLength = descriptor_length;
	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CBouquetNameDesc:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		name = new BYTE[descriptor_length];
		memcpy( name, data+readSize, descriptor_length );
		readSize += descriptor_length;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}

