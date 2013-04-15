#pragma once

/*
6.2.14 �T�[�r�X���X�g�L�q�q�iService list descriptor�j
�T�[�r�X���X�g�L�q�q�i�\6�|26 �Q�Ɓj�́A�T�[�r�X���ʂƃT�[�r�X�`����ʂɂ��T
�[�r�X�̈ꗗ��񋟂���B

service_list_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for (i=0;i<N;i++){
		service_id				16 uimsbf
		service_type			8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA���̃g�����X�|�[�g�X�g
���[�����̏��T�[�r�X�����j�[�N�Ɏ��ʂ���B�T�[�r�X���ʂ́A�Ή�����v���O�����}
�b�v�Z�N�V�������̕����ԑg�ԍ����ʁiprogram_number�j�ɓ������B
service_type�i�T�[�r�X�`����ʁj�F����͂W�r�b�g�̃t�B�[���h�ŁA�\6�|25 �ɏ]����
�T�[�r�X�̎�ނ�\���B
*/

#include "../../../Common/Util.h"

class CServiceListDesc
{
public:
	typedef struct _SERVICE_LIST_DATA{
		WORD service_id;
		BYTE service_type;
	} SERVICE_LIST_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<SERVICE_LIST_DATA> serviceList;

public:
	CServiceListDesc(void);
	~CServiceListDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
