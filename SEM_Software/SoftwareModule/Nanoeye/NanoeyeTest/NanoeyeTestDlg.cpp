
// NanoeyeTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "NanoeyeTest.h"
#include "NanoeyeTestDlg.h"

#include "NanoeyeAlign.h"
#include "NanoeyeEgps.h"
#include "NanoeyeLens.h"
#include "NanoeyeScan.h"
#include "NanoeyeStig.h"
#include "NanoeyeVacuum.h"
#include "NanoViewD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CNanoeyeTestDlg ��ȭ ����




CNanoeyeTestDlg::CNanoeyeTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNanoeyeTestDlg::IDD, pParent), minisem(NULL)

	, cnvd(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNanoeyeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, cNanoViewState);
}

BEGIN_MESSAGE_MAP(CNanoeyeTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CNanoeyeTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CNanoeyeTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTONSCAN, &CNanoeyeTestDlg::OnBnClickedButtonscan)
	ON_BN_CLICKED(IDC_BUTTONLENS, &CNanoeyeTestDlg::OnBnClickedButtonlens)
	ON_BN_CLICKED(IDC_BUTTONALIGN, &CNanoeyeTestDlg::OnBnClickedButtonalign)
	ON_BN_CLICKED(IDC_BUTTONSTIG, &CNanoeyeTestDlg::OnBnClickedButtonstig)
	ON_BN_CLICKED(IDC_BUTTONEGPS, &CNanoeyeTestDlg::OnBnClickedButtonegps)
	ON_BN_CLICKED(IDC_BUTTONVACUUM, &CNanoeyeTestDlg::OnBnClickedButtonvacuum)
END_MESSAGE_MAP()

// CNanoeyeTestDlg �޽��� ó����

BOOL CNanoeyeTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	HRESULT hr = CoInitialize(NULL);

	if(FAILED(hr)){
		AfxMessageBox(_T("COM ���̺귯�� �ʱ�ȭ ����"));
		SendMessage(WM_CLOSE);
		return true;
	}

	// SettingManager ����
	hr = CoCreateInstance(CLSID_SettingManager,
							NULL,
							CLSCTX_INPROC_SERVER,
							IID_ISettingManager,
							reinterpret_cast<void**>(&iSetManager));
	




	cnvd = new CNanoViewD();
	cnvd->iSetManager = iSetManager;
	cnvd->Create(IDD_Display);
	cnvd->ShowWindow(SW_SHOW);
	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CNanoeyeTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CNanoeyeTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CNanoeyeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNanoeyeTestDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CoUninitialize();

	if(minisem != NULL){	minisem->Release();	}

	delete(cnvd);

	CDialog::OnClose();
}

void CNanoeyeTestDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	HRESULT hr = CoCreateInstance(CLSID_ControllerMiniSEM,
									NULL,
									CLSCTX_INPROC_SERVER,
									IID_IController,
									reinterpret_cast<void**>(&minisem));

	if(FAILED(hr)){
		cNanoViewState.SetWindowTextW(_T("����"));
		minisem = NULL;
		return;
	}


	SAFEARRAY * portList = minisem->GetPortList();

	BSTR arr;
	_bstr_t temp;

	long lot = 0;
	SafeArrayGetElement(portList, &lot, &arr);

	temp.Assign(arr);


	VARIANT_BOOL vb = minisem->ColumnInit(temp);

	

	switch(vb){
	case 0:
		cNanoViewState.SetWindowTextW(_T("����"));
		break;
	case -1:
		cNanoViewState.SetWindowTextW(_T("����"));
		break;
	default:
		cNanoViewState.SetWindowTextW(_T("???"));
		break;
	}
}

void CNanoeyeTestDlg::OnBnClickedOk()
{
	OnOK();
}

void CNanoeyeTestDlg::OnBnClickedButtonscan()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	static bool created = false;

	static CNanoeyeScan *cScan = NULL;

	if(minisem == NULL){
		return;
	}

	if(cScan == NULL){
		cScan = new CNanoeyeScan();
		cScan->Create(IDD_DIALOGSCAN);
		cScan->ShowWindow(SW_SHOW     );
		cScan->minisem = this->minisem;
	}
	else{
		if(::IsWindowVisible(cScan->m_hWnd) == FALSE){
			cScan->ShowWindow(SW_SHOW     );
		}
	}
}

void CNanoeyeTestDlg::OnBnClickedButtonlens()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CNanoeyeTestDlg::OnBnClickedButtonalign()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	static bool created = false;

	static CNanoeyeAlign *cAlign;

	if(::IsWindow(cAlign->m_hWnd)){
		if(::IsWindowVisible(cAlign->m_hWnd) == FALSE){
			cAlign->ShowWindow(SW_SHOW     );
		}
	}
	else{
		 cAlign = new CNanoeyeAlign();
		 cAlign->ShowWindow(SW_SHOW     );
	}
}

void CNanoeyeTestDlg::OnBnClickedButtonstig()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CNanoeyeTestDlg::OnBnClickedButtonegps()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CNanoeyeTestDlg::OnBnClickedButtonvacuum()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
