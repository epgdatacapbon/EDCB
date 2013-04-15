#pragma once

/*
6.2.25 ���[�J�����ԃI�t�Z�b�g�L�q�q�iLocal time offset descriptor�j
���[�J�����ԃI�t�Z�b�g�L�q�q�i�\6�|41 �Q�Ɓj�́A�T�}�[�^�C�����{���Ɏ��ۂ̎���
�iUTC+9 ���ԁj�Ɛl�Ԍn�ւ̕\�������Ɉ��̃I�t�Z�b�g�l����������Ƃ��ɗp����B

local_time_offset_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for(i=0;i<N;i++){
		country_code				24 bslbf
		country_region_id			6 bslbf
		reserved					1 bslbf
		local_time_offset_polarity	1 bslbf
		local_time_offset			16 bslbf
		time_of_change				40 bslbf
		next_time_offset			16 bslbf
	}
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
country_code�i���R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́AISO 3166-1(23)�ŋK�肳���
�A���t�@�x�b�g3 �����R�[�h���g�p���č�����\���B�e�����́AISO 8859-1(24)�ɏ]����8
�r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}�������B
��F ���{��3 �����R�[�h�́uJPN�v�ł���A���̂悤�ɕ����������B
�u0100 1010 0101 0000 0100 1110�v
country_region_id�i���n�掯�ʁj�F����6 �r�b�g�̃t�B�[���h�́A�����̒n��i�]�[���j
���w�肷�邽�߂̂��̂ł���B�n�����ʂ��Ȃ��ꍇ�́u000000�v���g�p����B
local_time_offset_polarity�i���[�J�����ԃI�t�Z�b�g�ɐ��j�F���̂P�r�b�g�̏��́A��
���ɑ������[�J�����ԃI�t�Z�b�g�l����ѕύX�㎞�ԃI�t�Z�b�g�l�̋ɐ����w�肷��B��
�̃r�b�g�� �h0�h �̂Ƃ��́AJST_time �ɑ΂��ăI�t�Z�b�g���ԕ��i�߂邱�Ƃ��Ӗ����A�h1�h
�̂Ƃ��́AJST_time �ɑ΂��ăI�t�Z�b�g���ԕ��x�点�邱�Ƃ��Ӗ�����B
local_time_offset�i���[�J�����ԃI�t�Z�b�g�j�F����16 �r�b�g�̃t�B�[���h�́AJST_time
�ɑ΂���A���݂̃I�t�Z�b�g���Ԃ� -12 ���Ԃ���+12 ���Ԃ͈̔͂Ŏw�肷��B����16 �r
�b�g�́A�I�t�Z�b�g���Ԃ�10 ���Ԃ̈ʁA1 ���Ԃ̈ʁA10 ���̈ʁA1 ���̈ʂ�4 ���A����
����4 �r�b�g2 �i��10 �i���iBCD�j�ŕ���������B
time_of_change�i�ύX�����j�F����40 �r�b�g�̃t�B�[���h�́A���{�W�����iUTC+9 ���ԁj
�ƏC�������E�X���iMJD�j�i�t�^C �Q�Ɓj�ɂ���ĕ\������A���̈قȂ�I�t�Z�b�g����
�֕ύX�������t�Ǝ������܂ށB���̃t�B�[���h�́AMJD �̉���16 �r�b�g��16 �r�b�g��
���������A����24 �r�b�g��6 ��4 �r�b�g2 �i��10 �i���iBCD�j�ŕ���������B
next_time_offset�i�ύX�㎞�ԃI�t�Z�b�g�j�F����16 �r�b�g�̃t�B�[���h�́Atime_of_change
�Ɏw�肳�ꂽ�����ȍ~�̃I�t�Z�b�g���Ԃ� -12 ���Ԃ���+12 ���Ԃ͈̔͂Ŏw�肷��B����
16 �r�b�g�́A�I�t�Z�b�g���Ԃ�10 ���Ԃ̈ʁA1 ���Ԃ̈ʁA10 ���̈ʁA1 ���̈ʂ�4 ���A
���ꂼ��4 �r�b�g2 �i��10 �i���iBCD�j�ŕ���������B

*/

#include "../../../Common/Util.h"

class CLocalTimeOffsetDesc
{
public:
	typedef struct _LOCAL_TIME_OFFSET_DATA{
		CHAR country_code[4];
		BYTE country_region_id;
		BYTE local_time_offset_polarity;
		WORD local_time_offset; //���P��
		SYSTEMTIME time_of_change;
		WORD next_time_offset;	//���P��
	} LOCAL_TIME_OFFSET_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<LOCAL_TIME_OFFSET_DATA> timeOffsetList;

public:
	CLocalTimeOffsetDesc(void);
	~CLocalTimeOffsetDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
