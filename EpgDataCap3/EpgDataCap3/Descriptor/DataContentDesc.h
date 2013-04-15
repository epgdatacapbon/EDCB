#pragma once

/*
6.2.28 �f�[�^�R���e���c�L�q�q�iData content descriptor�j
�f�[�^�R���e���c�L�q�q�i�\ 6�|48 �Q�Ɓj�́A�f�[�^�����ԑg�̌X�̃R���e���c�Ɋ�
����ڍ׏��̋L�q�Ɏg�p�����B

data_content_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	data_component_id		16 uimsbf
	entry_component			8 uimsbf
	selector_length			8 uimsbf
	for(i=0;i<N;i++){
		selector_byte			8 uimsbf
	}
	num_of_component_ref	8 uimsbf
	for(i=0;i<num_of_component_ref;i++){
		component_ref			8 uimsbf
	}
	ISO_639_language_code	24 bslbf
	text_length				8 uimsbf
	for(i=0;i<N;i++){
		text_char				8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
data_component_id�i�f�[�^�������������ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�f�[�^
�����������L�q�q�̃f�[�^�������������ʂƓ����l���L�q����B
entry_component�i�G���g���R���|�[�l���g�j�F����8 �r�b�g�̃t�B�[���h�ł́A�f�[�^
�����̃R���e���c���\�����镡���̃R���|�[�l���g�X�g���[���̂����A�ŏ��ɎQ�Ƃ����
�ׂ��f�[�^���܂ރR���|�[�l���g�X�g���[�����A�R���|�[�l���g�^�O��p���Ďw�肷��B
selector_length�i�Z���N�^���j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃Z���N�^�̈�̃o
�C�g�����K�肷��B
selector_byte�i�Z���N�^�o�C�g�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̃Z���N�^
�̈�́A�f�[�^���擾���邽�߂ɕK�v�ȏ����L�q����B���̗̈�ɋL�q�������̃f
�[�^�\���̓f�[�^�������������ɕʓr�K�肷��B�i�t�^J �Q�Ɓj
num_of_component_ref�i�Q�ƃR���|�[�l���g���j�F����8 �r�b�g�̃t�B�[���h�́A����
�L�q�q�̕\���R���e���c�̋L�^�Đ��ɕK�v�ȁA�C�x���g���̑S�R���|�[�l���g�X�g���[��
�i�������G���g���R���|�[�l���g�Ŏw�肳�ꂽ�R���|�[�l���g�X�g���[���������j�̌�
��\���B���̌��͌㑱�̎Q�ƃR���|�[�l���g�̃��[�v�̃o�C�g���ƈ�v����B
component_ref�i�Q�ƃR���|�[�l���g�j�F����8 �r�b�g�̃t�B�[���h�́A���Y�R���e���c
�̎����������͋L�^�ɕK�v�ȃC�x���g���̃R���|�[�l���g�X�g���[���i�������G���g���R
���|�[�l���g�Ŏw�肳�ꂽ�R���|�[�l���g�X�g���[���������j�̃R���|�[�l���g�^�O���L
�q����B
ISO_639_language_code�i����R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́A�㑱�̃T�[�r
�X�L�q�Ŏg�p����镶���L�q�̌����ISO 639-2(22)�ɋK�肳���A���t�@�x�b�g3 �����R
�[�h�ŕ\���B
text_length�i�R���e���c�L�q���j�F����8 �r�b�g�̃t�B�[���h�͌㑱�̃R���e���c�L�q��
�o�C�g����\���B
text_char�i�R���e���c�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̕������t�B
�[���h�́A�`�������R���e���c�Ɋւ���������L�q����B

*/

#include "../../../Common/Util.h"

class CDataContentDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD data_component_id;
	BYTE entry_component;
	BYTE selector_length;
	BYTE* selector_byte;
	BYTE num_of_component_ref;
	BYTE* component_ref;
	CHAR ISO_639_language_code[4];
	BYTE text_length;
	CHAR* text_char;
public:
	CDataContentDesc(void);
	~CDataContentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
