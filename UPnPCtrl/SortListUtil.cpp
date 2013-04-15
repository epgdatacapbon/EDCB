#include "stdafx.h"

#include "SortListUtil.h"
#ifndef _WIN32
#define __int64 long long //64bit�^
#endif
#define FIRST_LIST_RANGE 100

typedef struct _SORT_LIST_ITEM{
	void* key;
	void* item;
}SORT_LIST_ITEM;

typedef struct _SORT_LIST_HANDLE_ITEM{
	int multiKeyFlag;						//����L�[�Œǉ��ł��邩�̃t���O�i0:�ǉ��ł��Ȃ�,1:�ǉ��ł���j
	SORT_LIST_COMPARE compFunc;				//�L�[��r�p�̔�r�֐�
	SORT_LIST_ITEM_DELETE deleteKeyFunc;	//������̃L�[����֐�
	SORT_LIST_ITEM_DELETE deleteItemFunc;	//������̗v�f����֐�

	void** itemList;					//���X�g�̃|�C���^
	int itemListRange;					//���X�g��MAX�ێ���
	int itemCount;						//�ǉ��A�C�e���̌�
}SORT_LIST_HANDLE_ITEM;

//�w��ʒu�̑O�ɒǉ�����
int SORT_LIST_InsertBefore(
	SORT_LIST_HANDLE_ITEM* handle,		//[IN]handle
	int pos,							//[IN]�}���ʒu
	void* key,							//[IN]�v�f�������̃L�[�ƂȂ镨
	void* item							//[IN]�ǉ�����v�f
)
{
	SORT_LIST_ITEM* addItem = NULL;
	if( handle == NULL ){
		return -1;
	}

	addItem = (SORT_LIST_ITEM*)malloc(sizeof(SORT_LIST_ITEM));
	if( addItem == NULL ){
		return -3;
	}
	addItem->key = key;
	addItem->item = item;

	if( handle->itemCount > pos ){
		//���ɂP���炷
		memmove(&handle->itemList[pos+1], &handle->itemList[pos], sizeof(void*)*(handle->itemCount - pos) );
	}else{
		//�w��l�����������Ō�ɒǉ�
		pos = handle->itemCount;
	}

	handle->itemList[pos] = addItem;
	handle->itemCount++;

	return 0;
}

//�w��ʒu�̌��ɒǉ�����
int SORT_LIST_InsertAfter(
	SORT_LIST_HANDLE_ITEM* handle,		//[IN]handle
	int pos,							//[IN]�}���ʒu
	void* key,							//[IN]�v�f�������̃L�[�ƂȂ镨
	void* item							//[IN]�ǉ�����v�f
)
{
	SORT_LIST_ITEM* addItem = NULL;
	if( handle == NULL ){
		return -1;
	}

	addItem = (SORT_LIST_ITEM*)malloc(sizeof(SORT_LIST_ITEM));
	if( addItem == NULL ){
		return -2;
	}
	addItem->key = key;
	addItem->item = item;

	if( handle->itemCount > pos+1 ){
		//���ɂP���炷
		memmove(&handle->itemList[pos+2], &handle->itemList[pos+1], sizeof(void*)*(handle->itemCount - pos - 1) );
	}else{
		//�w��l�����������Ō�ɒǉ�
		pos = handle->itemCount-1;
	}

	handle->itemList[pos+1] = addItem;
	handle->itemCount++;

	return 0;
}

