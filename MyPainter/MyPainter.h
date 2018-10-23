
// MyPainter.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyPainterApp:
// See MyPainter.cpp for the implementation of this class
//
#include <vector>
#include "Figure.h"
class CMyPainterApp : public CWinApp
{
		//1 b
	enum FIGURES{LINE,RECTANGLE,TRIANGLE,ELLIPSE,SQUARE,PARALLELOGRAM,RIGHTANGLEDTRAPEZOID,RIGHTTRIANGLE};
	FIGURES futureFigKIND;
    //COLORREF curColor;
    //1 e

	//Figure *f;
	//int indexMAX;
	//Figure* figs[100];

	//bool isPressed;
	//CPoint startP;
	//CPoint endP;
public:
	//CDlgDlg(CWnd* pParent = NULL);	// standard constructor
	//~CDlgDlg();
	CMyPainterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMyPainterApp theApp;