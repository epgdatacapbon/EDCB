#pragma once

/*
6.2.13 �T�[�r�X�L�q�q�iService descriptor�j
�T�[�r�X�L�q�q�i�\6�|24 �Q�Ɓj�͕Ґ��`�����l�����Ƃ��̎��ƎҖ����T�[�r�X�`����
�ʂƂƂ��ɕ��������ŕ\���B

service_descriptor(){
	descriptor_tag					8 uimsbf
	descriptor_length				8 uimsbf
	service_type					8 uimsbf
	service_provider_name_length	8 uimsbf
	for (i=0;i<N;i++){
		char							8 uimsbf
	}
	service_name_length				8 uimsbf
	for (i=0;i<N;i++){
		char							8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
�T�[�r�X�L�q�q�̈Ӗ��F
service_type�i�T�[�r�X�`����ʁj�F����͂W�r�b�g�̃t�B�[���h�ŁA�\6�|25 �ɏ]����
�T�[�r�X�̎�ނ�\���B
�m���n�F���̃t�B�[���h�́A�����ȍ�����21 ��88 ��(8)�ł́A�T�[�r�X�`�����ʎq�ƕ\��
����Ă���B
service_provider_name_length�i���ƎҖ����j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̎�
�ƎҖ��̃o�C�g����\���B
char�i���������j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B�[���h�́A
���ƎҖ����邢�̓T�[�r�X����\���B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB
service_name_length�i�T�[�r�X�����j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃T�[�r�X
���̃o�C�g����\���B

*/

#include "../../../Common/Util.h"

class CServiceDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE service_type;
	BYTE service_provider_name_length;
	CHAR* char_service_provider_name;
	BYTE service_name_length;
	CHAR* char_service_name;

public:
	CServiceDesc(void);
	~CServiceDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
