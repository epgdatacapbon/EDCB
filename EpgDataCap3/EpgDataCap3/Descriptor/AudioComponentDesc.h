#pragma once

/*
6.2.26 �����R���|�[�l���g�L�q�q�iAudio component descriptor�j
�����R���|�[�l���g�L�q�q�́A�����G�������^���[�X�g���[���̊e�p�����[�^�������A
�G�������^���X�g���[���𕶎��`���ŕ\�����邽�߂ɂ����p�����B�i�\6�|42 �Q�Ɓj

audio_component_descriptor (){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reserved_future_use		4 bslbf
	stream_content			4 uimsbf
	component_type			8 uimsbf
	component_tag			8 uimsbf
	stream_type				8 uimsbf
	simulcast_group_tag		8 bslbf
	ES_multi_lingual_flag	1 bslbf
	main_component_flag		1 bslbf
	quality_indicator		2 bslbf
	sampling_rate			3 uimsbf
	reserved_future_use		1 bslbf
	ISO_639_language_code	24 bslbf
	if (ES_multi_lingual_flag == 1){
		ISO_639_language_code_2		24 bslbf
	}
	for(i=0;i<N;i++){
		text_char					8 uimsbf
	}
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
stream_content�i�R���|�[�l���g���e�j�F����4 �r�b�g�̃t�B�[���h�́A�X�g���[���̎�
�ʂ�\���B�����X�g���[���ɑ΂��Ắu0x02�v�Ɛݒ肷��B�i�\6�|5 �Q�Ɓj
component_type�i�R���|�[�l���g��ʁj�F����8 �r�b�g�̃t�B�[���h�́A�����R���|�[�l
���g�̎�ʂ��K�肵�A�\6�|43 �ɏ]���ĕ����������B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ł���B�R���|�[
�l���g�^�O�́A�R���|�[�l���g�X�g���[�������ʂ��邽�߂̃��x���ł���A�X�g���[����
�ʋL�q�q�i6.2.16 ���Q�Ɓj���̃R���|�[�l���g�^�O�Ɠ���̒l�ł���B�i�������A�X�g��
�[�����ʋL�q�q��PMT ���ɑ��݂���ꍇ�B�j
stream_type�i�X�g���[���`����ʁj�F����8 �r�b�g�̃t�B�[���h�́A�����X�g���[����
�`���iMPEG2 BC Audio�AAAC Audio�j��\���B�i�t�^E �Q�Ɓj
simulcast_group_tag�i�T�C�}���L���X�g�O���[�v���ʁj�F����8 �r�b�g�̃t�B�[���h�́A
�T�C�}���L���X�g�i������e���قȂ镄���������œ`���j���s�Ȃ��Ă���R���|�[�l���g
�ɑ΂��ē����ԍ���^����B�T�C�}���L���X�g���s�Ȃ��Ă��Ȃ��R���|�[�l���g�ɑ΂���
�́A�u0xFF�v�ɐݒ肷��B
ES_multi_lingual_flag�iES ������t���O�j�F����1 �r�b�g�̃t���O�́A1/0+1/0 ���[�h��
�����āAES ����2 ����iES �����ꃂ�[�h�j���d���s���Ă���ꍇ�Ɂu1�v�ɐݒ肷��B
����ȊO�̃��[�h�̏ꍇ�ɂ͖���`�Ƃ���B
main_component_flag�i��R���|�[�l���g�t���O�j�F����1 �r�b�g�̃t���O�́A���̉���
�R���|�[�l���g���剹���ł���Ƃ��u1�v�Ƃ���B�܂��A1/0+1/0 ���[�h�̏ꍇ�ɂ́A��1
�����R���|�[�l���g���剹���ł���Ƃ��u1�v�Ƃ���B
quality_indicator�i�����\���j�F����2 �r�b�g�̃t�B�[���h�͉������[�h��\���A�\6-44
�ɏ]���ĕ����������B
sampling_rate�i�T���v�����O���g���j�F����3 �r�b�g�̃t�B�[���h�́A�T���v�����O���g
���������A�\6�|45 �ɏ]���ĕ����������B
ISO_639_language_code�i����R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́A�����R���|�[
�l���g�̌���������BES �����ꃂ�[�h�̂Ƃ��́A��1 �����R���|�[�l���g�̌���������B
����R�[�h�́AISO 639-2(22)�ɋK�肳���A���t�@�x�b�g3 �����R�[�h�ŕ\���B�e������
ISO 8859-1(24)�ɏ]����8 �r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}������
��B
��F ���{��̓A���t�@�x�b�g3 �����R�[�h�Łujpn�v�ł���A���̂悤�ɕ����������B
�u0110 1010 0111 0000 0110 1110�v
ISO_639_language_code_2�i����R�[�h����2�j�F����24 �r�b�g�̃t�B�[���h�́AES ��
���ꃂ�[�h�ɂ����āA��2 �����R���|�[�l���g�̌���������B
text_char�i�R���|�[�l���g�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������
�t�B�[���h�́A�R���|�[�l���g�X�g���[���̕����L�q���K�肷��B�������̕������Ɋ�
���ẮA�t�^A ���Q�ƁB

*/

#include "../../../Common/Util.h"

class CAudioComponentDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE stream_content;
	BYTE component_type;
	BYTE component_tag;
	BYTE stream_type;
	BYTE simulcast_group_tag;
	BYTE ES_multi_lingual_flag;
	BYTE main_component_flag;
	BYTE quality_indicator;
	BYTE sampling_rate;
	CHAR ISO_639_language_code[4];
	CHAR ISO_639_language_code2[4];
	BYTE text_charLength;
	CHAR* text_char;
public:
	CAudioComponentDesc(void);
	~CAudioComponentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
