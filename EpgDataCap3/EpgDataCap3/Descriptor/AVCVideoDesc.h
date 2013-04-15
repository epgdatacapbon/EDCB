#pragma once

/*
6.2.47 AVC �r�f�I�L�q�q(AVC video descriptor)
AVC �r�f�I�L�q�q�i�\6-90 �Q�Ɓj�́AITU-T ����H.264|ISO/IEC 14496-10 �̉f���X
�g���[���iAVC �X�g���[���j�̊�{�I�ȕ������p�����[�^���L�q���邽�߂ɗp������B
�{�L�q�q��PMT �ɋL�q����Ȃ��ꍇ�AAVC �X�g���[����AVC �Î~�摜��AVC 24 ����
�f�����܂�ł͂Ȃ�Ȃ��B�ڍׂ�ITU-T ����H.222.0|ISO/IEC 13818-1(21)���Q�Ƃ̂��ƁB

AVC_video_descriptor () {
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	profile_idc					8 uimsbf
	constraint_set0_flag		1 bslbf
	constraint_set1_flag		1 bslbf
	constraint_set2_flag		1 bslbf
	AVC_compatible_flags		5 bslbf
	level_idc					8 uimsbf
	AVC_still_present			1 bslbf
	AVC_24_hour_picture_flag	1 bslbf
	reserved					6 bslbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
profile_idc�iAVC �v���t�@�C���j�FAVC �f���X�g���[���̃v���t�@�C���������BITU-T
����H.264|ISO/IEC 14496-10 ��7.4.2.1 �߂��Q�Ƃ̂��ƁB
constraint_set0_flag�i�Z�b�g0 �����t���O�j�FITU-T ����H.264|ISO/IEC 14496-10 ��
7.4.2.1 �߂��Q�Ƃ̂��ƁB
constraint_set1_flag�i�Z�b�g1 �����t���O�j�FITU-T ����H.264|ISO/IEC 14496-10 ��
7.4.2.1 �߂��Q�Ƃ̂��ƁB
constraint_set2_flag�i�Z�b�g2 �����t���O�j�FITU-T ����H.264|ISO/IEC 14496-10 ��
7.4.2.1 �߂��Q�Ƃ̂��ƁB
AVC_compatible_flags�iAVC �݊����t���O�j�FITU-T ����H.264|ISO/IEC 14496-10 ��
�K�肳���V�[�P���X�p�����[�^�Z�b�g��reserved_zero_5bits �Ɠ����l�ł���B
level_idc�iAVC���x���j�FAVC�f���X�g���[���̃��x���������BITU-T ����H.264|ISO/IEC
14496-10 ��7.4.2.1 �߂��Q�Ƃ̂��ƁB
AVC_still_present�iAVC �Î~�摜����j�F���̃t�B�[���h���u1�v�̏ꍇ�AAVC �f���X
�g���[����AVC �Î~�悪�܂܂��B���̃t�B�[���h���u0�v�̏ꍇ�AAVC �f���X�g���[��
��AVC �Î~����܂�ł͂Ȃ�Ȃ��B
AVC_24_hour_picture_flag�iAVC 24 ���ԉf���t���O�j�F���̃t�B�[���h���u1�v�̏ꍇ�A
AVC �f���X�g���[����AVC 24 ���ԉf�����܂܂��BAVC 24 ���ԉf���Ƃ́A24 ���Ԃ��z
����񎦎��Ԃ�L����AVC �A�N�Z�X���j�b�g�ł���B���̃t�B�[���h���u0�v�̏ꍇ�AAVC
�f���X�g���[����AVC 24 ���ԉf�����܂�ł͂Ȃ�Ȃ��B

*/

#include "../../../Common/Util.h"

class CAVCVideoDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE profile_idc;
	BYTE constraint_set0_flag;
	BYTE constraint_set1_flag;
	BYTE constraint_set2_flag;
	BYTE AVC_compatible_flags;
	BYTE level_idc;
	BYTE AVC_still_present;
	BYTE AVC_24_hour_picture_flag;
public:
	CAVCVideoDesc(void);
	~CAVCVideoDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
