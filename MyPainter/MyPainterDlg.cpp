
// MyPainterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyPainter.h"
#include "MyPainterDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyPainterDlg dialog




CMyPainterDlg::CMyPainterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyPainterDlg::IDD, pParent)
	, isThin(FALSE)
{
	futureFigKIND=LINE;
	isPressed=false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CMyPainterDlg::~CMyPainterDlg()
{}

void CMyPainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_red);
	DDX_Control(pDX, IDC_SLIDER2, m_green);
	DDX_Control(pDX, IDC_SLIDER3, m_blue);
	DDX_Control(pDX, IDC_SLIDER4, F_red);
	DDX_Control(pDX, IDC_SLIDER5, F_green);
	DDX_Control(pDX, IDC_SLIDER6, F_blue);
	DDX_Check(pDX, IDC_CHECK1, isThin);

//	DDX_Control(pDX, IDC_BUTTON4, m_btnsave);
//DDX_Control(pDX, IDC_BUTTON5, n_btnNEW);
}

BEGIN_MESSAGE_MAP(CMyPainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CMyPainterDlg::OnBnClickedCheck1)
	
	ON_BN_CLICKED(IDC_BUTTON1, &CMyPainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyPainterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyPainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyPainterDlg::OnBnClickedButton4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMyPainterDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CMyPainterDlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CMyPainterDlg::OnNMCustomdrawSlider3)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON5, &CMyPainterDlg::OnBnClickedButton5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &CMyPainterDlg::OnNMCustomdrawSlider4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &CMyPainterDlg::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER6, &CMyPainterDlg::OnNMCustomdrawSlider6)
	
	//ON_BN_CLICKED(IDC_UNDO, &CMyPainterDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_RADIO1, &CMyPainterDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMyPainterDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMyPainterDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMyPainterDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMyPainterDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMyPainterDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CMyPainterDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CMyPainterDlg::OnBnClickedRadio8)
END_MESSAGE_MAP()


// CMyPainterDlg message handlers

