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
	//CLine(){ iCount++; };
	CLine(CPoint Start, CPoint End);
	~CLine(){ iCount--; };

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


