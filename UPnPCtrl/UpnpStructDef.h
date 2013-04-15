#ifndef __UPNP_STRUCT_DEF_H__
#define __UPNP_STRUCT_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include "SortListUtil.h"

#ifndef _WIN32
#define __int64 long long //64bit�^
#endif

//�����A�J�����͐�pAPI���ł��邾���g������
//M-Search�̃��N�G�X�g���
typedef struct _UPNP_MSEARCH_REQUEST_INFO{
	char* res;			//���N�G�X�g�̐��f�[�^

	char* host;			//HOST:
	char* man;			//MAN:
	char* mx;			//MX:
	char* st;			//ST:
	char* userAgent;	//USER-AGENT:
}UPNP_MSEARCH_REQUEST_INFO;

UPNP_MSEARCH_REQUEST_INFO* UPNP_MSEARCH_REQUEST_INFO_New();
void UPNP_MSEARCH_REQUEST_INFO_Delete(void* item);
UPNP_MSEARCH_REQUEST_INFO* UPNP_MSEARCH_REQUEST_INFO_Clone(UPNP_MSEARCH_REQUEST_INFO* src);

//M-Search�̃��X�|���X���i���ꂽ�Ƃ��j
typedef struct _UPNP_MSEARCH_RES_DEV_INFO{
	char* uuid;

	int max_age;		//CACHE-CONTROL: max-age =
	int port;			//LOCATION�̃|�[�g�ԍ�
	char* uri;			//LOCATION: (DDD���擾����URL)(http://xxx.xxx.xxx.xxx:xxxx�͏Ȃ�������(/****/***.xml) �Œ�ł��u/�v�͓���邱��)
	char* server;		//SERVER:
	char* usn;			//USN:
}UPNP_MSEARCH_RES_DEV_INFO;

UPNP_MSEARCH_RES_DEV_INFO* UPNP_MSEARCH_RES_DEV_INFO_New();
void UPNP_MSEARCH_RES_DEV_INFO_Delete(void* item);
UPNP_MSEARCH_RES_DEV_INFO* UPNP_MSEARCH_RES_DEV_INFO_Clone(UPNP_MSEARCH_RES_DEV_INFO* src);

//M-Search�̃��X�|���X���i�����Ƃ��j
typedef struct _UPNP_MSEARCH_RESPONSE_INFO{
	char* uuid;			//uuid
	char* res;			//���X�|���X�̐��f�[�^

	int max_age;		//CACHE-CONTROL: max-age =
	char* date;			//DATE:
	char* location;		//LOCATION: (DDD���擾����URL)
	char* server;		//SERVER:
	char* st;			//ST:
	char* usn;			//USN:
}UPNP_MSEARCH_RESPONSE_INFO;

UPNP_MSEARCH_RESPONSE_INFO* UPNP_MSEARCH_RESPONSE_INFO_New();
void UPNP_MSEARCH_RESPONSE_INFO_Delete(void* item);
UPNP_MSEARCH_RESPONSE_INFO* UPNP_MSEARCH_RESPONSE_INFO_Clone(UPNP_MSEARCH_RESPONSE_INFO* src);

//SSDP��Notify���
typedef struct _UPNP_SSDP_NOTIFY_INFO{
	char* res;			//Notify�̐��f�[�^

	char* host;			//HOST:
	int max_age;		//CACHE-CONTROL: max-age =
	char* location;		//LOCATION: (DDD���擾����URL)
	char* nt;			//NT:
	char* nts;			//NTS:
	char* server;		//SERVER:
	char* usn;			//USN:
}UPNP_SSDP_NOTIFY_INFO;

UPNP_SSDP_NOTIFY_INFO* UPNP_SSDP_NOTIFY_INFO_New();
void UPNP_SSDP_NOTIFY_INFO_Delete(void* item);
UPNP_SSDP_NOTIFY_INFO* UPNP_SSDP_NOTIFY_INFO_Clone(UPNP_SSDP_NOTIFY_INFO* src);



#ifdef __cplusplus
}
#endif

#endif
