// NanoeyeAlign.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NanoeyeTest.h"
#include "NanoeyeAlign.h"


// CNanoeyeAlign ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CNanoeyeAlign, CDialog)

CNanoeyeAlign::CNanoeyeAlign(CWnd* pParent /*=NULL*/)
	: CDialog(CNanoeyeAlign::IDD, pParent)
	, minisem(NULL)
{

}

CNanoeyeAlign::~CNanoeyeAlign()
{
}

void CNanoeyeAlign::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNanoeyeAlign, CDialog)
END_MESSAGE_MAP()


// CNanoeyeAlign �޽��� ó�����Դϴ�.
