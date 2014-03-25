#pragma once
#include "CPoint.h"


#pragma region "CCircle"

class CCircle{

private:
	static int iCount;

private:
	CPoint pCenter;
	float fRadius;

public:
	CCircle();
	CCircle(CPoint Center, float Radius);
	~CCircle(){ iCount--; };

	//copy constructior
	CCircle(const CCircle& oSource);

	//assignment
	CCircle& operator= (const CCircle& oSource);

	//draw stuff
	void drawCircle();

	static int CCircle::getCount() { return iCount; };


	void set(CPoint Center, float Radius);
	void setCenter(CPoint Center);
	void setRadius(float Radius);

	CPoint listCenter();
	float listRadius();
	float getArea();

	void list(void);
};

#pragma endregion