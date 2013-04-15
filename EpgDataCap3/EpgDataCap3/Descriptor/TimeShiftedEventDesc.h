#pragma once

/*
6.2.18 �^�C���V�t�g�C�x���g�L�q�q�iTime shifted event descriptor�j
�^�C���V�t�g�C�x���g�L�q�q�i�\6�|30 �Q�Ɓj�́A�Z�`���C�x���g�L�q�q�̑���Ɏg
�p����A���̃C�x���g�̃^�C���V�t�g���ꂽ�R�s�[�̃C�x���g��\���B

time_shifted_event_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reference_service_id	16 uimsbf
	reference_event_id		16 uimsbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
reference_service_id�i��T�[�r�X���ʁj�F����16 �r�b�g�̃t�B�[���h�́ANVOD ���\
�����Ă���T�[�r�X�̊�T�[�r�X�������B��T�[�r�X�́A��ɂ��̃g�����X�|�[�g�X
�g���[�����ɂ���B�����ł̓T�[�r�X���ʂ̓v���O�����}�b�v�Z�N�V�������̑Ή������
���ԑg�ԍ����ʂ������Ȃ��B
reference_event_id�i��C�x���g���ʁj�F����16 �r�b�g�̃t�B�[���h�́A���̋L�q�q��
����ċL�q�����^�C���V�t�g���ꂽ�R�s�[�̃C�x���g�̊�C�x���g�������B

*/

#include "../../../Common/Util.h"

class CTimeShiftedEventDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD reference_service_id;
	WORD reference_event_id;

public:
	CTimeShiftedEventDesc(void);
	~CTimeShiftedEventDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