//�n���h���̍쐬
//�߂�l�F�n���h���A�G���[��NULL
SORT_LIST_HANDLE SORT_LIST_CreateHandle(
	int multiKeyFlag,						//[IN]����L�[�Œǉ��ł��邩�̃t���O�i0:�ǉ��ł��Ȃ�,1:�ǉ��ł���j
	SORT_LIST_COMPARE compFunc,				//[IN]�L�[��r�p�̔�r�֐�
	SORT_LIST_ITEM_DELETE deleteKeyFunc,	//[IN]������̃L�[����֐�
	SORT_LIST_ITEM_DELETE deleteItemFunc	//[IN]������̗v�f����֐�
)
{
	SORT_LIST_HANDLE_ITEM* handle = NULL;
	if( compFunc == NULL ){
		return NULL;
	}

	handle = (SORT_LIST_HANDLE_ITEM*)malloc(sizeof(SORT_LIST_HANDLE_ITEM));
	if( handle != NULL ){
		handle->multiKeyFlag = multiKeyFlag;
		handle->compFunc = compFunc;
		handle->deleteKeyFunc = deleteKeyFunc;
		handle->deleteItemFunc = deleteItemFunc;
		handle->itemCount = 0;
		handle->itemListRange = FIRST_LIST_RANGE;
		handle->itemList = (void**)malloc(sizeof(void*)*handle->itemListRange);
		if( handle->itemList == NULL ){
			free(handle);
			handle = NULL;
		}
	}

	return handle;
}

//�n���h���̉��
//�����handle��NULL��
void SORT_LIST_CloseHandle(
	SORT_LIST_HANDLE* handle			//[IN]SORT_LIST_CreateHandle�̖߂�l
)
{
	int i=0;
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* item = NULL;

	if( handle == NULL ){
		return;
	}
	info = (SORT_LIST_HANDLE_ITEM*)*handle;
	if( info != NULL ){
		for( i=0; i<info->itemCount; i++ ){
			item = (SORT_LIST_ITEM*)info->itemList[i];
			if( info->deleteKeyFunc != NULL ){
				info->deleteKeyFunc(item->key);
			}
			if( info->deleteItemFunc != NULL ){
				info->deleteItemFunc(item->item);
			}
			free(item);
		}
		free(info->itemList);
		free(info);
		*handle = NULL;
	}
}

//�v�f�̒ǉ�
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_AddItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key,							//[IN]�v�f�������̃L�[�ƂȂ镨
	void* item							//[IN]�ǉ�����v�f
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	void** reallocList = NULL;
	int lowPos = 0;
	int midPos = 0;
	int highPos = 0;
	int compRes1 = 0;
	int compRes2 = 0;
	SORT_LIST_ITEM* comp1 = NULL;
	SORT_LIST_ITEM* comp2 = NULL;
	SORT_LIST_ITEM* addItem = NULL;
	int addMode = -1;

	if( handle == NULL ){
		return -1;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	if( info->compFunc == NULL ){
		return -2;
	}

	if( info->itemListRange < info->itemCount+1 ){
		//�T�C�Y�z����̂Ŋg��
		reallocList = (void**)realloc(info->itemList, sizeof(void*)*(info->itemListRange+FIRST_LIST_RANGE));
		if( reallocList == NULL ){
			return -3;
		}
		info->itemList = reallocList;
		info->itemListRange += FIRST_LIST_RANGE;
	}

	if( info->itemCount == 0 ){
		addItem = (SORT_LIST_ITEM*)malloc(sizeof(SORT_LIST_ITEM));
		addItem->key = key;
		addItem->item = item;
		info->itemList[0] = addItem;
		info->itemCount++;
	}else{
		//�}���ʒu�̌���
		lowPos = 0;
		highPos = info->itemCount-1;
		while( lowPos <= highPos ){
			midPos = (lowPos + highPos) / 2;
			comp1 = (SORT_LIST_ITEM*)info->itemList[midPos];
			compRes1 = info->compFunc(key, comp1->key);
			if( compRes1 == 0 ){
				if( info->multiKeyFlag == 0 ){
					//����L�[�Ȃ̂ŃG���[
					return -4;
				}else{
					//�ǉ��ʒu
					//����ɒǉ�
					addMode=1;
					break;
				}
			}else if( compRes1 < 0 ){
				highPos =  midPos-1;
				if( lowPos > highPos ){
					//�ǉ��ʒu
					//�O���ɒǉ�
					addMode=0;
					break;
				}
			}else{
				lowPos =  midPos+1;
				if( lowPos > highPos ){
					//�ǉ��ʒu
					//����ɒǉ�
					addMode=1;
					break;
				}
			}
		}
		if( addMode==0 ){
			SORT_LIST_InsertBefore(info, midPos, key, item);
		}else if( addMode==1 ){
			SORT_LIST_InsertAfter(info, midPos, key, item);
		}else{
			return -5;
		}
	}

	return 0;
}

