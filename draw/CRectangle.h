#pragma once
#include "CPoint.h"

#pragma region "CRectangle"


class CRectangle{

private:
	unsigned long ulCount = 0;

private:
	CPoint pBotLeft;
	CPoint pTopRight;

public:
	CRectangle();
	CRectangle(CPoint BotLeft, CPoint TopRight);
	CRectangle(float x1, float y1, float x2, float y2);
	~CRectangle(){ ulCount--; };

	//copy constructior
	CRectangle(const CRectangle& oSource);

	//assignment
	CRectangle& operator= (const CRectangle& oSource);

	//draw stuff
	void drawRectangle();


	void set(CPoint BotLeft, CPoint TopRight);
	void setBotLeft(CPoint BotLeft);
	void setTopRight(CPoint TopRight);

	CPoint listBotLeft();
	CPoint listTopRight();
	float getArea();

	void list(void);
};

#pragma endregion
