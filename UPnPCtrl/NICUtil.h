#ifndef __MULTI_PLATFORM_NIC_UTIL_H__
#define __MULTI_PLATFORM_NIC_UTIL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include "SortListUtil.h"

typedef struct _MP_NIC_INFO{
	char* name;			//�C���^�[�t�F�[�X��
	char* ipv4;			//IP�A�h���X(v4)
//	char* ipv6;			//IP�A�h���X(v6)
	char* macAddress;	//MAC�A�h���X("-"��؂�̕�����)
	unsigned char macAddressValue[6];//MAC�A�h���X("-"���Ȃ��l)
}MP_NIC_INFO;

MP_NIC_INFO* MP_NIC_INFO_New();
void MP_NIC_INFO_Delete(void* item);
MP_NIC_INFO* MP_NIC_INFO_Clone(MP_NIC_INFO* src);

//NIC�̈ꗗ�����擾����
//�߂�l�F�G���[��NULL�A�������������ʂ̃��X�g�A�L�[�Fchar* ��name�A�v�f�FMP_NIC_INFO*�@�s�K�v�ɂȂ������ʑw�ŊJ�����邱��
SORT_LIST_HANDLE MP_NIC_GetNICInfo(void);

#ifdef __cplusplus
}
#endif

#endif
