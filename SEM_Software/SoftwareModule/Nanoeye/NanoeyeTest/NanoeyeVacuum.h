#pragma once


// CNanoeyeVacuum ��ȭ �����Դϴ�.

class CNanoeyeVacuum : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeVacuum)

public:
	CNanoeyeVacuum(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeVacuum();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGVACUUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
};
