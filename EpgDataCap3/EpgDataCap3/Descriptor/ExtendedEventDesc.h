#pragma once

/*
6.2.7 �g���`���C�x���g�L�q�q�iExtended event descriptor�j
�g���`���C�x���g�L�q�q�́A�Z�`���C�x���g�L�q�q�ɕt�������Ďg�p����A�C�x���g��
�ڍ׋L�q��񋟂���B1 �C�x���g�Ɋւ���256 �o�C�g���ȏ�̏��̓`�����\�Ƃ����
�ɁA�P�ȏ�̊g���`���C�x���g�L�q�q���g�p���邱�Ƃ��ł���B�������͍��ږ��t�B
�[���h�ƍ��ڋL�q�t�B�[���h��2 �̗�����\�������B���̍\���̓T�^�I�ȓK�p�@�͔z
���̃��X�g�̒񋟂ł���B���Ƃ��΁A���ږ��t�B�[���h�ɂ́u�v���f���[�T�[�v�A���ڋL
�q�t�B�[���h�ɂ̓v���f���[�T�[�̖��O���L�ڂ����B

extended_event_descriptor(){
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	descriptor_number			4 uimsbf
	last_descriptor_number		4 uimsbf
	ISO_639_language_code		24 bslbf
	length_of_items				8 uimsbf
	for ( i=0;i<N;i++){
		item_description_length		8 uimsbf
		for (j=0;j<N;j++){
			item_description_char		8 uimsbf
		}
		item_length					8 uimsbf
		for (j=0;j<N;j++){
			item_char					8 uimsbf
		}
	}
	text_length					8 uimsbf
	for (i=0;i<N;i++){
		text_char					8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
descriptor_number�i�L�q�q�ԍ��j�F�L�q�q�̔ԍ���\��4 �r�b�g�̃t�B�[���h�ł���B
�ЂƂ̋L�q�q�ɂ͓��肫��Ȃ������֌W�Â���ׂɎg����B�֌W�Â����Ă���g
���`���C�x���g�L�q�q�Z�b�g�̈�Ԗڂ̋L�q�q�ԍ��́A�u0x0�v�Ƃ���B���̃Z�N�V������
�Ŋg���`���C�x���g�L�q�q������邲�ƂɋL�q�q�ԍ���1 ���Z�����B
last_descriptor_number�i�ŏI�L�q�q�ԍ��j�F����4 �r�b�g�̃t�B�[���h�́A���̋L�q�q
�����̈ꕔ���ƂȂ��Ă���A�֌W�Â���ꂽ�L�q�q�Z�b�g�̍ŏI�g���`���C�x���g�L�q�q
�i�ő�̋L�q�q�ԍ������L�q�q�j�̔ԍ��������B
ISO_639_language_code�i����R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́A�R���|�[�l��
�g�i�����A���邢�̓f�[�^�j�̌���A����т��̋L�q�q�Ɋ܂܂�镶���L�q�̌��������
����B����R�[�h�́AISO 639-2(22)�ɋK�肳���A���t�@�x�b�g3 �����R�[�h�ŕ\���B�e
������ISO 8859-1(24)�ɏ]����8 �r�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}
�������B
��F ���{��̓A���t�@�x�b�g3 �����R�[�h�Łujpn�v�ł���A���̂悤�ɕ����������B
�u0110 1010 0111 0000 0110 1110�v
length_of_items�i���ڒ��j�F�����8 �r�b�g�̃t�B�[���h�ŁA�㑱�̍��ڂ̃o�C�g������
���B
item_description_length�i���ږ����j�F�����8 �r�b�g�̃t�B�[���h�ŁA���ږ��̃o�C�g
���������B
item_description_char�i���ږ��i���������j�j�F�����8 �r�b�g�̃t�B�[���h�ŁA��A��
���ږ��̃t�B�[���h�́A���ږ��̕����L�q���K�肷��B�������̕������Ɋւ��ẮA�t
�^A ���Q�ƁB
item_length�i���ڋL�q���j�F�����8 �r�b�g�̃t�B�[���h�ŁA���ڋL�q�̃o�C�g���������B
item_char�i���ڋL�q�i���������j�j�F�����8 �r�b�g�̃t�B�[���h�ŁA��A�̍��ڋL�q��
�t�B�[���h�́A���ڂ̕����L�q���K�肷��B�������̕������Ɋւ��ẮA�t�^A ���Q�ƁB
text_length�i�g���L�q���j�F�����8 �r�b�g�̃t�B�[���h�ŁA���ږ����̊g���L�q�̃o�C
�g���������B
text_char�i�g���L�q�i���������j�j�F�����8 �r�b�g�̃t�B�[���h�ŁA��A�̊g���L�q��
�t�B�[���h�́A���ږ����̕����L�q���K�肷��B�������̕������Ɋւ��ẮA�t�^A ��
�Q�ƁB
*/

#include "../../../Common/Util.h"

class CExtendedEventDesc
{
public:
	typedef struct _ITEM_DATA{
		BYTE item_description_length;
		CHAR* item_description_char;
		BYTE item_length;
		CHAR* item_char;
		//=�I�y���[�^�[�̏���
		_ITEM_DATA(void){
			item_description_length = 0;
			item_description_char = NULL;
			item_length = 0;
			item_char = NULL;
		}
		~_ITEM_DATA(void){
			SAFE_DELETE_ARRAY(item_description_char);
			SAFE_DELETE_ARRAY(item_char);
		}
	}ITEM_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE descriptor_number;
	BYTE last_descriptor_number;
	CHAR ISO_639_language_code[4];
	BYTE length_of_items;
	vector<ITEM_DATA*> itemList;
	BYTE text_length;
	CHAR* text_char;
public:
	CExtendedEventDesc(void);
	~CExtendedEventDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
