#pragma once


// CNanoeyeEgps ��ȭ �����Դϴ�.

class CNanoeyeEgps : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeEgps)

public:
	CNanoeyeEgps(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeEgps();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGEGPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
};
