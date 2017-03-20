
// NanoeyeTestDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include "NanoViewD.h"

#include <GdiPlusTypes.h>
#include <gdiplus.h>

// CNanoeyeTestDlg ��ȭ ����
class CNanoeyeTestDlg : public CDialog
{
// �����Դϴ�.
public:
	CNanoeyeTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NANOEYETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

private:
	IController * minisem;


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonscan();
	afx_msg void OnBnClickedButtonlens();
	afx_msg void OnBnClickedButtonalign();
	afx_msg void OnBnClickedButtonstig();
	afx_msg void OnBnClickedButtonegps();
	afx_msg void OnBnClickedButtonvacuum();

	CEdit cNanoViewState;
	CNanoViewD *cnvd;
	ISettingManager *iSetManager;
};
