#pragma once

/*
6.2.4 �R���e���g�L�q�q�iContent descriptor�j
�R���e���g�L�q�q�i�\6�|6 �Q�Ɓj�̓C�x���g�̃W���������������̂ł���B

content_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for (i=0;i<N;i++) {
		content_nibble_level_1	4 uimsbf
		content_nibble_level_2	4 uimsbf
		user_nibble				4 uimsbf
		user_nibble				4 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
content_nibble_level_1�i�W������1�j�F����4 �r�b�g�̃t�B�[���h�́A�R���e���g���ʂ�
���i�K���ނ�\���B�������ɂ��Ă͕ʓr�K�肷��B�i�t�^H �Q�Ɓj
content_nibble_level_2�i�W������2�j�F����4 �r�b�g�̃t�B�[���h�́A�R���e���g���ʂ�
���i�K���ނ�\���B�������ɂ��Ă͕ʓr�K�肷��B�i�t�^H �Q�Ɓj
user_nibble�i���[�U�W�������j�F����4 �r�b�g�̃t�B�[���h�́A�������Ǝ҂ɂ���`��
���B

*/

#include "../../../Common/Util.h"

class CContentDesc
{
public:
	typedef struct _NIBBLE_DATA{
		BYTE content_nibble_level_1;
		BYTE content_nibble_level_2;
		BYTE user_nibble_1;
		BYTE user_nibble_2;
	}NIBBLE_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<NIBBLE_DATA> nibbleList;

public:
	CContentDesc(void);
	~CContentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
