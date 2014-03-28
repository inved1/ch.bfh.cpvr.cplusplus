#pragma once
#include "CPoint.h"


#pragma region "CLine"

class CLine{

private:
	unsigned long ulCount = 0;

private:
	CPoint pStart;
	CPoint pEnd;

public:
	CLine();
	CLine(CPoint Start, CPoint End);
	CLine(float x1, float y1, float x2, float y2);

	~CLine(){ ulCount--; };

	//copy constructior
	CLine(const CLine& oSource);

	//assignment
	CLine& operator= (const CLine& oSource);

	//draw stuff
	void drawLine(void);

	void set(CPoint Start, CPoint End);
	void setStart(CPoint Start);
	void setEnd(CPoint End);

	CPoint listStart();
	CPoint listEnd();

	float getLength();

	void list(void);

};

#pragma endregion


