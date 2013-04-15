
// EpgTimerTaskDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "EpgTimerTask.h"
#include "EpgTimerTaskDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEpgTimerTaskDlg �_�C�A���O




CEpgTimerTaskDlg::CEpgTimerTaskDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEpgTimerTaskDlg::IDD, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDR_MAINFRAME ), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hIcon2 = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDR_MAINFRAME ), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_hIconRed = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON_RED ), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hIconBlue = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON_BLUE ), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hIconGreen = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON_GREEN ), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_hIconGray = (HICON)LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON_GRAY ), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
}

void CEpgTimerTaskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CEpgTimerTaskDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_BUTTON_END, &CEpgTimerTaskDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_S4, &CEpgTimerTaskDlg::OnBnClickedButtonS4)
	ON_BN_CLICKED(IDC_BUTTON_S3, &CEpgTimerTaskDlg::OnBnClickedButtonS3)
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CEpgTimerTaskDlg ���b�Z�[�W �n���h���[

BOOL CEpgTimerTaskDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	wstring pipeName = L"";
	wstring pipeEventName = L"";
	Format(pipeName, L"\\\\.\\pipe\\EpgTimerGUI_Ctrl_BonPipe_%d", GetCurrentProcessId());
	Format(pipeEventName, L"Global\\EpgTimerGUI_Ctrl_BonConnect_%d", GetCurrentProcessId());

	m_cPipe.StartServer(pipeEventName.c_str(), pipeName.c_str(), OutsideCmdCallback, this);

	//�E�C���h�E�̕���
	WINDOWPLACEMENT Pos;
	Pos.length = sizeof(WINDOWPLACEMENT);
	Pos.flags = NULL;
	Pos.showCmd = SW_HIDE;
	Pos.rcNormalPosition.left = 0;
	Pos.rcNormalPosition.right = 0;
	Pos.rcNormalPosition.top = 0;
	Pos.rcNormalPosition.bottom = 0;
	SetWindowPlacement(&Pos);

	CString strBuff=L"";
	if( AddTaskBar( GetSafeHwnd(),
			WM_TRAY_PUSHICON,
			TRAYICON_ID,
			m_hIconBlue,
			strBuff ) == FALSE ){
				SetTimer(RETRY_ADD_TRAY, 5000, NULL);
	}

	CSendCtrlCmd cmd;
    if( cmd.SendRegistGUI(GetCurrentProcessId()) != CMD_SUCCESS ){
		MessageBox(L"EpgTimerSrv.exe�̋N�����m�F�ł��܂���ł����B\r\n�I�����Ă��������B");
	}

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CEpgTimerTaskDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CEpgTimerTaskDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEpgTimerTaskDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	lpwndpos->flags &= ~SWP_SHOWWINDOW;
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����܂��B
}


BOOL CEpgTimerTaskDlg::AddTaskBar(HWND hWnd, UINT uiMsg, UINT uiID, HICON hIcon, CString strTips)
{ 
	BOOL bRet;
	NOTIFYICONDATA stData;
	ZeroMemory(&stData, sizeof(NOTIFYICONDATA));

	stData.cbSize = sizeof(NOTIFYICONDATA); 
	stData.hWnd = hWnd; 
	stData.uID = uiID; 
	stData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
	stData.uCallbackMessage = uiMsg; 
	stData.hIcon = hIcon; 

	if( strTips.IsEmpty() == false ){
		wcsncpy_s(stData.szTip, sizeof(stData.szTip), strTips.GetBuffer(0), sizeof(stData.szTip) );
	}
 
	bRet = Shell_NotifyIcon(NIM_ADD, &stData);
  
	return bRet; 
}

BOOL CEpgTimerTaskDlg::ChgTipsTaskBar(HWND hWnd, UINT uiID, HICON hIcon, CString strTips)
{ 
	BOOL bRet;
	NOTIFYICONDATA stData;
	ZeroMemory(&stData, sizeof(NOTIFYICONDATA));

	stData.cbSize = sizeof(NOTIFYICONDATA); 
	stData.hWnd = hWnd; 
	stData.uID = uiID; 
	stData.hIcon = hIcon; 
	stData.uFlags = NIF_ICON | NIF_TIP; 

	if( strTips.IsEmpty() == false ){
		wcsncpy_s(stData.szTip, sizeof(stData.szTip), strTips.GetBuffer(0), sizeof(stData.szTip) );
	}
 
	bRet = Shell_NotifyIcon(NIM_MODIFY, &stData); 
 
	return bRet; 
}

BOOL CEpgTimerTaskDlg::DeleteTaskBar(HWND hWnd, UINT uiID)
{ 
	BOOL bRet=TRUE; 
	NOTIFYICONDATA stData; 
	ZeroMemory(&stData, sizeof(NOTIFYICONDATA));
 
	stData.cbSize = sizeof(NOTIFYICONDATA); 
	stData.hWnd = hWnd; 
	stData.uID = uiID; 
         
	bRet = Shell_NotifyIcon(NIM_DELETE, &stData); 
	return bRet; 
}


LRESULT CEpgTimerTaskDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊�{�N���X���Ăяo���Ă��������B
	switch(message){
		case WM_TRAY_PUSHICON:
			{
				//�^�X�N�g���C�֌W
				switch(LOWORD(lParam)){
					case WM_RBUTTONDOWN:
						{
							CMenu menu;
							CPoint point;
							menu.LoadMenu(IDR_MENU_TRAY);
							CMenu* pPopup = menu.GetSubMenu(0);

							GetCursorPos(&point);
							SetForegroundWindow();
							pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
							pPopup->DestroyMenu();
						}
						break;
					default :
						break ;
					}
			}
			break;
		case WM_QUERY_SUSPEND:
			{
				CQueryWaitDlg cDlg;
				if( cDlg.DoModal() != IDCANCEL ){
					CSendCtrlCmd cmd;
					cmd.SendSuspend((WORD)wParam);
				}
			}
			break;
		case WM_QUERY_REBOOT:
			{
				CQueryWaitDlg cDlg;
				cDlg.SetRebootMode();
				if( cDlg.DoModal() != IDCANCEL ){
					CSendCtrlCmd cmd;
					cmd.SendReboot();
				}
			}
			break;
		default:
			break;
	}

	return CDialogEx::WindowProc(message, wParam, lParam);
}


void CEpgTimerTaskDlg::OnBnClickedButtonEnd()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	EndDialog(0);
}

