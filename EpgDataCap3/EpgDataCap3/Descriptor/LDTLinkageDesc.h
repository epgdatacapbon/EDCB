#pragma once

/*
6.2.40 LDT �����N�L�q�q�iLDT linkage descriptor�j
LDT �����N�L�q�q�́ALDT �ɏW�񂳂ꂽ���ɑ΂��郊���N���L�q���邽�߂Ɏg�p����
��B�\6�|77 �Q�ƁB

LDT_linkage_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	original_service_id		16 uimsbf
	transport_stream_id		16 uimsbf
	original_network_id		16 uimsbf
	for (i=0;i<N;i++){
		description_id			16 uimsbf
		reserved_future_use		4 uimsbf
		description_type		4 uimsbf
		user_defined			8 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
original_service_id�i�I���W�i���T�[�r�X���ʁj�F����16 �r�b�g�̃t�B�[���h�́A�����N
����LDT �T�u�e�[�u���̃I���W�i���T�[�r�X���ʂ������B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F����16 �r�b�g�̃t�B�[���h�́A
�����N����LDT �T�u�e�[�u�����܂܂��g�����X�|�[�g�X�g���[�����ʂ������B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F����16 �r�b�g�̃t�B�[���h�́A
�����N����LDT �T�u�e�[�u�����܂܂�錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ������B
description_id�i�L�q���ʁj�F����16 �r�b�g�̃t�B�[���h�́A�����N����L�q�̎��ʔԍ�
�������B
description_type�i�L�q�`����ʁj�F����4 �r�b�g�̃t�B�[���h�́A�\6�|78 �ɏ]���ă�
���N��̋L�q�`���̎�ʂ������B
user_defined�i���ƎҒ�`�r�b�g�j�F����8 �r�b�g�̃t�B�[���h�́A�������Ǝ҂��Ǝ���
��`���邱�Ƃ��ł���B

*/

#include "../../../Common/Util.h"

class CLDTLinkageDesc
{
public:
	typedef struct _LDT_DATA{
		WORD description_id;
		BYTE description_type;
		BYTE user_defined;
	} LDT_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD original_service_id;
	WORD transport_stream_id;
	WORD original_network_id;
	vector<LDT_DATA> LDTList;

public:
	CLDTLinkageDesc(void);
	~CLDTLinkageDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
