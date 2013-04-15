#pragma once

/*
6.2.48 AVC �^�C�~���OHRD �L�q�q(AVC timing and HRD descriptor)
AVC �^�C�~���OHRD �L�q�q�i�\6-91 �Q�Ɓj�́AITU-T ����H.264|ISO/IEC 14496-10
�̉f���X�g���[���̎��ԏ���HRD�iHypothetical Reference Decoder: ���z�Q�ƃf�R�[
�_�j�̏����L�q���邽�߂ɗp������BAVC �f���X�g���[����VUI�iVideo Usability
Information: �f���L�p���j�p�����[�^��`�����Ȃ��ꍇ�A�{�L�q�q��PMT �ɋL�q����
�K�v������B�ڍׂ�ITU-T ����H.222.0|ISO/IEC 13818-1(21)���Q�Ƃ̂��ƁB

AVC_timing_and_HRD_descriptor () {
	descriptor_tag						8 uimsbf
	descriptor_length					8 uimsbf
	hrd_management_valid_flag			1 bslbf
	reserved							6 bslbf
	picture_and_timing_info_present		1 bslbf
	if(picture_and_timing_info_present = = 1){
		90kHz_flag							1 bslbf
		reserved							7 bslbf
		if(90kHz_flag = = 0){
			N									32 uimsbf
			K									32 uimsbf
		}
		num_units_in_tick					32 uimsbf
	}
	fixed_frame_rate_flag				1 bslbf
	temporal_poc_flag					1 bslbf
	picture_to_display_conversion_flag	1 bslbf
	reserved							5 bslbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
hrd_management_valid_flag�iHRD �Ǘ��L���t���O�j�F���̂P�r�b�g�̃t�B�[���h���u1�v
�̏ꍇ�AITU-T ����H.264|ISO/IEC 14496-10 �t�^C �ɒ�`����Ă���Buffering Period
SEI ��AVC �f���X�g���[���Ɋ܂܂�Ă���K�v������ANAL HRD�iNetwork Abstraction
Layer Hypothetical Reference Decoder�F�l�b�g���[�N���ۑw���z�Q�ƃf�R�[�_�j��CPB
�iCoded Picture Buffer�F�������摜�o�b�t�@�j�ւ̓]���X�P�W���[���ɏ]���āAMBn ��
��EBn �փo�C�g���]������邱�Ƃ������B���̃t�B�[���h���u0�v�̏ꍇ�AITU-T ����
H.222.0|ISO/IEC 13818-1 �� 2.14.3.1 �߂Œ�`����郊�[�N���\�b�h��MBn ����EBn ��
�̓]���ɗp������B
picture_and_timing_info_present�i���ԏ��L���t���O�j�F���̃t�B�[���h���u1�v�̏�
���A90kHz_flag �ƃV�X�e���N���b�N�ւ̐��m�ȃ}�b�s���O�̂��߂̃p�����[�^��{�L�q�q
���܂�ł��邱�Ƃ������B
90kHz_flag�i90kHz �t���O�j�F���̃t�B�[���h���u1�v�̏ꍇ�AAVC �^�C���x�[�X��90kHz
�ł��邱�Ƃ������BAVC �^�C���x�[�X�̎����́AITU-T ����H.264|ISO/IEC 14496-10
�t�^E �Œ�`���ꂽAVC ��time_scale �Œ�`�����B
N, K�FAVC ��time_scale ��system_clock_reference �̊Ԃ̊֌W�������Œ�`����p����
�[�^�ł���AK ��N �ȏ�ł���B
time_scale = (N * system_clock_frequency) / K
num_units_in_tick�i���Ԍv�Z�̒P�ʁj�FITU-T ����H.264|ISO/IEC 14496-10 �̕t�^E
���Q�Ƃ̂��ƁB
fixed_frame_rate_flag�i�Œ�t���[�����[�g�t���O�j�FITU-T ����H.264|ISO/IEC
14496-10 �̕t�^E ���Q�Ƃ̂��ƁB���̃t���O���u1�v�̏ꍇ�A�������t���[�����[�g��AVC
�f���G�������^���[�X�g���[�����ň��ł��邱�Ƃ�\���B���̃t���O���u0�v�̏ꍇ�A
AVC �f���X�g���[���̃t���[�����[�g�Ɋւ����񂪖{�L�q�q�ɂ͂Ȃ����Ƃ�\���B
temporal_poc_flag�i����POC �t���O�j�F���̃t�B�[���h���u1�v��fixed_frame_rate_flag
���u1�v�̏ꍇ�AAVC �f���X�g���[����POC�iPicture Order Count�F�摜���ԁj����
�`�����Ȃ���΂Ȃ�Ȃ��BITU-T ����H.264|ISO/IEC 14496-10 �̕t�^E ���Q�Ƃ̂��ƁB
���̃t�B�[���h���u0�v�̏ꍇ�AAVC �f���X�g���[����POC ���Ǝ��ԂƂ̊֌W�Ɋւ���
���͓`������Ȃ��B
picture_to_display_conversion_flag�i�f���\���ϊ��t���O�j�F���̃t�B�[���h���u1�v�̏�
���AAVC �f���X�g���[�����������f���̕\���̂��߂̏���`�����Ă��邱�Ƃ������B��
�̃t�B�[���h���u0 �v�̏ꍇ�AAVC �f���X�g���[����VUI �p�����[�^��
pic_struct_present_flag �́u0�v�Ƃ��Ȃ���΂Ȃ�Ȃ��B

*/

#include "../../../Common/Util.h"

class CAVCTimingHRDDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE hrd_management_valid_flag;
	BYTE picture_and_timing_info_present;
	BYTE _90kHz_flag;
	DWORD N;
	DWORD K;
	DWORD num_units_in_tick;
	BYTE fixed_frame_rate_flag;
	BYTE temporal_poc_flag;
	BYTE picture_to_display_conversion_flag;

public:
	CAVCTimingHRDDesc(void);
	~CAVCTimingHRDDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
