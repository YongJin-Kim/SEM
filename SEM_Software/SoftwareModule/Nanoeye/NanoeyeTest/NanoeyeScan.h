#pragma once
#include "afxwin.h"


// CNanoeyeScan ��ȭ �����Դϴ�.

class CNanoeyeScan : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeScan)
public:
	CNanoeyeScan(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeScan();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGSCAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
	CScrollBar csbMagX;
	CScrollBar csbMagY;
	CScrollBar csbAmpX;
	CScrollBar csbAmpY;
	CScrollBar csbRoation;
	CEdit ceMagX;
	CEdit ceMagY;
	CEdit ceAmpX;
	CEdit ceAmpY;
	CEdit ceRotation;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
