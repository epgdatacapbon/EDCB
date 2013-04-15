#pragma once

/*
6.2.45 �R���e���g���p�L�q�q (Content availability descriptor)
�R���e���g���p�L�q�q�i�\6-87 �Q�Ɓj�́A�L�^��o�͂𐧌䂷����������A�����ǁi��
�쌠�ґ��j���ԑg�̋L�^��o�͂̐�����s�����ɁA�f�W�^���R�s�[����L�q�q�Ƒg�ݍ���
���ėp������B

content_availability_descriptor () {
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reserved_future_use		1 bslbf
	copy_restriction_mode	1 bslbf
	image_constraint_token	1 bslbf
	retention_mode			1 bslbf
	retention_state			3 bslbf
	encryption_mode			1 bslbf
	for(i=0;i<N;i++){
		reserved_future_use		8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
copy_restriction_mode�i�R�s�[�������[�h�j�F����1 �r�b�g�̃t�B�[���h�́A�R�s�[��
�����̃��[�h�������A���Ǝ҂̉^�p�K��ɂ���Ē�߂���B
image_constraint_token�i�𑜓x�����r�b�g�j�F����1 �r�b�g�̃t�B�[���h�́A�f���M��
�o�͂̉掿�����̗L���������B���̃t�B�[���h���u0�v�̏ꍇ�A�f���M���o�͂̉𑜓x��
�����Ȃ���΂Ȃ�Ȃ��B�u1�v�̏ꍇ�A�������s��Ȃ��Ă悢�B
retention_mode�i�ꎞ�~�ϐ���r�b�g�j�F���̂P�r�b�g�̃t�B�[���h���u�O�v�̏ꍇ�A�f
�W�^���R�s�[����L�q�q��digital_recording_control_data ���u�R�s�[�֎~�v�ł����Ă���
���~�ς��\�ł��邱�Ƃ������B�u�P�v�̏ꍇ�A�ꎞ�~�ς��s�����Ƃ͂ł��Ȃ��B
retention_state�i�ꎞ�~�ϋ��e���ԁj�F���̂R�r�b�g�̃t�B�[���h�́A�R���e���c����M
���Ă���̈ꎞ�~�ϋ��e���Ԃ�\���A�\6-88 �ɂ��������ĕ����������
encryption_mode�i�o�͕ی�r�b�g�j�F���̂P�r�b�g�̃t�B�[���h�́A�����f�W�^���C��
�^�t�F�[�X�o�͂̏o�͕ی�̗L���������B���̃t�B�[���h���u�O�v�̏ꍇ�A�����f�W�^��
�C���^�t�F�[�X�o�͂ɂ����ẮA�ی�̏������s��Ȃ���΂Ȃ�Ȃ��B�u�P�v�̏ꍇ�A��
����s��Ȃ��Ă悢�B

*/

#include "../../../Common/Util.h"

class CContentAvailabilityDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE copy_restriction_mode;
	BYTE image_constraint_token;
	BYTE retention_mode;
	BYTE retention_state;
	BYTE encryption_mode;

public:
	CContentAvailabilityDesc(void);
	~CContentAvailabilityDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
