#pragma once

/*
6.2.23 �f�W�^���R�s�[����L�q�q�iDigital copy control descriptor�j
�f�W�^���R�s�[����L�q�q�i�\6�|38 �Q�Ɓj�́A�f�W�^���L�^�@��ɂ�����R�s�[����
�𐧌䂷����������A�f�W�^���L�^���s���邱�Ƃ��z�肳���ꍇ�ɁA�����ǁi����
���ґ��j���ԑg�̋L�^�A�R�s�[�Ɋւ�������f�W�^���L�^�@��ɓ`���邽�߂ɗp�����
��B�܂��A�X�̔ԑg�̍ő�`�����[�g�����ʂ��邽�߂ɂ����p�����B

digital_copy_control_descriptor(){
	descriptor_tag					8 uimsbf
	descriptor_length				8 uimsbf
	digital_recording_control_data	2 bslbf
	maximum_bitrate_flag			1 bslbf
	component_control_flag			1 bslbf
	user_defined					4 bslbf
	if (maximum_bitrate_flag == 1){
		maximum_bitrate					8 uimsbf
	}
	if (component_control_flag == 1){
		component_control_length		8 uimsbf
		for (i=0;i<N;i++){
			component_tag					8 uimsbf
			digital_recording_control_data	2 bslbf
			maximum_bitrate_flag			1 bslbf
			reserved_future_use				1 bslbf
			user_defined					4 bslbf
			if (maximum_bitrate_flag == 1){
				maximum_bitrate					8 uimsbf
			}
		}
	}
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
digital_recording_control_data�i�f�W�^���R�s�[������j�F����2 �r�b�g�̃t�B�[���h
�́A�R�s�[����𐧌䂷�����\���A�\6�|39 �ɏ]���ĕ����������B
maximum_bit_rate_flag�i�ő�`�����[�g�t���O�j�F����1 �r�b�g�̃t���O���u1�v�̏ꍇ�A
�㑱�̍ő�`�����[�g�̃t�B�[���h���L���ł��邱�Ƃ������B�u0�v�̏ꍇ�A���̃t���O��
����̍ő�`�����[�g�̃t�B�[���h�͑��݂��Ȃ��B
component_control_flag�i�R���|�[�l���g����t���O�j�F���̂P�r�b�g�̃t���O�́A�ԑg
���\������R���|�[�l���g���Ƀf�W�^���R�s�[��������K�肷�邩�ǂ����������B����
�t���O���u1�v�̏ꍇ�A�R���|�[�l���g���䒷�ȍ~�̃t�B�[���h���L���ƂȂ�A�f�W�^���R
�s�[������͔ԑg���\������R���|�[�l���g���ɋK�肳���B�u0�v�̏ꍇ�A�f�W�^���R
�s�[������͔ԑg�S�̂ɂ��ċK�肳��A�R���|�[�l���g���䒷�ȍ~�̃t�B�[���h�͑�
�݂��Ȃ��B���̋L�q�q��PMT �œ`������ꍇ�́A�R���|�[�l���g����t���O�͏�Ɂu0�v
�Ƃ���B
user_defined�i���ƎҒ�`�r�b�g�j�F����4 �r�b�g�̃t�B�[���h�́A�������Ǝ҂��Ǝ�
�ɒ�`���邱�Ƃ��ł���B
maximum_bit_rate�i�ő�`�����[�g�j�F����8 �r�b�g�̃t�B�[���h�́A�e�C�x���g�܂�
�̓G�������^���[�X�g���[���̃g�����X�|�[�g�X�g���[���p�P�b�g�̓`�����[�g��
1/4Mbps ���ɐ؂�グ�ċL�q����B�ϓ`�����[�g�̏ꍇ�́A�ő�l���L�q����B
component_control_length�i�R���|�[�l���g���䒷�j�F����8 �r�b�g�̃t�B�[���h�́A��
���̃R���|�[�l���g���䃋�[�v�̃o�C�g���������B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ł���B�R���|�[
�l���g�^�O�͔ԑg���\������R���|�[�l���g�̃G�������^���[�X�g���[�������ʂ��邽��
�̃��x���ł���A�R���|�[�l���g�L�q�q����уX�g���[�����ʋL�q�q���̃R���|�[�l���g
�^�O�Ɠ���̒l�ł���B

*/

#include "../../../Common/Util.h"

class CDigitalCopyCtrlDesc
{
public:
	typedef struct _COMPONENT_CTRL_DATA{
		BYTE component_tag;
		BYTE digital_recording_control_data;
		BYTE maximum_bitrate_flag;
		BYTE user_defined;
		BYTE maximum_bitrate;
	} COMPONENT_CTRL_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE digital_recording_control_data;
	BYTE maximum_bitrate_flag;
	BYTE component_control_flag;
	BYTE user_defined;
	BYTE maximum_bitrate;
	BYTE component_control_length;
	vector<COMPONENT_CTRL_DATA> component_controlList;

public:
	CDigitalCopyCtrlDesc(void);
	~CDigitalCopyCtrlDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