//�v�f�̍폜
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_DeleteItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key							//[IN]�v�f�������̃L�[�ƂȂ镨
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* delItem = NULL;
	int lowPos = 0;
	int midPos = 0;
	int highPos = 0;
	int compRes = 0;

	if( handle == NULL ){
		return -1;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	if( info->compFunc == NULL ){
		return -2;
	}
	if( info->itemCount <= 0 ){
		return -3;
	}

	//�폜�A�C�e���̌���
	lowPos = 0;
	highPos = info->itemCount-1;
	while( lowPos <= highPos ){
		midPos = (lowPos + highPos) / 2;
		delItem = (SORT_LIST_ITEM*)info->itemList[midPos];
		compRes = info->compFunc(delItem->key, key);
		if( compRes == 0 ){
			//�폜����
			if( info->deleteKeyFunc != NULL ){
				info->deleteKeyFunc(delItem->key);
			}
			if( info->deleteItemFunc != NULL ){
				info->deleteItemFunc(delItem->item);
			}
			free(delItem);
			//�O�ɂP���炷
			if( info->itemCount - midPos - 1 > 0 ){
				memmove(&info->itemList[midPos], &info->itemList[midPos+1], sizeof(void*)*(info->itemCount - midPos - 1) );
			}
			info->itemCount--;
			break;
		}else if(compRes < 0){
			lowPos =  midPos+1;
		}else{
			highPos =  midPos-1;
		}
	}
	return 0;
}


//�w��Index�̗v�f�̍폜
//�߂�l�F0�����ŃG���[�A0�ȏ�Ő���
int SORT_LIST_DeleteItemByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�폜����v�fIndex
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* delItem = NULL;

	if( handle == NULL ){
		return -1;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	if( info->compFunc == NULL ){
		return -2;
	}
	if( info->itemCount <= 0 ){
		return -3;
	}

	//�폜�A�C�e��
	delItem = (SORT_LIST_ITEM*)info->itemList[index];
	//�폜����
	if( info->deleteKeyFunc != NULL ){
		info->deleteKeyFunc(delItem->key);
	}
	if( info->deleteItemFunc != NULL ){
		info->deleteItemFunc(delItem->item);
	}
	free(delItem);
	//�O�ɂP���炷
	if( info->itemCount - index - 1 > 0 ){
		memmove(&info->itemList[index], &info->itemList[index+1], sizeof(void*)*(info->itemCount - index - 1) );
	}
	info->itemCount--;

	return 0;
}

