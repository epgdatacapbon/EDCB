#include "StdAfx.h"
#include "NetworkIdentification.h"

CNetworkIdentification::CNetworkIdentification(void)
{
	private_dataLength = 0;
	private_data = NULL;
}

CNetworkIdentification::~CNetworkIdentification(void)
{
	SAFE_DELETE_ARRAY(private_data);
}

BOOL CNetworkIdentification::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}
	SAFE_DELETE_ARRAY(private_data);
	private_dataLength = 0;

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

	if( descriptor_tag != 0xC2 ){
		//�^�O�l����������
		_OutputDebugString( L"++++CNetworkIdentification:: descriptor_tag err 0xC2 != 0x%02X", descriptor_tag );
		return FALSE;
	}

	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CNetworkIdentification:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		memcpy(country_code, data+readSize, 3 );
		country_code[3] = '\0';
		readSize+=3;

		media_type = ((WORD)data[readSize])<<8 | data[readSize+1];
		network_id = ((WORD)data[readSize+2])<<8 | data[readSize+3];
		readSize+=4;

		if( readSize-2 < descriptor_length ){
			private_dataLength = descriptor_length - (BYTE)(readSize-2);
			private_data = new BYTE[private_dataLength];
			memcpy(private_data, data+readSize, private_dataLength);
			readSize+=private_dataLength;
		}
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}
