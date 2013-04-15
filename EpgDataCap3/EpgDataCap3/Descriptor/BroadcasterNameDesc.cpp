#include "StdAfx.h"
#include "BroadcasterNameDesc.h"

CBroadcasterNameDesc::CBroadcasterNameDesc(void)
{
	char_nameLength = 0;
	char_name = NULL;
}

CBroadcasterNameDesc::~CBroadcasterNameDesc(void)
{
	SAFE_DELETE_ARRAY(char_name);
}

BOOL CBroadcasterNameDesc::Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize )
{
	if( data == NULL ){
		return FALSE;
	}
	SAFE_DELETE_ARRAY(char_name);
	char_nameLength = 0;

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

	if( descriptor_tag != 0xD8 ){
		//�^�O�l����������
		_OutputDebugString( L"++++CBroadcasterNameDesc:: descriptor_tag err 0xD8 != 0x%02X", descriptor_tag );
		return FALSE;
	}

	if( readSize+descriptor_length > dataSize ){
		//�T�C�Y�ُ�
		_OutputDebugString( L"++++CBroadcasterNameDesc:: size err %d > %d", readSize+descriptor_length, dataSize );
		return FALSE;
	}
	if( descriptor_length > 0 ){
		char_nameLength = descriptor_length;
		char_name = new CHAR[char_nameLength +1];
		if( char_nameLength > 0 ){
			memcpy(char_name, data+readSize, char_nameLength);
		}
		char_name[char_nameLength] = '\0';

		readSize += char_nameLength;
	}else{
		return FALSE;
	}
	//->��͏���

	if( decodeReadSize != NULL ){
		*decodeReadSize = 2+descriptor_length;
	}

	return TRUE;
}

