#pragma once

/*
6.2.21 �V�X�e���Ǘ��L�q�q�iSystem management descriptor�j
�m���n�{���ڂ́A�����ȍ����� 21 ��88 ��(8)�ɋK�肳��Ă���B
�V�X�e���Ǘ��L�q�q�i�\6�|33 �Q�Ɓj�́A�����Ɣ���������ʂ��邽�߂Ɏg�p�����B

system_management_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	system_management_id	16 uimsbf
	for (i=0;i <N;i++){
		additional_identification_info	8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
system_management_id�i�V�X�e���Ǘ����ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�\6
�|34 �Ɏ����\������Ȃ�B
additional_identification_info�i�t�����ʏ��j�F�����8 �r�b�g�̃t�B�[���h�ŁA�V�X�e
���Ǘ����ʂ̔ԍ��̊g���Ɏg�p�����B

system_management_id(){
	broadcasting_flag						2 uimsbf
	broadcasting_identifier					6 uimsbf
	additional_broadcasting_identification	8 uimsbf
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
additional_broadcasting_identification�i�ڍׂ̎��ʁj�F�����8 �r�b�g�̃t�B�[���h�ŁA
���Ǝ҂̉^�p�K��Œ�߂�B

*/

#include "../../../Common/Util.h"

class CSystemManagementDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD system_management_id;
	BYTE additional_identification_infoLength;
	BYTE* additional_identification_info;
public:
	CSystemManagementDesc(void);
	~CSystemManagementDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
