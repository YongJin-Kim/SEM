#pragma once


// CNanoeyeLens ��ȭ �����Դϴ�.

class CNanoeyeLens : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeLens)

public:
	CNanoeyeLens(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeLens();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGLENS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
};
