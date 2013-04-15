
// EpgTimerTaskDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "../../Common/Util.h"
#include "../../Common/StringUtil.h"
#include "../../Common/PathUtil.h"
#include "../../Common/PipeServer.h"
#include "../../Common/SendCtrlCmd.h"
#include "../../Common/CtrlCmdUtil.h"
#include "../../Common/CtrlCmdUtil2.h"
#include "QueryWaitDlg.h"

#define WM_TRAY_PUSHICON (WM_USER+51) //�g���C�A�C�R�������ꂽ
#define WM_QUERY_SUSPEND (WM_USER+52)
#define WM_QUERY_REBOOT (WM_USER+53)

#define TRAYICON_ID 200
#define RETRY_ADD_TRAY 1000
#define RETRY_CHG_TRAY 1001

// CEpgTimerTaskDlg �_�C�A���O
class CEpgTimerTaskDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CEpgTimerTaskDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_EPGTIMERTASK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

protected:
	//�^�X�N�g���C
	BOOL DeleteTaskBar(HWND hWnd, UINT uiID);
	BOOL AddTaskBar(HWND hWnd, UINT uiMsg, UINT uiID, HICON hIcon, CString strTips);
	BOOL ChgTipsTaskBar(HWND hWnd, UINT uiID, HICON hIcon, CString strTips);

// ����
protected:
	HICON m_hIcon;
	HICON m_hIcon2;
	HICON m_hIconRed;
	HICON m_hIconBlue;
	HICON m_hIconGreen;
	HICON m_hIconGray;

	CPipeServer m_cPipe;
	DWORD m_dwSrvStatus;

	//�O������R�}���h�֌W
	static int CALLBACK OutsideCmdCallback(void* pParam, CMD_STREAM* pCmdParam, CMD_STREAM* pResParam);
	//CMD_TIMER_GUI_VIEW_EXECUTE View�A�v���iEpgDataCap_Bon.exe�j���N��
	void CmdViewExecute(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam);
	//CMD_TIMER_GUI_QUERY_SUSPEND �X�^���o�C�A�x�~�A�V���b�g�_�E���ɓ����Ă������̊m�F�����[�U�[�ɍs��
	void CmdViewQuerySuspend(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam);
	//CMD_TIMER_GUI_QUERY_REBOOT PC�ċN���ɓ����Ă������̊m�F�����[�U�[�ɍs��
	void CmdViewQueryReboot(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam);
	//CMD_TIMER_GUI_SRV_STATUS_CHG �T�[�o�[�̃X�e�[�^�X�ύX�ʒm�i1:�ʏ�A2:EPG�f�[�^�擾�J�n�A3:�\��^��J�n�j
	void CmdSrvStatusChg(CMD_STREAM* pCmdParam, CMD_STREAM* pResParam);

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButtonEnd();
	afx_msg void OnBnClickedButtonS4();
	afx_msg void OnBnClickedButtonS3();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
