#pragma once
#include "CPoint.h"

#pragma region "CRectangle"


class CRectangle{

private:
	static int iCount;

private:
	CPoint pBotLeft;
	CPoint pTopRight;

public:
	//CRectangle(){ iCount++; };
	CRectangle(CPoint BotLeft, CPoint TopRight);
	~CRectangle(){ iCount--; };

	//copy constructior
	CRectangle(const CRectangle& oSource);

	//assignment
	CRectangle& operator= (const CRectangle& oSource);

	static int CRectangle::getCount() { return iCount; };


	void set(CPoint BotLeft, CPoint TopRight);
	void setBotLeft(CPoint BotLeft);
	void setTopRight(CPoint TopRight);

	CPoint listBotLeft();
	CPoint listTopRight();
	float getArea();

	void list(void);
};

#pragma endregion