BOOL CMyPainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_btnsave.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),  MAKEINTRESOURCE(IDI_ICON1)));
//	n_btnNEW.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),  MAKEINTRESOURCE(IDI_ICON3)));

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
	m_red.SetRangeMax(255);
	m_red.SetRangeMin(0);
	m_green.SetRangeMax(255);
	m_green.SetRangeMin(0);
	m_blue.SetRangeMax(255);
	m_blue.SetRangeMin(0);

	F_red.SetRangeMax(255);
	F_red.SetRangeMin(0);
	F_green.SetRangeMax(255);
	F_green.SetRangeMin(0);
	F_blue.SetRangeMax(255);
	F_blue.SetRangeMin(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyPainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyPainterDlg::OnPaint()
{
	CPaintDC dc(this);

	for (int i=0; i < shapes.GetSize(); ++i)
		shapes[i]->draw(&dc);

	CBrush brush(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	CBrush *oldBrush = dc.SelectObject(&brush);
	CPen pen(PS_SOLID, isThin?1:3,RGB(F_red.GetPos(), F_green.GetPos(), F_blue.GetPos()) /*RGB(0,0,0)*/);
	CPen *oldPen = dc.SelectObject(&pen);
	dc.Rectangle(875,52,915,92);
	dc.SelectObject( oldBrush ); 
	dc.SelectObject(oldPen);
		
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyPainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyPainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(isPressed)
	{
		/*CPen myPen1(PS_DASH, isThin?1:3, RGB(0,0,255));*/

		shapes[shapes.GetSize() - 1]->setEnd(point);
		Invalidate();

	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMyPainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	isPressed=true;
	Figure *n=0;
	switch(futureFigKIND)
	{
	case RECTANGLE: n = new RectangleM(isThin);
		break;
	case ELLIPSE: n = new EllipseM(isThin); 
		break;
	case LINE: n = new LineM(isThin);
		break;
	case TRIANGLE: n = new TriangleM(isThin);
		break;
	case SQUARE: n = new SqureM(isThin);
		break;
	case PARALLELOGRAM: n = new ParallelogramM(isThin);
		break;
	case RIGHTANGLEDTRAPEZOID: n = new TrapezoidM(isThin);
		break;
	case RIGHTTRIANGLE: n = new RTriangleM(isThin);
		break;
	}

	Command *c = new shape_add(shapes, n);
	c->perform();
	commands.push(c);
	//shapes.Add(n);
	n->setBg(RGB(m_red.GetPos(), m_green.GetPos(), m_blue.GetPos()));
	n->setFBg(RGB(F_red.GetPos(), F_green.GetPos(), F_blue.GetPos()));
	n->setStart(point);
	n->setEnd(point);
	Invalidate();
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMyPainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
		isPressed=false;
		shapes[shapes.GetSize() - 1]->setEnd(point);	
		Invalidate();
	CDialogEx::OnLButtonUp(nFlags, point);

	
}


void CMyPainterDlg::OnOK()
{
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	shapes.Serialize(ar);
	Invalidate();
	CDialogEx::OnOK();
}


void CMyPainterDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}




void CMyPainterDlg::OnBnClickedButton3()
{
	std::string *pPath;
	CFileDialog dlg(true,_T("Chart Files (*.$$)|*.$$|"),NULL,NULL,_T("Chart Files (*.$$)|*.$$|"));
	auto result = dlg.DoModal();
    if(result != IDOK)
			 MessageBox(_T("Problem With Choosing This File"), _T("Error"), 
      MB_ICONERROR | MB_OK);
	OPENFILENAME& ofn = dlg.GetOFN( );
	CFile file(ofn.lpstrFile, CFile::modeRead);
	CArchive ar (&file, CArchive::load);
	shapes.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
}



void CMyPainterDlg::OnBnClickedButton4()
{
	
	// TODO: Add your control notification handler code here
	std::string *pPath;
	CFileDialog dlg(false,_T("Chart Files (*.$$)|*.$$|"),NULL,NULL,_T("Chart Files (*.$$)|*.$$|"));
	auto result = dlg.DoModal();
    if(result != IDOK)
		 MessageBox(_T("Problem With Choosing This File"), _T("Error"), 
      MB_ICONERROR | MB_OK);
    //else 
		//pPath->assign(dlg.GetPathName());
OPENFILENAME& ofn = dlg.GetOFN( );
	char* s = NULL;
	try
	{
		CFile file(ofn.lpstrFile, CFile::modeCreate);
	}
	catch(int e)
	{};
	CFile file(ofn.lpstrFile, CFile::modeWrite);
	
	CArchive ar (&file, CArchive::store);
	shapes.Serialize(ar);
	ar.Close();
	file.Close();
}




void CMyPainterDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
}




void CMyPainterDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if(commands.empty())
		return;
		Command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
		Invalidate();
}


void CMyPainterDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if(undoes.empty())
		return;
	Command *c = undoes.top();
	c->perform();
	commands.push(c);
	undoes.pop();
	Invalidate();
}


void CMyPainterDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMyPainterDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMyPainterDlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMyPainterDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	while(!commands.empty())
	{
		Command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
		Invalidate();
	}
	return;
}


void CMyPainterDlg::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMyPainterDlg::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMyPainterDlg::OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}





void CMyPainterDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=LINE;
}


void CMyPainterDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=RECTANGLE;
}


void CMyPainterDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=TRIANGLE;
}


void CMyPainterDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=ELLIPSE;
}


void CMyPainterDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=SQUARE;
}


void CMyPainterDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=PARALLELOGRAM;
}


void CMyPainterDlg::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=RIGHTANGLEDTRAPEZOID;
}


void CMyPainterDlg::OnBnClickedRadio8()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=RIGHTTRIANGLE;
}
