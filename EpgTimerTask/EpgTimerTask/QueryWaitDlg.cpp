// QueryWaitDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "EpgTimerTask.h"
#include "QueryWaitDlg.h"
#include "afxdialogex.h"


// CQueryWaitDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CQueryWaitDlg, CDialogEx)

CQueryWaitDlg::CQueryWaitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQueryWaitDlg::IDD, pParent)
	, msgText(_T(""))
{
	m_bReboot = FALSE;
}

CQueryWaitDlg::~CQueryWaitDlg()
{
}

void CQueryWaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_MSG, msgText);
	DDX_Control(pDX, IDC_PROGRESS1, waitProg);
}


BEGIN_MESSAGE_MAP(CQueryWaitDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CQueryWaitDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CQueryWaitDlg ���b�Z�[�W �n���h���[


BOOL CQueryWaitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �����ɏ�������ǉ����Ă�������
	ModifyStyleEx(0, WS_EX_DLGMODALFRAME);

	ShowWindow(SW_SHOW);
	SetForegroundWindow();
	if( m_bReboot == FALSE ){
		waitProg.SetRange(0,15);
		waitProg.SetPos(15);
		dwCount = 15;
		msgText = L"�X�^���o�C�A�x�~�A�܂��̓V���b�g�_�E���ֈڍs���s���܂�";
	}else{
		msgText = L"PC���ċN�����܂�";
		SetWindowText(L"PC�ċN��");
		waitProg.SetRange(0,30);
		waitProg.SetPos(30);
		dwCount = 30;
	}
	SetTimer(TIMER_WAIT_SLEEP, 1000, NULL );
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


void CQueryWaitDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	if( nIDEvent == TIMER_WAIT_SLEEP ){
		if( dwCount == 0 ){
			KillTimer(TIMER_WAIT_SLEEP);
			EndDialog(IDOK);
		}
		dwCount--;
		waitProg.SetPos(dwCount);
		UpdateData(FALSE);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CQueryWaitDlg::OnBnClickedCancel()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CDialogEx::OnCancel();
}
