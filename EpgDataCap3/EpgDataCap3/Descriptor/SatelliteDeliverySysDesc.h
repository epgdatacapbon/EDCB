#pragma once

/*
6.2.6 �q�����z�V�X�e���L�q�q�iSatellite delivery system descriptor�j
�q�����z�V�X�e���L�q�q�́A�q���`���H�̕����I�����������B�\6�|8 �Q�ƁB

satellite_delivery_system_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	frequency				32 bslbf
	orbital_position		16 bslbf
	west_east_flag			1 bslbf
	polarisation			2 bslbf
	modulation				5 bslbf
	symbol_rate				28 bslbf
	FEC_inner				4 bslbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
frequency�i���g���j�F�����32 �r�b�g�̃t�B�[���h�ŁA4 �r�b�gBCD �R�[�h8 ���Ŏ��g
����\���B�q�����z�V�X�e���L�q�q�ł́A���g����4 ���ڈȍ~�������_�ȉ��ƂȂ�GHz
�P�ʂŕ����������B�i�� 012.73300GHz�j
orbital_position�i�O���j�F�����16 �r�b�g�̃t�B�[���h�ŁA4 �r�b�gBCD �R�[�h4 ���ŁA
�S���ڂ������_�ȉ��ƂȂ�x�P�ʂŋO���ʒu��\���B�i�� 144.0 �x�j
west_east_flag�i���o���o�t���O�j�F�����1 �r�b�g�̃t�B�[���h�ŁA�q���ʒu���O����
���o���邢�͐��o�̂ǂ���ɂȂ邩�������B�u0�v�͐��o�A�u1�v�͓��o�Ɉʒu���邱�Ƃ�
�����B
polarisation�i�Δg�j�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|9 �ɏ]���ē`���M���̕Δg
�������B��1 �r�b�g�͒����Δg���~�Δg�����K�肷��B
modulation�i�ϒ��j�F�����5 �r�b�g�̃t�B�[���h�ŁA�\6�|10 �ɏ]���ĉq�����z�V�X�e
���Ŏg�p�����ϒ������������B
symbol_rate�i�V���{�����[�g�j�F�����28 �r�b�g�t�B�[���h�ŁA4 �r�b�gBCD �R�[�h7
���ŁA4 ���ڈȍ~�������_�ȉ��ƂȂ�Msymbol/s �P�ʂŃV���{�����[�g�l��\���B�i��
021.0960�j
FEC_inner�iFEC�i�������j�j�F�����4 �r�b�g�̃t�B�[���h�ŁA�\6�|11 �ɏ]���ē���
����\���B
*/

#include "../../../Common/Util.h"

class CSatelliteDeliverySysDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	double frequency;
	double orbital_position;
	BYTE west_east_flag;
	BYTE polarisation;
	BYTE modulation;
	double symbol_rate;
	BYTE FEC_inner;

public:
	CSatelliteDeliverySysDesc(void);
	~CSatelliteDeliverySysDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
