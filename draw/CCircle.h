#pragma once
#include "CPoint.h"
#include "CFigure.h"


#pragma region "CCircle"

class CCircle: public CFigure {


	friend class CLine;
	friend class CRect;
	friend class CCircle;


private:
	unsigned long ulCount = 0;

	CPoint myCenter;
	float myRadius;
	ColorType myColor;

public:
	CCircle();
	CCircle(CPoint Center, float Radius,ColorType c);
	CCircle(float x, float y, float Radius, ColorType c);
	~CCircle(){ ulCount--; };

	void draw() const;
	void erase() const;
	void changeColor(ColorType c);


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