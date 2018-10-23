#include "stdafx.h"
#include "Figure.h"
#include "MyPainter.h"
#include "MyPainterDlg.h"
#include "afxdialogex.h"
IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure(void){}
Figure::Figure(BOOL isThin):isThin(isThin){}
Figure::~Figure(void){}
void Figure::Serialize( CArchive& archive )
{
    // call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if(archive.IsStoring())
		archive << startP.x << startP.y << endP.x << endP.y << bgColor;
    else
        archive >> startP.x >> startP.y >> endP.x >> endP.y >> bgColor;
}

void Figure::draw(CDC *dc) {
	CPen pen(PS_SOLID, isThin?1:3, FbgColor);
	CBrush brush(bgColor);
	CBrush *old = dc->SelectObject(&brush);
	CPen *oldPen = dc->SelectObject(&pen);
	innerDraw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(old);
}