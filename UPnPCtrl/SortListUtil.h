#ifndef __SORT_LIST_UTIL_H__
#define __SORT_LIST_UTIL_H__

/*
�g����

�L�[�ɂ�錟�����\�ȃ��X�g���쐬���đ��삷�����
�i�ǉ����Ƀ\�[�g���Ȃ���ǉ��j

��r�p�֐��̓o�^�͕K�{
�v�f�J���p�͂Ȃ��Ă��i���̏ꍇ�͏�ʑw�ŊJ�����邱�Ɓj
�X���b�h�Z�[�t�ł͂Ȃ��̂ŁA�ǉ��A�폜�ƎQ�Ƃ������ɔ����������ł���Ώ�ʑw�Ŕr����������邱��

SORT_LIST_CreateHandle()
�ō쐬
��
SORT_LIST_AddItem()
�ŗv�f�������ǉ�
�L�[�Ɨv�f���\���̂╶����̏ꍇ�͓��I�Ɋm�ۂ��A��ʑw�ŏ���ɊJ������Ȃ��悤�ɂ��邱��
��
SORT_LIST_FindItem()��SORT_LIST_GetItemByIndex()
�ŗv�f�ւ̃A�N�Z�X������
��
SORT_LIST_CloseHandle()
�K�v�Ȃ��Ȃ�Ή��

*/

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef void* SORT_LIST_HANDLE;

//�v�f��r�p�̊֐�
//�߂�l ���̐�:item1<item2,0:item1==item2,���̐�:item1>item2
typedef int (*SORT_LIST_COMPARE)(
	void* item1,
	void* item2
);

//������̗v�f����֐�
typedef void (*SORT_LIST_ITEM_DELETE)(
	void* item1
);

//�n���h���̍쐬
//�߂�l�F�n���h���A�G���[��NULL
SORT_LIST_HANDLE SORT_LIST_CreateHandle(
	int multiKeyFlag,						//[IN]����L�[�Œǉ��ł��邩�̃t���O�i0:�ǉ��ł��Ȃ�,1:�ǉ��ł���j
	SORT_LIST_COMPARE compFunc,				//[IN]�L�[��r�p�̔�r�֐�
	SORT_LIST_ITEM_DELETE deleteKeyFunc,	//[IN]������̃L�[����֐�
	SORT_LIST_ITEM_DELETE deleteItemFunc	//[IN]������̗v�f����֐�
);

//�n���h���̉��
//�����handle��NULL��
void SORT_LIST_CloseHandle(
	SORT_LIST_HANDLE* handle			//[IN]SORT_LIST_CreateHandle�̖߂�l
);

//�v�f�̒ǉ�
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_AddItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key,							//[IN]�v�f�������̃L�[�ƂȂ镨
	void* item							//[IN]�ǉ�����v�f
);

//�v�f�̍폜
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_DeleteItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key							//[IN]�v�f�������̃L�[�ƂȂ镨
);

//�w��Index�̗v�f�̍폜
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_DeleteItemByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�폜����v�fIndex
);

//�v�f�̐����擾����
//�߂�l�F0�����ŃG���[�A0�ȏ�ŗv�f��
int SORT_LIST_GetCount(
	SORT_LIST_HANDLE handle				//[IN]SORT_LIST_CreateHandle�̖߂�l
);

//�w��Index�̗v�f�̎擾
//�߂�l�F�v�f�A�G���[��NULL
void* SORT_LIST_GetItemByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�擾����v�fIndex
);

//�w��Index�̃L�[�̎擾
//�߂�l�F�L�[�A�G���[��NULL
void* SORT_LIST_GetKeyByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�擾����L�[Index
);

//�w��L�[�̗v�f�̎擾
//�߂�l�F�v�f�A�G���[��NULL
void* SORT_LIST_FindItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key							//[IN]�����L�[
);

//�v�f�̃N���A
void SORT_LIST_Clear(
	SORT_LIST_HANDLE handle				//[IN]SORT_LIST_CreateHandle�̖߂�l
);



//�ėp��r�p�֐�
//int�p
int SORT_LIST_COMPDEF_int(void* item1, void* item2);

//__int64*�i64bit�^�ϐ��j�p
int SORT_LIST_COMPDEF_int64p(void* item1, void* item2);

//char*�pstrcmp�Ŕ�r
int SORT_LIST_COMPDEF_strcmp(void* item1, void* item2);

//char*�pstricmp�Ŕ�r
int SORT_LIST_COMPDEF_stricmp(void* item1, void* item2);

//�ėpdelete�֐�
//free�݂̂ŉ��
void SORT_LIST_DELDEF_free(void* item1);

#ifdef __cplusplus
}
#endif

#endif
