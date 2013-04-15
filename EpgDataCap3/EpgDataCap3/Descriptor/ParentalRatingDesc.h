#pragma once

/*
6.2.12 �p�����^�����[�g�L�q�q�iParental rating descriptor�j
���̋L�q�q�i�\6�|22 �Q�Ɓj�́A�N��Ɋ�Â�������������\���A�܂��A���̐�������
�Ɋ�Â��悤�g�����邱�Ƃ��\�ł���B

parental_rating_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for (i=0;i<N;i++){
		country_code			24 bslbf
		rating					8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
country_code�i���R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́AISO 3166-1(23)�ŋK�肳���
�A���t�@�x�b�g3 �����R�[�h���g�p���č�����\���B�e�����́AISO 8859-1(24)�ɏ]����8
�r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}�������B
��F ���{��3 �����R�[�h�́uJPN�v�ł���A���̂悤�ɕ����������B
�u0100 1010 0101 0000 0100 1110�v
rating�i�N������[�g�j�F����͂W�r�b�g�̃t�B�[���h�ŁA�\6�|23 �ɏ]���Ď����҂�
�����Œ�N���\���B

*/

#include "../../../Common/Util.h"

class CParentalRatingDesc
{
public:
	typedef struct _RATING_DATA{
		CHAR country_code[4];
		BYTE rating;
	} RATING_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<RATING_DATA> ratingList;

public:
	CParentalRatingDesc(void);
	~CParentalRatingDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
