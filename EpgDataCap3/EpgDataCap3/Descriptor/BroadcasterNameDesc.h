#pragma once

/*
6.2.36 �u���[�h�L���X�^���L�q�q�iBroadcaster name descriptor�j
�u���[�h�L���X�^���L�q�q�́A�u���[�h�L���X�^�̖��̂��L�q����B�\6�|70 �Q�ƁB

broadcaster_name_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	for(i=0; i<N; i++){
		char				8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
char�i���������j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B�[���h�́A
�u���[�h�L���X�^����\���B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB

*/

#include "../../../Common/Util.h"

class CBroadcasterNameDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE char_nameLength;
	CHAR* char_name;

public:
	CBroadcasterNameDesc(void);
	~CBroadcasterNameDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
