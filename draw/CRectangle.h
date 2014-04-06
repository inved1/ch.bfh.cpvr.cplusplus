#pragma once
#include "CPoint.h"
#include "CFigure.h"

#pragma region "CRectangle"


class CRectangle: public CFigure{

	friend class CLine;
	friend class CPoint;
	friend class CCircle;

private:
	unsigned long ulCount = 0;

	CPoint myBotLeft;
	CPoint myTopRight;
	ColorType myColor;

public:
	CRectangle();
	CRectangle(CPoint BotLeft, CPoint TopRight,ColorType c);
	CRectangle(float x1, float y1, float x2, float y2, ColorType c);
	~CRectangle(){ ulCount--; };

	void draw() const;
	void erase() const;
	void changeColor(ColorType c);


	//copy constructior
	CRectangle(const CRectangle& oSource);

	//assignment
	CRectangle& operator= (const CRectangle& oSource);

	//draw stuff
	


	void set(CPoint BotLeft, CPoint TopRight);
	void setBotLeft(CPoint BotLeft);
	void setTopRight(CPoint TopRight);

	CPoint listBotLeft();
	CPoint listTopRight();
	float getArea();

	void list(void);
};

#pragma endregion
