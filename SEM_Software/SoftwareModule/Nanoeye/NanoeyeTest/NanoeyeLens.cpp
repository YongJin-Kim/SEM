// NanoeyeLens.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NanoeyeTest.h"
#include "NanoeyeLens.h"


// CNanoeyeLens ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CNanoeyeLens, CDialog)

CNanoeyeLens::CNanoeyeLens(CWnd* pParent /*=NULL*/)
	: CDialog(CNanoeyeLens::IDD, pParent)
{

}

CNanoeyeLens::~CNanoeyeLens()
{
}

void CNanoeyeLens::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNanoeyeLens, CDialog)
END_MESSAGE_MAP()


// CNanoeyeLens �޽��� ó�����Դϴ�.
