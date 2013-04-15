#pragma once

/*
6.2.17 �X�^�b�t�L�q�q�iStuffing descriptor�j
�X�^�b�t�L�q�q�́A�O�ɕ��������ꂽ�L�q�q�𖳌��ɂ�����e�[�u���̃X�^�b�t�B���O
�̂��߂̃_�~�[�L�q�q�̑}���ɗ��p�����B�\6�|29 �Q�ƁB

stuffing_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	for (i= 0;i<N;i++){
		stuffing_byte		8 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
stuffing_byte�i�X�^�b�t�B���O�o�C�g�j�F�����8 �r�b�g�̃t�B�[���h�ł���B���̃t�B
�[���h�͖���قȂ�l�ɐݒ�\�ł���B��M�@�ł̓X�^�b�t�B���O�o�C�g�͔p�������B

*/

#include "../../../Common/Util.h"

class CStuffingDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE stuffing_byteLength;
	BYTE* stuffing_byte;
public:
	CStuffingDesc(void);
	~CStuffingDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
