#pragma once

/*
6.2.29 �n�C�p�[�����N�L�q�q�iHyperlink descriptor�j
�n�C�p�[�����N�L�q�q�i�\6�|49 �Q�Ɓj�́A���̔ԑg��ԑg�����A�ԑg�֘A���ɑ΂�
�郊���N���L�q���邽�߂Ɏg�p�����B

hyperlink_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	hyper_linkage_type		8 uimsbf
	link_destination_type	8 uimsbf
	selector_length			8 uimsbf
	for(i=0; i<selector_length; i++){
		selector_byte			8 uimsbf
	}
	for(i=0; i<N; i++){
		private_data			8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
hyper_linkage_type�i�n�C�p�[�����N��ʁj�F����8 �r�b�g�̃t�B�[���h�̓����N�̌`��
�������A�\6�|50 �ɏ]���ĕ����������B
link_destination_type�i�����N���ʁj�F���̂W�r�b�g�̃t�B�[���h�̓����N��̎�ʂ�
�\�킵�A�\6�|51 �ɏ]���ĕ����������B
selector_length�i�Z���N�^���j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃Z���N�^�̈�̃o
�C�g����\���B
selector_byte�i�Z���N�^�o�C�g�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A�̃Z���N�^
�̈�́A�����N���ʖ��ɋK�肳���ȉ��̌`���ɂ���ă����N����L�q����B


�\6�|52 �Z���N�^�̈�̋L�q�ilink_destination_type:0x01�j
link_service_info(){
	original_network_id		16 uimsbf
	transport_stream_id		16 uimsbf
	service_id				16 uimsbf
}

original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA
�����N��̃T�[�r�X�������錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ�\�����x�����L�q��
��B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�����N��̃T�[�r�X��������g�����X�|�[�g�X�g���[�������ʂ��郉�x�����L�q����B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃g�����X�|�[
�g�X�g���[�����̃T�[�r�X�����ʂ��邽�߂̃��x���ŁA�Ή�����v���O�����}�b�v�Z�N�V
�������̕����ԑg�ԍ����ʂƓ����l���L�q����B

�\6�|53 �Z���N�^�̈�̋L�q�ilink_destination_type:0x02�j
link_event_info(){
	original_network_id		16 uimsbf
	transport_stream_id		16 uimsbf
	service_id				16 uimsbf
	event_id				16 uimsbf
}
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA
�����N��̃C�x���g�������錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ�\�����x�����L�q��
��B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�����N��̃C�x���g��������g�����X�|�[�g�X�g���[�������ʂ��郉�x�����L�q����B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃C�x���g����
����g�����X�|�[�g�X�g���[�����̃T�[�r�X�����ʂ��邽�߂̃��x���ŁA�Ή�����v���O
�����}�b�v�Z�N�V�������̕����ԑg�ԍ����ʂƓ����l���L�q����B
event_id�i�C�x���g���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃C�x���g�̎���
�ԍ����L�q����B

�\6�|54 �Z���N�^�̈�̋L�q�iLINK_DESTINATION_TYPE:0X03�j
link_module_info(){
	original_network_id		16 uimsbf
	transport_stream_id		16 uimsbf
	service_id				16 uimsbf
	event_id				16 uimsbf
	component_tag			8 uimsbf
	moduleId				16 uimsbf
}
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA
�����N��̃J���[�Z�����W���[���������錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ�\����
�x�����L�q����B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�����N��̃J���[�Z�����W���[����������g�����X�|�[�g�X�g���[�������ʂ��郉�x
�����L�q����B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃J���[�Z����
�W���[����������g�����X�|�[�g�X�g���[�����̃T�[�r�X�����ʂ��邽�߂̃��x���ŁA��
������v���O�����}�b�v�Z�N�V�������̕����ԑg�ԍ����ʂƓ����l���L�q����B
event_id�i�C�x���g���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃J���[�Z�����W
���[����������C�x���g�̎��ʔԍ����L�q����B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ŁA�����N��̃J
���[�Z�����W���[����`������R���|�[�l���g�X�g���[�������ʂ��郉�x�����L�q����B
moduleId�i���W���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃J���[�Z��
���W���[���̎��ʔԍ����L�q����B

�\6�|55 �Z���N�^�̈�̋L�q�ilink_destination_type:0x04�j
link_content_info(){
	original_network_id		16 uimsbf
	transport_stream_id		16 uimsbf
	service_id				16 uimsbf
	content_id				32 uimsbf
}
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA
�����N��̃R���e���c�̃��W���[���������錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ�\��
���x�����L�q����B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�����N��̃R���e���c��������g�����X�|�[�g�X�g���[�������ʂ��郉�x�����L�q��
��B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃R���e���c��
������g�����X�|�[�g�X�g���[�����̃T�[�r�X�����ʂ��邽�߂̃��x���ŁA�Ή�����v��
�O�����}�b�v�Z�N�V�������̕����ԑg�ԍ����ʂƓ����l���L�q����B
content_id�i�R���e���c���ʁj�F�����32 �r�b�g�̃t�B�[���h�ŁA�����N��̃R���e���c
���T�[�r�X���ň�ӂɎ��ʂ��鎯�ʔԍ����L�q����B

�\6�|56 �Z���N�^�̈�̋L�q�ilink_destination_type:0x05�j
link_content_module_info(){
	original_network_id		16 uimsbf
	transport_stream_id		16 uimsbf
	service_id				16 uimsbf
	content_id				32 uimsbf
	component_tag			8 uimsbf
	moduleId				16 uimsbf
}
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA
�����N��̃R���e���c�̃��W���[���������錳�̕��z�V�X�e���̃l�b�g���[�N���ʂ�\��
���x�����L�q����B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�����N��̃R���e���c�̃��W���[����������g�����X�|�[�g�X�g���[�������ʂ��郉
�x�����L�q����B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃R���e���c��
���W���[����������g�����X�|�[�g�X�g���[�����̃T�[�r�X�����ʂ��邽�߂̃��x���ŁA
�Ή�����v���O�����}�b�v�Z�N�V�������̕����ԑg�ԍ����ʂƓ����l���L�q����B
content_id�i�R���e���c���ʁj�F�����32 �r�b�g�̃t�B�[���h�ŁA�����N��̃��W���[��
��������R���e���c���T�[�r�X���ň�ӂɎ��ʂ��鎯�ʔԍ����L�q����B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ŁA�����N��̃J
���[�Z�����W���[����`������R���|�[�l���g�X�g���[�������ʂ��郉�x�����L�q����B
moduleId�i���W���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�����N��̃��W���[��
�̎��ʔԍ����L�q����B

�\6�|57 �Z���N�^�̈�̋L�q�ilink_destination_type:0x06�j
link_ert_node_info(){
	information_provider_id		16 uimsbf
	event_relation_id			16 uimsbf
	node_id						16 uimsbf
}
information_provider_id�i���񋟎Ҏ��ʁj�F����16�r�b�g�̃t�B�[���h�́A�����N���
�m�[�h��������C�x���g�֌W�T�u�e�[�u���̏��񋟎Ҏ��ʂ��w�肷��B
event_relation_id�i�C�x���g�֌W���ʁj�F����16 �r�b�g�̃t�B�[���h�́A�����N��̑���
��C�x���g�֌W�T�u�e�[�u���̃C�x���g�֌W���ʂ��w�肷��B
node_id�i�m�[�h���ʁj�F����16 �r�b�g�̃t�B�[���h�́A�����N��̃m�[�h�̃m�[�h����
���w�肷��B

�\6�|58 �Z���N�^�̈�̋L�q�ilink_destination_type:0x07�j
link_stored_content_info(){
	for(i=0; i<N; i++){
		uri_char 8 uimsbf
	}
}
uri_char�iURI �����j�F��A�̃t�B�[���h�́A�~�ς��ꂽ�f�[�^�T�[�r�X�̃R���e���c��
URI ���L�q����BURI �̋L�q���@�ɂ��Ă�ARIB STD-B24 ����9 �͂̋K��ɂ��B

*/

#include "../../../Common/Util.h"

class CHyperlinkDesc
{
public:
	typedef struct _SELECTOR_DATA{
		WORD original_network_id;
		WORD transport_stream_id;
		WORD service_id;
		WORD event_id;
		BYTE component_tag;
		WORD moduleId;
		DWORD content_id;
		WORD information_provider_id;
		WORD event_relation_id;
		WORD node_id;
		CHAR uri_char[256];
	} SELECTOR_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE hyper_linkage_type;
	BYTE link_destination_type;
	BYTE selector_length;
	vector<SELECTOR_DATA*> selectorList;
	BYTE private_dataLength;
	BYTE* private_data;
public:
	CHyperlinkDesc(void);
	~CHyperlinkDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
