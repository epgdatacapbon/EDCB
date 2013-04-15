#pragma once

/*
8.2.8.3.3 �p�[�V�����g�����X�|�[�g�X�g���[���^�C���L�q�q
(partialTS_Time_descriptor)
event �̎��ԏ��A�y�ё��o�������̎��ԏ����L�q���邱�Ƃ��ł���BSIT �ɋL�q��
���Btransmission_info_loop �ɋL�q����ꍇ�́Ajst_time �݂̂̋L�q�Ƃ��Aevent �̏�
��͋L�q���Ȃ��BEvent �̏����L�q����ꍇ�́Aservice_loop ��descriptor ��}������B
SIT �̒��ɂ���descriptor �𕡐��}�����鎖�͍D�܂����Ȃ��B�i�\8-2-12 �Q�Ɓj

partialTS_time_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	event_version_number	8 uimsbf
	event_start_time		40 bslbf
	duration				24 uimsbf
	offset					24 bslbf
	reserved				5 bslbf
	offset_flag				1 bslbf
	other_descriptor_status	1 bslbf
	jst_time_flag			1 bslbf
	if(jst_time_flag == 1){
		jst_time				40 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
event_version_number (�ԑg�o�[�W�����ԍ�)�Fevent �̃X�e�[�^�X�̐؂�ڂ����ʂ���
���߂Ɏg�p�B
�؂�ڂŁ{�P�Ƃ���B����T�[�r�X�𑗐M���A�C�x���g���ς�������ɃJ�E���g�A�b�v
����B
event_start_time (�ԑg�J�n����)�Fevent �̊J�n���Ԃ��L�q����B���ԕ\���ɂ��ẮA
EIT �ɋL�q����Ă���start_time �Ɠ����B���̎��ԏ����g�p���Ȃ��ꍇ�́Aall 1 ���L
�q�B
duration (�p������)�Fevent �̌p�����Ԃ��L�q����B���ԕ\���ɂ��ẮAEIT �ɋL�q
����Ă���duration �Ɠ����B���ԏ����L�q���Ȃ��ꍇ�́Aall 1 ���L�q
Offset (�I�t�Z�b�g����)�F�I�t�Z�b�g���ԁBevent_start_time �܂���jst_time �����鎞
�́A���̎��ԂɃA�v���C�����B0x000000 �̎��A�I�t�Z�b�g�̓A�v���C����Ȃ��B����
�̋L�q�́Aduration �Ɠ����B
offset_flag (�I�t�Z�b�g�t���O)�F�I�t�Z�b�g���ԕ��i�߂邩�x�点�邩���`
0�Fevent_start_time �y��jst_time ��offset �̒l�𑫂������Ԃŉ^�p�B
1�Fevent_start_time �y��jst_time ��offset �̒l�����������Ԃŉ^�p�B
other_descriptor_status (���L�q�q�X�e�[�^�X)�FSIT �Ŏg����partialTS_time_
descriptor �ȊO�̏�Ԃ��L�q����B
1�F����descriptor ���ς���Ă���\�����L��B
0�F����descriptor �͕ω����Ă��Ȃ��B
jst_time_flag (jst ���ԃt���O)�F���ꂪ�P�ƂȂ�ƁA�����t�B�[���h��jst_time ������
�鎖�������B
jst_time (jst ����)�F���݂̎������BTDT �ɋL�q�����jst_time ���덷2 �b�ȓ��ŋL
�q����B

*/

#include "../../../Common/Util.h"

class CPartialTSTimeDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE event_version_number;
	SYSTEMTIME event_start_time;
	WORD duration_HH;
	WORD duration_MM;
	WORD duration_SS;
	WORD offset_HH;
	WORD offset_MM;
	WORD offset_SS;
	BYTE offset_flag;
	BYTE other_descriptor_status;
	BYTE jst_time_flag;
	SYSTEMTIME jst_time;
public:
	CPartialTSTimeDesc(void);
	~CPartialTSTimeDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
