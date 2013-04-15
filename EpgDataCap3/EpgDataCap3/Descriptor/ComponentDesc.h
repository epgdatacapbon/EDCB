#pragma once

/*
6.2.3 �R���|�[�l���g�L�q�q�iComponent descriptor�j
�R���|�[�l���g�L�q�q�̓R���|�[�l���g�̎�ʂ������A�G�������^���X�g���[���𕶎�
�`���ŕ\�����邽�߂ɂ����p�����

component_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reserved_future_use		4 bslbf
	stream_content			4 uimsbf
	component_type			8 uimsbf
	component_tag			8 uimsbf
	ISO_639_language_code	24 bslbf
	for (i=0;i<N;i++){
		text_char				8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
stream_content�i�R���|�[�l���g���e�j�F����4 �r�b�g�̃t�B�[���h�́A�X�g���[���̎��
�i�f���A�����A�f�[�^�j��\���A���L�̕\6�|5 �ɏ]���ĕ����������B
component_type�i�R���|�[�l���g��ʁj�F����8 �r�b�g�̃t�B�[���h�́A�f���A�����A�f
�[�^�Ƃ������R���|�[�l���g�̎�ʂ��K�肵�A���L�̕\6�|5 �ɏ]���ĕ����������B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ł���B�R���|�[�l
���g�^�O�́A�R���|�[�l���g�X�g���[�������ʂ��邽�߂̃��x���ł���A�X�g���[�����ʋL
�q�q�i6.2.16 ���Q�Ɓj���̃R���|�[�l���g�^�O�Ɠ���̒l�ł���B�i�������A�X�g���[����
�ʋL�q�q��PMT ���ɑ��݂���ꍇ�B�j
ISO_639_language_code�i����R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́A�R���|�[�l���g
�i�����A���邢�̓f�[�^�j�̌���A����т��̋L�q�q�Ɋ܂܂�镶���L�q�̌�������ʂ���B
����R�[�h�́AISO 639-2(22)�ɋK�肳���A���t�@�x�b�g3 �����R�[�h�ŕ\���B�e������ISO
8859-1(24)�ɏ]����8 �r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}�������B
��F ���{��̓A���t�@�x�b�g3 �����R�[�h�Łujpn�v�ł���A���̂悤�ɕ����������B
�u0110 1010 0111 0000 0110 1110�v
text_char�i�R���|�[�l���g�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̃R���|�[�l
���g�L�q�̃t�B�[���h�́A�R���|�[�l���g�X�g���[���̕����L�q���K�肷��B

*/

#include "../../../Common/Util.h"

class CComponentDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE stream_content;
	BYTE component_type;
	BYTE component_tag;
	CHAR ISO_639_language_code[4];
	BYTE text_charLength;
	BYTE* text_char;

public:
	CComponentDesc(void);
	~CComponentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
