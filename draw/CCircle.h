#pragma once
#include "CPoint.h"


#pragma region "CCircle"

class CCircle{

private:
	unsigned long ulCount = 0;

private:
	CPoint pCenter;
	float fRadius;

public:
	CCircle();
	CCircle(CPoint Center, float Radius);
	CCircle(float x, float y, float Radius);
	~CCircle(){ ulCount--; };

	//copy constructior
	CCircle(const CCircle& oSource);

	//assignment
	CCircle& operator= (const CCircle& oSource);

	//draw stuff
	void drawCircle();



	void set(CPoint Center, float Radius);
	void setCenter(CPoint Center);
	void setRadius(float Radius);

	CPoint listCenter();
	float listRadius();
	float getArea();

	void list(void);
};

#pragma endregion