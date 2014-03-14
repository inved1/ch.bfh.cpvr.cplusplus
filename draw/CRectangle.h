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
