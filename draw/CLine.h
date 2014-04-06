#pragma once
#include "CPoint.h"
#include "CFigure.h"

#pragma region "CLine"

class CLine : public CFigure{

	friend class CPoint;
	friend class CRect;
	friend class CCircle;

	
private:
	unsigned long ulCount = 0;

	CPoint myStart;
	CPoint myEnd;
	ColorType myColor;

public:
	CLine(){ myStart = CPoint(), myEnd = CPoint(), myColor = BLACK; CLine::ulCount++; };
	CLine(CPoint Start, CPoint End, ColorType c);
	CLine(float x1, float y1, float x2, float y2, ColorType c);

	~CLine(){ ulCount--; };

	void draw() const;
	void erase() const;
	void changeColor(ColorType c);


	//copy constructior
	CLine(const CLine& oSource);

	//assignment
	CLine& operator= (const CLine& oSource);

	//draw stuff
	
	void set(CPoint Start, CPoint End);
	void setStart(CPoint Start);
	void setEnd(CPoint End);

	CPoint listStart();
	CPoint listEnd();

	float getLength();

	void list(void);

};

#pragma endregion


