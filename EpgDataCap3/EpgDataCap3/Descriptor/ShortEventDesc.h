#pragma once

/*
6.2.15 �Z�`���C�x���g�L�q�q�iShort event descriptor�j
�Z�`���C�x���g�L�q�q�̓C�x���g������т��̃C�x���g�̒Z���L�q���e�L�X�g�`���ŕ\
���B�\6�|27 �Q�ƁB

short_event_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	ISO_639_language_code	24 bslbf
	event_name_length		8 uimsbf
	for (i=0;i<event_name_length;i++){
		event_name_char			8 uimsbf
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
ISO_639_language_code�i����R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́A�㑱�̕�����
��t�B�[���h�̌����ISO 639-2(22)�ɋK�肳���A���t�@�x�b�g3 �����R�[�h�ŕ\���B�e
������ISO 8859-1(24)�ɏ]����8 �r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}
�������B
��F ���{��̓A���t�@�x�b�g3 �����R�[�h�Łujpn�v�ł���A���̂悤�ɕ����������B
�u0110 1010 0111 0000 0110 1110�v
event_name_length�i�ԑg�����j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̔ԑg���̃o�C�g
����\���B
event_name_char�i�ԑg���j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B
�[���h�́A�ԑg����\���B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB
text_length�i�ԑg�L�q���j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̔ԑg�L�q�̃o�C�g����
�\���B
text_char�i�ԑg�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B�[���h
�͔ԑg�̐������L�q����B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB

*/

#include "../../../Common/Util.h"

class CShortEventDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	CHAR ISO_639_language_code[4];
	BYTE event_name_length;
	CHAR* event_name_char;
	BYTE text_length;
	CHAR* text_char;

public:
	CShortEventDesc(void);
	~CShortEventDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