void CEpgTimerTaskDlg::OnBnClickedButtonS3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	CSendCtrlCmd cmd;
	if(cmd.SendChkSuspend() != 1 ){
		MessageBox(L"�X�^���o�C�Ɉڍs�ł����Ԃł͂���܂���B\r\n�i���������\�񂪎n�܂�B�܂��͗}��������exe���N�����Ă���B�Ȃǁj");
	}else{
		cmd.SendSuspend(0xFF01);
	}
}

void CEpgTimerTaskDlg::OnBnClickedButtonS4()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	CSendCtrlCmd cmd;
	if(cmd.SendChkSuspend() != 1 ){
		MessageBox(L"�x�~�Ɉڍs�ł����Ԃł͂���܂���B\r\n�i���������\�񂪎n�܂�B�܂��͗}��������exe���N�����Ă���B�Ȃǁj");
	}else{
		cmd.SendSuspend(0xFF02);
	}
}


void CEpgTimerTaskDlg::OnDestroy()
{
	KillTimer(RETRY_ADD_TRAY);
	KillTimer(RETRY_CHG_TRAY);
	DeleteTaskBar(GetSafeHwnd(), TRAYICON_ID);

	CSendCtrlCmd cmd;
    cmd.SendUnRegistGUI(GetCurrentProcessId());

	CDialogEx::OnDestroy();

	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����܂��B
}


void CEpgTimerTaskDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	if( nIDEvent == RETRY_ADD_TRAY ){
		KillTimer(RETRY_ADD_TRAY);
		CString strBuff=L"";
/*		RESERVE_DATA Item;
		if( GetNextReserve(&Item) == TRUE ){
			wstring strTime;
			GetTimeString3(Item.StartTime, Item.dwDurationSec, strTime);

			strBuff += L"���̗\�� ";
			strBuff += strTime.c_str();
			strBuff += L" ";
			strBuff += Item.strTitle.c_str();
		}else{
			strBuff += L"���̗\�� �Ȃ�";
		}*/
		HICON hSetIcon = m_hIconBlue;
		switch(m_dwSrvStatus){
			case 1:
				hSetIcon = m_hIconRed;
				break;
			case 2:
				hSetIcon = m_hIconGreen;
				break;
			default:
				break;
		}
		if( AddTaskBar( GetSafeHwnd(),
				WM_TRAY_PUSHICON,
				TRAYICON_ID,
				hSetIcon,
				strBuff ) == FALSE ){
					SetTimer(RETRY_ADD_TRAY, 5000, NULL);
		}
	}else if( nIDEvent == RETRY_CHG_TRAY ){
		KillTimer(RETRY_CHG_TRAY);
		CString strBuff=L"";
/*		RESERVE_DATA Item;
		if( GetNextReserve(&Item) == TRUE ){
			wstring strTime;
			GetTimeString3(Item.StartTime, Item.dwDurationSec, strTime);

			strBuff += L"���̗\�� ";
			strBuff += strTime.c_str();
			strBuff += L" ";
			strBuff += Item.strTitle.c_str();
		}else{
			strBuff += L"���̗\�� �Ȃ�";
		}
*/
		HICON hSetIcon = m_hIconBlue;
		switch(m_dwSrvStatus){
			case 1:
				hSetIcon = m_hIconRed;
				break;
			case 2:
				hSetIcon = m_hIconGreen;
				break;
			default:
				break;
		}
		if( ChgTipsTaskBar( GetSafeHwnd(),
				TRAYICON_ID,
				hSetIcon,
				strBuff ) == FALSE ){
					SetTimer(RETRY_CHG_TRAY, 5000, NULL);
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}

int CALLBACK CEpgTimerTaskDlg::OutsideCmdCallback(void* pParam, CMD_STREAM* pCmdParam, CMD_STREAM* pResParam)
{
	CEpgTimerTaskDlg* pSys = (CEpgTimerTaskDlg*)pParam;
	pResParam->param = CMD_NON_SUPPORT;
	switch( pCmdParam->param ){
		case CMD2_TIMER_GUI_VIEW_EXECUTE:
			pSys->CmdViewExecute(pCmdParam, pResParam);
			break;
		case CMD2_TIMER_GUI_QUERY_SUSPEND:
			pSys->CmdViewQuerySuspend(pCmdParam, pResParam);
			break;
		case CMD2_TIMER_GUI_QUERY_REBOOT:
			pSys->CmdViewQueryReboot(pCmdParam, pResParam);
			break;
		case CMD2_TIMER_GUI_SRV_STATUS_NOTIFY2:
			pSys->CmdSrvStatusChg(pCmdParam, pResParam);
			break;
		default:
			pResParam->param = CMD_NON_SUPPORT;
			break;
	}

	return 0;
}

//CMD_TIMER_GUI_VIEW_EXECUTE View�A�v���iEpgDataCap_Bon.exe�j���N��
void CEpgTimerTaskDlg::CmdViewExecute(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam)
{
	OutputDebugString(L"CEpgTimerTaskDlg::CmdViewExecute");
	wstring exeCmd = L"";

	ReadVALUE(&exeCmd, pCmdParam->data, pCmdParam->dataSize, NULL);

	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	ZeroMemory(&si,sizeof(si));
	si.cb=sizeof(si);
	if( exeCmd.find(L".bat") != string::npos ){
		si.wShowWindow |= SW_SHOWMINNOACTIVE;
		si.dwFlags |= STARTF_USESHOWWINDOW;
	}

	BOOL bRet = CreateProcess( NULL, (WCHAR*)exeCmd.c_str(), NULL, NULL, FALSE, GetPriorityClass(GetCurrentProcess()), NULL, NULL, &si, &pi );
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	if( bRet == TRUE ){
		pResParam->dataSize = GetVALUESize(pi.dwProcessId);
		pResParam->data = new BYTE[pResParam->dataSize];
		WriteVALUE(pi.dwProcessId, pResParam->data, pResParam->dataSize, NULL);
		pResParam->param = CMD_SUCCESS;
	}else{
		pResParam->param = CMD_ERR;
	}
}

//CMD_TIMER_GUI_QUERY_SUSPEND �X�^���o�C�A�x�~�A�V���b�g�_�E���ɓ����Ă������̊m�F�����[�U�[�ɍs��
void CEpgTimerTaskDlg::CmdViewQuerySuspend(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam)
{
	OutputDebugString(L"CEpgTimerTaskDlg::CmdViewQuerySuspend");
	WORD val = 0;
	ReadVALUE(&val, pCmdParam->data, pCmdParam->dataSize, NULL);

	PostMessage(WM_QUERY_SUSPEND, val, 0);

	pResParam->param = CMD_SUCCESS;
}

//CMD_TIMER_GUI_QUERY_REBOOT PC�ċN���ɓ����Ă������̊m�F�����[�U�[�ɍs��
void CEpgTimerTaskDlg::CmdViewQueryReboot(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam)
{
	OutputDebugString(L"CEpgTimerTaskDlg::CmdViewQueryReboot");
	WORD val = 0;
	ReadVALUE(&val, pCmdParam->data, pCmdParam->dataSize, NULL);

	PostMessage(WM_QUERY_REBOOT, val, 0);

	pResParam->param = CMD_SUCCESS;
}

//CMD2_TIMER_GUI_SRV_STATUS_NOTIFY2 �T�[�o�[�̃X�e�[�^�X�ύX�ʒm
void CEpgTimerTaskDlg::CmdSrvStatusChg(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam)
{
	OutputDebugString(L"CEpgTimerTaskDlg::CmdSrvStatusChg");
	WORD ver = 0;
	DWORD readSize = 0;
	ReadVALUE2(CMD_VER, &ver, pCmdParam->data, pCmdParam->dataSize, &readSize);
	NOTIFY_SRV_INFO status;
	if( ReadVALUE2(ver, &status, pCmdParam->data+readSize, pCmdParam->dataSize-readSize, NULL) == TRUE ){
		switch(status.notifyID){
		case NOTIFY_UPDATE_SRV_STATUS:
			{
				CString strBuff = L"";
				HICON hSetIcon = m_hIconBlue;
				switch(status.param1){
					case 1:
						hSetIcon = m_hIconRed;
						break;
					case 2:
						hSetIcon = m_hIconGreen;
						break;
					default:
						break;
				}
				m_dwSrvStatus = status.param1;
				if( ChgTipsTaskBar( GetSafeHwnd(),
						TRAYICON_ID,
						hSetIcon,
						strBuff ) == FALSE ){
							SetTimer(RETRY_CHG_TRAY, 5000, NULL);
				}
			}
			break;
		default:
			break;
		}
		pResParam->param = CMD_SUCCESS;
	}else{
		pResParam->param = CMD_ERR;
	}
}
