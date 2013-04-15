#pragma once

/*
descriptor()�F�\12-2 �Ŏ����_�E�����[�h�R���e���c�L�q�q���i�[����B

Download_content_descriptor () {
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	reboot						1 bslbf
	add_on						1 bslbf
	compatibility_flag			1 bslbf
	module_info_flag			1 bslbf
	text_info_flag				1 bslbf
	reserved					3 bslbf
	component_size				32 uimsbf
	download_id					32 uimsbf
	time_out_value_DII			32 uimsbf
	leak_rate					22 uimsbf
	reserved					2 bslbf
	component_tag				8 uimsbf
	if (compatibility_flag == �e1�f) {
		compatibilityDescriptor()
	}
	if (module_info_flag == �e1�f) {
		num_of_modules				16 uimsbf
		for ( i=0; i<num_of_modules; i++) {
			module_id					16 uimsbf
			module_size					32 uimsbf
			module_info_length			8 uimsbf
			for (i=0; i< module_info_length; i++) {
				module_info_byte;			8 uimsbf
			}
		}
	}
	private_data_length			8 uimsbf
	for ( i=0; i<private_data_length ; i++ ) {
		private_data_byte		8 uimsbf
	}
	if (text_info_flag == �e1�f) {
		ISO_639_language_code		24 uimsbf
		text_length					8 uimsbf
		for(i=0;i<N;i++){
			text_char					8uimsbf
		}
	}
}

descriptor_tag�F�_�E�����[�h�R���e���c�L�q�q���������ʒl�B�l��0xC9�B
reboot�F�_�E�����[�h�I�����Ɏ�M�@���ċN������K�v�����邩�ۂ����w������B
1�Ȃ�΍ċN���A0 �Ȃ�Όp������B
add_on�F�����̃��W���[���̏��������Ȃ̂��A�ǉ��Ȃ̂��������B
1�Ȃ�Βǉ��A0 �Ȃ�Ώ��������B
compatibility_flag�F�L�q�q����CompatibilityDescriptor()�̗L���������t���O�B
1�Ȃ��CompatibilityDescriptor()������������A0 �Ȃ�Ε���������Ȃ��B
module_info_flag�F�L�q�q���̃��W���[�����̏��̗L���������t���O�B
1�Ȃ�΃��W���[�����̏�񂪕���������A0 �Ȃ�Ε���������Ȃ��B
text_info_flag�F�L�q�q�����̃T�[�r�X�L�q�̗L���������t���O�B
1�Ȃ�΃T�[�r�X�L�q������������A0 �Ȃ�Ε���������Ȃ��B
component_size(�R���|�[�l���g�T�C�Y)�F�J���[�Z���œ`���f�[�^�T�C�Y�̍��v�i�P�ʂ̓o�C�g�j
download_id�i�_�E�����[�h���ʁj�F���̃_�E�����[�h�̎󂯕t���ԍ������ʂ���ړI�Őݒ肳�ꂽ�A
�_�E�����[�h���ʂ��w�肷��B�����Ŏw�肳�ꂽ�_�E�����[�h���ʂ͎��ۂ̔z�M����DII/DDB ��
���w�肳���B
time_out_value_DII(DII �^�C���A�E�g�l)�F���Y�J���[�Z����DII �̑S�Z�N�V������M�ɑ΂��鐄
�����ׂ��^�C���A�E�g�l(�P�ʂ̓~���b)�B
leak_rate(���[�N���[�g)�F��M�@�̃g�����X�|�[�g�o�b�t�@�̃��[�N���[�g�B�P�ʂ�50bytes/s�B
reserved�i�\��j�F����3 �r�b�g�̃t�B�[���h�͏����̂��߂̗\��ł���B
component_tag�i�R���|�[�l���g�^�O�j�F����8 �r�b�g�̃t�B�[���h�ɂ�PMT �̃X�g���[�����ʋL
�q�q�ŗ^������A�Ή�����X�g���[���̃R���|�[�l���g�^�O�̒l������B
compatibilityDescriptor()�FDII ����compatibilityDescriptor �Ƃ܂����������̂��̂�����BSDTT
�ɂ�����table_id_ext/group �œ���ł��Ȃ��悤�ȃ_�E�����[�h�Ώۂ̓���͂����ōs���B
number_of_modules�F���W���[���̐��������B
module_id�F�_�E�����[�h�ɂ�����t�@�C���`���ɗp�����郂�W���[�����ʁB
module_size�F���Y���W���[���̃o�C�g����\�킷�B0 �͕s�蒷�B
module_info_length�Fmodule_info_byte �̃o�C�g���B
module_info_byte�FDII �ɂċL�q�����type �L�q�q�AName �L�q�q�AInfo �L�q�q�AControl �L�q�q
�̂����K�v�Ȃ��̂��i�[����B
private_data_length�Fprivate_data_byte �̃o�C�g���B
private_data_byte�F���̗̈�̎g�����͖{�K�i�͈̔͊O�ł���B
ISO_639_language_code�i����R�[�h�j�F�T�[�r�X�L�q�Ŏg�p����镶���L�q�̌�������ʂ���B
text_length�i�T�[�r�X�L�q���j�F�T�[�r�X�L�q�̒����i�P�ʁF�o�C�g�j
text_char�i�T�[�r�X�L�q�j�F�`�������_�E�����[�h�R���e���c�̃T�[�r�X�Ɋւ���L�q

*/

#include "../../../Common/Util.h"

class CDownloadContentDesc
{
public:
	typedef struct _MODULE_INFO_DATA{
		WORD module_id;
		DWORD module_size;
		BYTE module_info_length;
		BYTE* module_info_byte;
		_MODULE_INFO_DATA(void){
			module_info_byte = NULL;
		}
		~_MODULE_INFO_DATA(void){
			SAFE_DELETE_ARRAY(module_info_byte);
		}
	} MODULE_INFO_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE reboot;
	BYTE add_on;
	BYTE compatibility_flag;
	BYTE module_info_flag;
	BYTE text_info_flag;
	DWORD component_size;
	DWORD download_id;
	DWORD time_out_value_DII;
	DWORD leak_rate;
	BYTE component_tag;
//	BYTE* compatibilityDescriptor;
	WORD num_of_modules;
	vector<MODULE_INFO_DATA*> moduleInfoList;
	BYTE private_data_length;
//	BYTE* private_data_byte;
	CHAR ISO_639_language_code[4];
	BYTE text_length;
	BYTE* text_char;

public:
	CDownloadContentDesc(void);
	~CDownloadContentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
