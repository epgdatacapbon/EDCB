#pragma once

/*
6.2.9 ���U�C�N�L�q�q�iMosaic descriptor�j
���U�C�N�R���|�[�l���g�́A�����̈قȂ�f�����W�܂�A1 �̕��������ꂽ�f���R��
�|�[�l���g�ƂȂ������̂ł���B�X�̏�񂪉�ʏ�������������ʒu�ɒ񎦂����l��
��񂪕Ґ�����Ă���B
���U�C�N�L�q�q�ɂ��A�f�W�^���f���R���|�[�l���g�͗v�f�Z�����ɋ敪������A�v�f
�Z���͘_���Z���Ɋ��蓖�Ă��A�_���Z���Ɋ��蓖�Ă�ꂽ�f���Ǝ��ۂ̏��i��F�u�[
�P�A�T�[�r�X�A�C�x���g���j���֘A�Â�����B�\6�|15 �Q�ƁB

mosaic_descriptor(){
	descriptor_tag							8 uimsbf
	descriptor_length						8 uimsbf
	mosaic_entry_point						1 bslbf
	number_of_horizontal_elementary_cells	3 uimsbf
	reserved_future_use						1 bslbf
	number_of_vertical_elementary_cells		3 uimsbf
	for (i=0,i<N; i++) {
		logical_cell_id							6 uimsbf
		reserved_future_use						7 bslbf
		logical_cell_presentation_info			3 uimsbf
		elementary_cell_field_length			8 uimsbf
		for (j=0,j<elementary_cell_field_length;j++) {
			reserved_future_use						2 bslbf
			elementary_cell_id						6 uimsbf
		}
		cell_linkage_info						8 uimsbf
		if (cell_linkage_info ==0x01){
			bouquet_id								16 uimsbf
		}
		if (cell_linkage_info ==0x02){
			original_network_id						16 uimsbf
			transport_stream_id						16 uimsbf
			service_id								16 uimsbf
		}
		if (cell_linkage_info ==0x03){
			original_network_id						16 uimsbf
			transport_stream_id						16 uimsbf
			service_id								16 uimsbf
		}
		if (cell_linkage_info ==0x04){
			original_network_id						16 uimsbf
			transport_stream_id						16 uimsbf
			service_id								16 uimsbf
			event_id								16 uimsbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
mosaic_entry_point�i�ŏ�ʃ��U�C�N�j�F�����1 �r�b�g�̃t�B�[���h�ŁA�u1�v�ɐݒ肳
��Ă���ꍇ�A���̃��U�C�N���ŏ�ʂ̊K�w�̃��U�C�N�ł��邱�Ƃ������B���U�C�N�V�X
�e���̓c���[�\�����\�����邱�Ƃ��\�ł���A���̃t���O�̓c���[�\���̏o���_�ł���
���Ƃ������B
number_of_horizontal_elementary_cells�i�����Z�����j�F����3 �r�b�g�̃t�B�[���h�́A
�\6�|16 �ɏ]���āA��ʏ�̐����Z������\�킷�B
number_of_vertical_elementary_cells�i�����Z�����j�F����3 �r�b�g�̃t�B�[���h�́A��
�ʏ�̐����Z������\�킷�B�����͕\6�|17 ���Q�ƁB
logical_cell_id�i�_���Z�����ʁj�F����6 �r�b�g�̃t�B�[���h��2 �i�`���ŕ����������B
�אڂ���قȂ�v�f�Z���i�}6�|1 �Q�Ɓj�́A�O���[�v������_���Z�����\�����邱�Ƃ�
�\�ł���B�_���Z���ԍ��͂��̂悤�ɃO���[�v�����ꂽ�v�f�Z���ԍ��Ɋ֌W�Â�����B
�_���Z�����̍��v�́A�v�f�Z�����i�ő�64�j�𒴂��邱�Ƃ͂ł��Ȃ��B�e�X�̗v�f�Z����
�P�̘_���Z���Ɋ��蓖�Ă���B1 �̘_���Z����1 �ȏ�̗v�f�Z������\�������B
logical_cell_presentation_info�i�_���Z���񎦏��j�F����3 �r�b�g�̃t�B�[���h�́A�_��
�Z���̒񎦎�ʂ�\�킷�B�_���Z���񎦏��́A�\6�|18 �ɒ�`����񎦌`���������B
elementary_cell_field_length�i�v�f�Z����񒷁j�F�v�f�Z����񒷂�8 �r�b�g�̃t�B�[��
�h�ŁA���̃t�B�[���h�̒��ォ�炱�̘_���Z�����ʂ̃��[�v���̍Ō�̗v�f�Z�����ʂ܂�
�̃o�C�g���������B
elementary_cell_id�i�v�f�Z�����ʁj�F����6 �r�b�g�̃t�B�[���h�̓Z���ԍ���2 �i����
�\���B���̃t�B�[���h��0 ����N �͈̔͂̒l���Ƃ�B
�m��2�n�F�v�f�Z���ԍ���0 ����N �܂Ŕ����Ȃ��t�^�����B0 ��1 �}�X�ځi����j�̃Z
���Ɋ��蓖�Ă���B�ԍ��͍�����E�A�ォ�牺�̏��Ɋ���U���AN �Ԃ͍ŉ��s�̍Ō�
�i�E���j�̃}�X�Ɋ���U����B
cell_linkage_info�i�Z�������N���j�F����8 �r�b�g�̃t�B�[���h�́A�\6�|19 �ɏ]���āA
�_���Z���œ`���������̎�ʂ�\���B
bouquet_id�i�u�[�P���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�Z���ɋL�ڂ���Ă���u�[
�P�����ʂ���B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F����16 �r�b�g�̃t�B�[���h�́A
�㑱�̃t�B�[���h�ƂƂ��ɁA�T�[�r�X�A�C�x���g���邢�̓��U�C�N��Ǝ��Ɏ��ʂ��郉�x
���̖���������B�i5.2 ���Q�Ɓj
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�Z���ɋL�ڂ���Ă���T�[�r�X�A�C�x���g���邢�̓��U�C�N���܂܂��g�����X�|�[
�g�X�g���[�������ʂ���B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA���̃g�����X�|�[�g�X�g
���[�����̃T�[�r�X�����ʂ���B�T�[�r�X���ʂ́A�Ή�����v���O�����}�b�v�Z�N�V����
���̕����ԑg�ԍ����ʁiprogram_number�j�ɓ������B
���̃t�B�[���h�̉��߂́A�Z�������N���̒l�ɂ���Ĉȉ��̂Ƃ���ƂȂ�F
�Z�������N��񁁁u0x02�v�̏ꍇ�A�Z���ɋL�ڂ��ꂽ�T�[�r�X�̃T�[�r�X���ʂł���B
�Z�������N��񁁁u0x03�v�̏ꍇ�A�Z���ɋL�ڂ��ꂽ���U�C�N�T�[�r�X�̃T�[�r�X��
�ʂł���B
�Z�������N��񁁁u0x04�v�̏ꍇ�A�Z���ɋL�ڂ��ꂽ�C�x���g�̃T�[�r�X���ʂł���B
event_id�i�C�x���g���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�L�ڂ��ꂽ�C�x���g�̔ԍ�
�������B

*/

#include "../../../Common/Util.h"

class CMosaicDesc
{
public:
	typedef struct _CELL_DATA{
		BYTE logical_cell_id;
		BYTE logical_cell_presentation_info;
		BYTE elementary_cell_field_length;
		vector<BYTE> elementary_cell_idList;
		BYTE cell_linkage_info;
		//cell_linkage_info == 0x01
		WORD bouquet_id;
		//cell_linkage_info == 0x02,0x03,0x04
		WORD original_network_id;
		WORD transport_stream_id;
		WORD service_id;
		//cell_linkage_info == 0x04
		WORD event_id;
	}CELL_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE mosaic_entry_point;
	BYTE number_of_horizontal_elementary_cells;
	BYTE number_of_vertical_elementary_cells;
	vector<CELL_DATA*> cellList;

public:
	CMosaicDesc(void);
	~CMosaicDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
