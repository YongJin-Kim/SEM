#pragma once


// CNanoeyeAlign ��ȭ �����Դϴ�.

class CNanoeyeAlign : public CDialog
{
	DECLARE_DYNAMIC(CNanoeyeAlign)

public:
	CNanoeyeAlign(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNanoeyeAlign();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGALIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	IController *minisem;
};
