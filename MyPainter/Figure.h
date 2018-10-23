
#pragma once   

class Figure: public CObject 
{
public:
	DECLARE_SERIAL(Figure)
	Figure();
	Figure(BOOL isThin);
	virtual ~Figure(void);
	void setStart(CPoint p) { startP = p; }
	void setEnd(CPoint p) { endP = p; }
	CPoint getStart() const { return startP; }
	CPoint getEnd() const { return endP; }
	COLORREF getBg() const { return bgColor; }	
	COLORREF getFBg() const { return FbgColor; }	
	void setBg(COLORREF c) { bgColor = c; }
	void setFBg(COLORREF c) { FbgColor = c; }
	virtual void draw(CDC *dc);
	virtual void innerDraw(CDC *dc){} ;
	virtual void Draw(CDC *dc){};
	void Serialize(CArchive &archive);
	protected:
	BOOL isThin;
	CPoint startP , endP;
	COLORREF bgColor,FbgColor;
};

