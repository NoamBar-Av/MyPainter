
// MyPainterDlg.h : header file
//

#pragma once
#include <vector>
#include <stack>
#include "Figure.h"
#include "shape_add.h"
#include "EllipseM.h"
#include "SqureM.h"
#include "ParallelogramM.h"
#include "RTriangleM.h"
#include "LineM.h"
#include "RectangleM.h"
#include "TriangleM.h"
#include "TrapezoidM.h"
#include "Command.h"
#include "afxwin.h"
using namespace std;

// CMyPainterDlg dialog
class CMyPainterDlg : public CDialogEx
{
	int flagsave;
		enum FIGURES{LINE,RECTANGLE,TRIANGLE,ELLIPSE,SQUARE,PARALLELOGRAM,RIGHTANGLEDTRAPEZOID,RIGHTTRIANGLE};
			FIGURES futureFigKIND;
			//COLORREF curColor;
	//CObArray shapes;
	CTypedPtrArray<CObArray, Figure*> shapes;
	//vector<Figure*> shapes;
	stack<Command*> commands, undoes;
	bool isPressed;
	CPoint startP;
	CPoint endP;
	//Figure* figure;
	virtual void OnOK();
// Construction
public:
	CMyPainterDlg(CWnd* pParent = NULL);	// standard constructor
	~CMyPainterDlg();
// Dialog Data
	enum { IDD = IDD_MYPAINTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_red;
	CSliderCtrl m_green;
	CSliderCtrl m_blue;
	CSliderCtrl F_red;
	CSliderCtrl F_green;
	CSliderCtrl F_blue;

	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	BOOL isThin;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
//	CButton m_btnsave;
//	CButton n_btnNEW;
};
