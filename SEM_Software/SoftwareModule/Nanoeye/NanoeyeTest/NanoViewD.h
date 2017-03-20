#pragma once

#include "stdafx.h"
#include "afxwin.h"


// CNanoViewD ��ȭ �����Դϴ�.

class CNanoViewD : public CDialog
{
	DECLARE_DYNAMIC(CNanoViewD)

public:
	CNanoViewD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoViewD();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Display };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IActiveScan *scanner;
	BOOL OnInitDialog();
	ScanEventHandler *sehlu;
	IScanItemEventPtr isie;
	ISettingManager *iSetManager;
	CStatic imgWindow;
	void OnClose();

	afx_msg void OnPaint();
};
