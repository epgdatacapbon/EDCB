#pragma once

/*
6.2.10 NVOD ��T�[�r�X�L�q�q�iNear Video On Demand reference descriptor�j
�{�L�q�q�́A�^�C���V�t�g�T�[�r�X�L�q�q����у^�C���V�t�g�C�x���g�L�q�q�Ƌ��ɁA
�����J�n���ԈȊO�̓V�[�P���X�������ł���C�x���g��`�����Ă��镡���̃T�[�r�X����
���ǂ��L�q�����i��񋟂���B�����̃^�C���V�t�g�T�[�r�X�́A�����T�[�r�X����Y
���T�[�r�X��I�����邱�Ƃɂ��A���[�U�[���C�ӂ̎����ɔԑg�J�n���Ԃɋ߂��T�[�r�X
��I���ł��邱�Ƃ���A�j�A�r�f�I�I���f�}���h�iNVOD�j�ƌĂ΂��B
NVOD ��T�[�r�X�L�q�q�i�\6�|20 �Q�Ɓj�́ANVOD �T�[�r�X���\������T�[�r�X
�̈ꗗ�������B�e�X�̃T�[�r�X�́A�Y������SDT �T�u�e�[�u���̃^�C���V�t�g�T�[�r�X�L
�q�q�ɂ��L�q����Ă���B�i6.2.19 ���Q�Ɓj�^�C���V�t�g�T�[�r�X�L�q�q�́A��T�[�r
�X���ʂɂ��^�C���V�t�g�T�[�r�X���֘A�Â��Ă���B��T�[�r�X���ʂ́A�SNVOD �T
�[�r�X���L�q���郉�x���ł��邪�A���ꎩ�g��PMT ���̂�����̃v���O�����ԍ��ɂ���
�����Ȃ��B
�^�C���V�t�g�C�x���g�L�q�q�́A�e�X�̃^�C���V�t�g�T�[�r�X�̃C�x���g���ɗp����
���B�e�C�x���g�ɑS�����d�����ċL�q���Ȃ��Ă悢����ɁA�^�C���V�t�g�C�x���g
�L�q�q�͊�T�[�r�X�̊�C�x���g���ʂ��w�������B�S�C�x���g���́A��T�[�r�X
�̃C�x���g���Ɏ������B
NVOD�T�[�r�X���\������T�[�r�X�͓���g�����X�|�[�g�X�g���[�����ɑ��݂���K�v
�͂Ȃ����ANVOD �T�[�r�X�̃T�[�r�X��`�����Ă���S�Ẵg�����X�|�[�g�X�g���[����
SI �Ɋ�T�[�r�X�̋L�q���K�{�ł���B

NVOD_reference_descriptor(){
	descriptor_tag 8 uimsbf
	descriptor_length 8 uimsbf
	for (i=0;i<N;i++) {
		transport_stream_id 16 uimsbf
		original_network_id 16 uimsbf
		service_id 16 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�g�����X�|�[�g�X�g���[�������ʂ���B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F����16 �r�b�g�̃t�B�[���h�́A
���̓`���V�X�e���̃l�b�g���[�N���ʂ��K�肷�郉�x���̖���������B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA���̃g�����X�|�[�g�X�g
���[�����̃T�[�r�X�����ʂ���B�T�[�r�X���ʂ́A�Ή�����v���O�����}�b�v�Z�N�V����
���̕����ԑg�ԍ����ʁiprogram_number�j�ɓ������B
*/

#include "../../../Common/Util.h"

class CNVODReferenceDesc
{
public:
	typedef struct _SERVICE_DATA{
		WORD original_network_id;
		WORD transport_stream_id;
		WORD service_id;
	} SERVICE_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<SERVICE_DATA> serviceList;

public:
	CNVODReferenceDesc(void);
	~CNVODReferenceDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
