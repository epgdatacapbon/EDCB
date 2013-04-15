#pragma once

/*
6.2.16 �X�g���[�����ʋL�q�q�iStream identifier descriptor�j
PMT ���Ŏg�p�����X�g���[�����ʋL�q�q�i�\6�|28 �Q�Ɓj�́A�T�[�r�X�̃R���|�[�l
���g�X�g���[���Ƀ��x����t���A���̃��x���ɂ����EIT ���̃R���|�[�l���g�L�q�q�Ŏ�
�����L�q���e�i�\6�|5�j�i�Ⴆ�΁A����T�[�r�X�̃R���|�[�l���g�X�g���[���́u�f���A
�A�X�y�N�g��16:9 �p���x�N�g������v�ł��邱�Ɓj���Q�Ƃł��邽�߂Ɏg�p����B�X�g��
�[�����ʋL�q�q�́A�֌W����ES ��񒷃t�B�[���h�̒���ɒu���B

stream_identifier_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	component_tag		8 uimsbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
component_tag�i�R���|�[�l���g�^�O�j�F�T�[�r�X�̃R���|�[�l���g�X�g���[���́A����8
�r�b�g�̃t�B�[���h�ɂ��A�R���|�[�l���g�L�q�q�Ŏ������L�q���e�i�\6�|5�j���Q��
�ł���B�v���O�����}�b�v�Z�N�V�����ł́A�e�X�g���[���ɗ^����R���|�[�l���g�^�O��
�l�͈قȂ�l�Ƃ��ׂ��ł���B

*/

#include "../../../Common/Util.h"

class CStreamIdentifierDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE component_tag;

public:
	CStreamIdentifierDesc(void);
	~CStreamIdentifierDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
