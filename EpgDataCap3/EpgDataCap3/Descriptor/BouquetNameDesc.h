#pragma once

/*
6.2.1 �u�[�P���L�q�q�iBouquet name descriptor�j
�u�[�P���L�q�q�̓e�L�X�g�`���Ńu�[�P���������B

bouquet_name_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for(i=0;i<N;i++){
		char					8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
char�i���������j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕��������t�B�[���h�ł́A
BAT �T�u�e�[�u���Œʒm�����u�[�P�����`�������B�������̕������Ɋւ��ẮA�t
�^A ���Q�ƁB
*/

#include "../../../Common/Util.h"

class CBouquetNameDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE nameLength;
	BYTE* name;

public:
	CBouquetNameDesc(void);
	~CBouquetNameDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

};