//�v�f�̐����擾����
//�߂�l�F0�����ŃG���[�A0�ȏ�ŗv�f��
int SORT_LIST_GetCount(
	SORT_LIST_HANDLE handle				//[IN]SORT_LIST_CreateHandle�̖߂�l
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;

	if( handle == NULL ){
		return -1;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	return info->itemCount;
}

//�w��Index�̗v�f�̎擾
//�߂�l�F�v�f�A�G���[��NULL
void* SORT_LIST_GetItemByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�擾����v�fIndex
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* item = NULL;

	if( handle == NULL ){
		return NULL;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;
	if( info->itemCount <= index ){
		return NULL;
	}
	item = (SORT_LIST_ITEM*)info->itemList[index];

	return item->item;
}

//�w��Index�̃L�[�̎擾
//�߂�l�F�L�[�A�G���[��NULL
void* SORT_LIST_GetKeyByIndex(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	int index							//[IN]�擾����v�fIndex
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* item = NULL;

	if( handle == NULL ){
		return NULL;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;
	if( info->itemCount <= index ){
		return NULL;
	}
	item = (SORT_LIST_ITEM*)info->itemList[index];

	return item->key;
}

//�w��L�[�̗v�f�̎擾
//�߂�l�F�v�f�A�G���[��NULL
void* SORT_LIST_FindItem(
	SORT_LIST_HANDLE handle,			//[IN]SORT_LIST_CreateHandle�̖߂�l
	void* key							//[IN]�����L�[
)
{
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* item = NULL;
	int lowPos = 0;
	int midPos = 0;
	int highPos = 0;
	int compRes = 0;
	int findFlag = 0;

	if( handle == NULL ){
		return NULL;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	if( info->compFunc == NULL ){
		return NULL;
	}
	if( info->itemCount <= 0 ){
		return NULL;
	}

	//�A�C�e���̌���
	lowPos = 0;
	highPos = info->itemCount-1;
	while( lowPos <= highPos ){
		midPos = (lowPos + highPos) / 2;
		item = (SORT_LIST_ITEM*)info->itemList[midPos];
		compRes = info->compFunc(item->key, key);
		if( compRes == 0 ){
			findFlag = 1;
			break;
		}else if(compRes < 0){
			lowPos =  midPos+1;
		}else{
			highPos =  midPos-1;
		}
		item = NULL;
	}
	if( findFlag == 0 ){
		return NULL;
	}
	return item->item;
}

//�v�f�̃N���A
void SORT_LIST_Clear(
	SORT_LIST_HANDLE handle				//[IN]SORT_LIST_CreateHandle�̖߂�l
)
{
	int i=0;
	SORT_LIST_HANDLE_ITEM* info = NULL;
	SORT_LIST_ITEM* item = NULL;

	if( handle == NULL ){
		return ;
	}
	info = (SORT_LIST_HANDLE_ITEM*)handle;

	if( info->itemCount <= 0 ){
		return ;
	}

	for( i=0; i<info->itemCount; i++ ){
		item = (SORT_LIST_ITEM*)info->itemList[i];
		if( info->deleteKeyFunc != NULL ){
			info->deleteKeyFunc(item->key);
		}
		if( info->deleteItemFunc != NULL ){
			info->deleteItemFunc(item->item);
		}
		free(item);
	}
	info->itemCount = 0;
}


//�ėp��r�p�֐�
//int�p
int SORT_LIST_COMPDEF_int(void* item1, void* item2)
{
	int info1 = (int)item1;
	int info2 = (int)item2;
	if( info1 < info2 ){
		return -1;
	}else
	if( info1 == info2 ){
		return 0;
	}else{
		return 1;
	}
}

//__int64*�i64bit�^�ϐ��j�p
int SORT_LIST_COMPDEF_int64p(void* item1, void* item2)
{
	__int64* info1 = (__int64*)item1;
	__int64* info2 = (__int64*)item2;
	if( *info1 < *info2 ){
		return -1;
	}else
	if( *info1 == *info2 ){
		return 0;
	}else{
		return 1;
	}
}

//char*�pstrcmp
int SORT_LIST_COMPDEF_strcmp(void* item1, void* item2)
{
	char* info1 = (char*)item1;
	char* info2 = (char*)item2;

	return strcmp(info1, info2);
}

//char*�pstricmp
int SORT_LIST_COMPDEF_stricmp(void* item1, void* item2)
{
	char* info1 = (char*)item1;
	char* info2 = (char*)item2;

#ifdef _WIN32
	return _stricmp(info1, info2);
#else
	//Linux�n
	return strcasecmp(info1, info2);
#endif
}

//�ėpdelete�֐�
//free�Ŕ�r
void SORT_LIST_DELDEF_free(void* item1)
{
	free(item1);
}
