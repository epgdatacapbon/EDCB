#pragma once

/*
6.2.5 ���ʎ�M�ۋL�q�q�iCountry availability descriptor�j
���̗l�X�ȑg�ݍ��킹�����ʂ��邽�߂ɁA���̋L�q�q�͊e�T�[�r�X��2 ��L�ڂ��鎖��
�ł���B1 ��ڂ̓T�[�r�X����M�\�ȍ����邢�͍��̃O���[�v�̃��X�g�ŁA2 ��ڂ͎�M
�s�\�ȃ��X�g�������B��҂̃��X�g�͑O�҂𖳌��ɂ���B�L�q�q��1 �����g�p���ꂸ�A
����ɂ��ꂪ���̃T�[�r�X����M�\�ȍ����L�ڂ��Ă���ꍇ�́A���̍��ł͂��̃T�[�r
�X����M�ł��Ȃ����Ƃ������B�L�q�q��1 �����g�p���ꂸ�A����ɂ��ꂪ���̃T�[�r�X
����M�s�\�ȍ����L�ڂ��Ă���ꍇ�́A���̍��ł͂��̃T�[�r�X����M�\�Ȃ��Ƃ���
���B���̋L�q�q�����݂��Ȃ��ꍇ�́A�T�[�r�X����M�\�ȍ��͒�`����Ȃ��B�\6�|7 �Q
�ƁB

country_availability_descriptor(){
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	country_availability_flag	1 bslbf
	reserved_future_use			7 bslbf
	for (i=0;I<N;i++){
		country_code				24 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
country_availability_flag�i��M�ۃt���O�j�F����1 �r�b�g�̃t�B�[���h�́A�㑱�̍��R
�[�h���\�������T�[�r�X�̎�M���\���ۂ��������B��M�ۃt���O���u1�v�ɐݒ肳���
����ꍇ�A�㑱�̍��R�[�h�̓T�[�r�X�̎�M���\�ł��鍑�������B�u0�v�ɐݒ肳��Ă�
��ꍇ�A���R�[�h�̓T�[�r�X�̎�M���s�\�ȍ��������B
country_code�i���R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́AISO 3166-1(23)�ŋK�肳���
�A���t�@�x�b�g3 �����R�[�h���g�p���č�����\���B�e�����́AISO 8859-1(24)�ɏ]����8
�r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}�������B
��F ���{��3 �����R�[�h�́uJPN�v�ł���A���̂悤�ɕ����������B
�u0100 1010 0101 0000 0100 1110
*/

#include "../../../Common/Util.h"

class CCountryAvailabilityDesc
{
public:
	typedef struct _COUNTRY_DATA{
		CHAR country_code[4];
	}COUNTRY_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	CHAR country_availability_flag;
	vector<COUNTRY_DATA> countryList;

public:
	CCountryAvailabilityDesc(void);
	~CCountryAvailabilityDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
