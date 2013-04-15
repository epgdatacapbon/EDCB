#pragma once

/*
6.2.33 �V���[�Y�L�q�q�iSeries descriptor�j
�V���[�Y�L�q�q�́A�V���[�Y�ԑg�����ʂ��邽�߂ɗp����B�\6�|65 �Q�ƁB

series_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	series_id				16 uimsbf
	repeat_label			4 uimsbf
	program_pattern			3 uimsbf
	expire_date_valid_flag	1 uimsbf
	expire_date				16 uimsbf
	episode_number			12 uimsbf
	last_episode_number		12 uimsbf
	for(i=0; i<N; i++){
		series_name_char		8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
series_id�i�V���[�Y���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�V���[�Y�����j�[�N�Ɏ���
���邽�߂̎��ʎq�ł���B
repeat_label�i�ĕ������x���j�F����4 �r�b�g�̃t�B�[���h�́A�V���[�Y�̕������ԂƃV
���[�Y�̍ĕ����̕������Ԃ��d�Ȃ�ꍇ�ɁA�Ґ�����ʂ��郉�x���Ƃ��ėp����B�I���W
�i���̃V���[�Y�̕����ɂ́u0x0�v��^����B
program_pattern�i�Ґ��p�^�[���j�F����3 �r�b�g�̃t�B�[���h�́A�\6�|66 �ɏ]���A�V
���[�Y�ԑg�̕Ґ��̃p�^�[����\���B����ɂ��V���[�Y�ɑ�����C�x���g�����ɂ���
��邩�̖ڈ����킩��B
expire_date_valid_flag�i�L�������t���O�j�F����1 �r�b�g�̃t���O�́A���ɑ���expire_date
�̒l���L���ł��邱�Ƃ������B�V���[�Y�̏I���\����̒l���L���ȏꍇ�A���̒l���u1�v��
����B
expire_date�i�L�������j�F����16 �r�b�g�̃t�B�[���h�́A�V���[�Y���L���Ȋ����̔N��
����MJD �̉���16 �r�b�g�ŕ\���B���炩�̌����ōŏI��̃C�x���g��F���ł��Ȃ�����
�ꍇ���A���̓��t���߂���Ǝ�M�@�̓V���[�Y���I�������ƔF������B
episode_number�i�b���j�F����12 �r�b�g�̃t�B�[���h�́A���̋L�q�q�������ԑg�́A�V
���[�Y���̘b���������B��1 �񂩂��4095 ��܂ŋL�ڂł���B�b��������𒴂���ꍇ
�̓V���[�Y��ʂɒ�`����B
�A���ԑg�̏ꍇ�Ŕԑg�񐔂���`�ł��Ȃ��ꍇ�́A�u0x000�v�Ƃ���B
last_episode_number�i�ԑg�����j�F����12 �r�b�g�̃t�B�[���h�́A���Y�V���[�Y�ԑg��
�ԑg�����������B��1 �񂩂��4095 ��܂ŋL�ڂł���B�ԑg����������𒴂���ꍇ�́A
�V���[�Y��ʂɒ�`����B
�ŏI�񂪖���̏ꍇ�A�u0x000�v�Ƃ���B
series_name_char�i�V���[�Y���j�F���̕��������t�B�[���h�ł́A�V���[�Y�����`������
��B�������̕������ɂ��ẮA�t�^A �Q�ƁB

*/

#include "../../../Common/Util.h"

class CSeriesDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD series_id;
	BYTE repeat_label;
	BYTE program_pattern;
	BYTE expire_date_valid_flag;
	WORD expire_date;
	WORD episode_number;
	WORD last_episode_number;
	BYTE series_name_charLength;
	CHAR* series_name_char;
public:
	CSeriesDesc(void);
	~CSeriesDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
