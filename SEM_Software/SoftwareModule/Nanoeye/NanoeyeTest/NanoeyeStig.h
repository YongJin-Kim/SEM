#pragma once


// CNanoeyeStig ��ȭ �����Դϴ�.

class CNanoeyeStig : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeStig)

public:
	CNanoeyeStig(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeStig();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGSTIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
};
