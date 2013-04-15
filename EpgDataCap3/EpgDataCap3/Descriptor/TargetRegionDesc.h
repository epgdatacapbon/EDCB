#pragma once

/*
6.2.27 �Ώےn��L�q�q�iTarget region descriptor�j
�Ώےn��L�q�q�i�\6�|46 �Q�Ɓj�́A�ԑg�A�������͔ԑg���\������ꕔ�̃X�g���[��
���ΏۂƂ���n����L�q���邽�߂Ɏg�p�����B

target_region_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	region_spec_type	8 uimsbf
	target_region_spec()
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
region_spec_type�i�n��L�q�����w��j�F����8 �r�b�g�̃t�B�[���h�́A�㑱��
target_region_spec()�\���̂ɂ�����n��L�q�̕������w�肵�A�\6�|47 �ɏ]���ĕ�������
���B
target_region_spec()�i�n��w��q�j�F�n��L�q�����w�育�ƂɋK�肳���n��w��̂���
�̃f�[�^�\���������B�i�t�^G �Q�Ɓj

bs_prefecture_spec(){
	prefecture_bitmap	56 bslbf
}
prefecture_bitmap�i����w��r�b�g�}�b�v�j�F����56 �r�b�g�̃t�B�[���h�͕\G�|2 ��
�����r�b�g�}�b�v�ł���B�l1 ���w�肳�ꂽ�r�b�g�͓��Y�n�悪�Ώۂł��邱�Ƃ������A
�l0 ���w�肳�ꂽ�r�b�g�͓��Y�n�悪�ΏۊO�ł��邱�Ƃ������B

*/

#include "../../../Common/Util.h"

class CTargetRegionDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE region_spec_type;
	BYTE prefecture_bitmap[7];
public:
	CTargetRegionDesc(void);
	~CTargetRegionDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
