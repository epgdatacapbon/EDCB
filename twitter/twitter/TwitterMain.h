#pragma once

#include "../../Common/ErrDef.h"
#include "../../Common/NWStructDef.h"
#include "../../Common/ProxyUtil.h"
#include "WinHTTPUtil.h"
#include "twitterDef.h"

class CTwitterMain
{
public:
	CTwitterMain(void);
	~CTwitterMain(void);

	//DLL�̏�����
	//�߂�l�F
	// �G���[�R�[�h
	DWORD Initialize(
		);

	//DLL�̊J��
	//�߂�l�F
	// �G���[�R�[�h
	DWORD UnInitialize(
		);

	//IE��Proxy�ݒ���擾����
	//�߂�l�F
	// TRUE�i�֐������j�AFALSE�i�֐����s�j
	//�����F
	// proxyConfig		[OUT]IE��Proxy�ݒ�̏��i����API�ďo���܂Ń������m�ہj
	BOOL GetIEProxyConfig(
		CURRENT_USER_IE_PROXY_CONFIG** proxyConfig
		);

	//�����I�Ɍ��o��Proxy�̃A�h���X���擾����
	//�߂�l�F
	// TRUE�i�֐������j�AFALSE�i�֐����s�j
	//�����F
	// proxyConfig		[OUT]Proxy�̏��i����API�ďo���܂Ń������m�ہj
	BOOL GetProxyAutoDetect(
		PROXY_CONFIG** proxyConfig
		);

	//�����\���X�N���v�g��Proxy�̃A�h���X���擾����
	//�߂�l�F
	// TRUE�i�֐������j�AFALSE�i�֐����s�j
	//�����F
	// scriptURL		[IN]�����\���X�N���v�g��URL
	// proxyConfig		[OUT]Proxy�̏��i����API�ďo���܂Ń������m�ہj
	BOOL GetProxyAutoScript(
		LPCWSTR scriptURL,
		PROXY_CONFIG** proxyConfig
		);

	//Proxy�g�p��ݒ�
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// useProxy			[IN]Proxy�g�����ǂ����iTRUE:Proxy�g���j
	// proxyInfo		[IN]Proxy�g���ꍇ�̐ݒ���
	void SetProxy(
		BOOL useProxy,
		USE_PROXY_INFO* proxyInfo
		);

	//�F�ؗp���O�C��URL���擾����
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// url			[OUT]�F�ؗp���O�C��URL�i����API�ďo���܂Ń������m�ہj
	DWORD GetAuthorizationUrl(
		WCHAR** url
		);

	//�F�،��ʂ̈Ïؔԍ���ݒ肷��
	//������GetAuthorizationUrl�Ŏ擾�����l���g�p����̂ŁA��A�̗���Őݒ肷��K�v����
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// password		[IN]�Ïؔԍ�
	DWORD SetAuthorizationPWD(
		LPCWSTR password
		);

	//�c�C�[�g����
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// asyncMode	[IN]�񓯊��ő��M
	// text			[IN]�c�C�[�g���e
	DWORD SendTweet(
		BOOL asyncMode,
		LPCWSTR text
		);

	//�񓯊��c�C�[�g�̎c����擾����
	//�߂�l�F
	// ��
	DWORD GetTweetQue(
		);
protected:
	BOOL useProxy;
	USE_PROXY_INFO proxyInfo;
	BOOL chgProxy;

	CWinHTTPUtil httpUtil;
	CProxyUtil proxyUtil;
	wstring moduleIniPath;

	WCHAR* authorizationUrl;
	wstring authorization_token;
	wstring authorization_token_secret;

	wstring oauth_token;
	wstring oauth_token_secret;

	HANDLE lockEvent;
	vector<wstring> tweetQue;
	HANDLE tweetThread;
	HANDLE tweetStopEvent;
	HANDLE tweetSetEvent;

	wstring lastResponse;

	DWORD sendWaitSec;

protected:
	BOOL Lock(LPCWSTR log = NULL, DWORD timeOut = 15*1000);
	void UnLock(LPCWSTR log = NULL);
	static UINT WINAPI TweetThread(LPVOID param);

	DWORD SendCmd(BOOL asyncMode, NW_VERB_MODE verbMode, wstring url, wstring httpHead, UPLOAD_DATA_LIST* upList, wstring saveFilePath);
};

