#pragma once

/*
6.2.19 �^�C���V�t�g�T�[�r�X�L�q�q�iTime shifted service descriptor�j
���̋L�q�q�́A�T�[�r�X�L�q�q�̑���Ɏg���A���̃T�[�r�X�̃^�C���V�t�g���ꂽ
�R�s�[�̃T�[�r�X��\���B�\6�|31 �Q�ƁB

time_shifted_service_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reference_service_id	16 uimsbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
reference_service_id�i��T�[�r�X���ʁj�F����16 �r�b�g�̃t�B�[���h�́ANVOD ���\
�����Ă���T�[�r�X�̊�T�[�r�X�������B��T�[�r�X�́A��ɂ��̃g�����X�|�[�g�X
�g���[�����ɂ���B�����ł̓T�[�r�X���ʂ̓v���O�����}�b�v�Z�N�V�������̑Ή������
���ԑg�ԍ����ʂ������Ȃ��B
*/

#include "../../../Common/Util.h"

class CTimeShiftedServiceDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD reference_service_id;
public:
	CTimeShiftedServiceDesc(void);
	~CTimeShiftedServiceDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
