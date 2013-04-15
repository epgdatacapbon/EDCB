#pragma once

/*
6.2.39 �f�����L�q�q�iBoard information descriptor�j
�f�����L�q�q�͌f�����̃^�C�g������ѓ��e���e�L�X�g�`���ŕ\���B�\6�|76
�Q�ƁB

board_information_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	title_length			8 uimsbf
	for (i=0;i<title_length;i++){
		title_char				8 uimsbf
	}
	text_length				8 uimsbf
	for (i=0;i<text_length;i++){
		text_char				8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
title_length�i�^�C�g�����j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃^�C�g���̃o�C�g����
�\���B
title_char�i�^�C�g���j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B�[���h
�́A�f�����^�C�g����\���B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB
text_length�i���e�L�q���j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̓��e�L�q�̃o�C�g����
�\���B
text_char�i���e�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B�[���h
�͌f�����̓��e���L�q����B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB

*/

#include "../../../Common/Util.h"

class CBoardInfoDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE title_length;
	CHAR* title_char;
	BYTE text_length;
	CHAR* text_char;
public:
	CBoardInfoDesc(void);
	~CBoardInfoDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
