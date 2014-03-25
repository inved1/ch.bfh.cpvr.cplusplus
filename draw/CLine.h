#pragma once
#include "CPoint.h"


#pragma region "CLine"

class CLine{

private:
	static int iCount;

private:
	CPoint pStart;
	CPoint pEnd;

public:
	CLine();
	CLine(CPoint Start, CPoint End);
	CLine(int x1, int y1, int x2, int y2);

	~CLine(){ iCount--; };

	//copy constructior
	CLine(const CLine& oSource);

	//assignment
	CLine& operator= (const CLine& oSource);

	//draw stuff
	void drawLine(void);

	static int CLine::getCount() { return iCount; };

	void set(CPoint Start, CPoint End);
	void setStart(CPoint Start);
	void setEnd(CPoint End);

	CPoint listStart();
	CPoint listEnd();

	float getLength();

	void list(void);

};

#pragma endregion


