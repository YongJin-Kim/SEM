#pragma once


// cAlign ��ȭ �����Դϴ�.

class cAlign : public CDialog
{
	DECLARE_DYNAMIC(cAlign)

public:
	cAlign(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~cAlign();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOGALIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
