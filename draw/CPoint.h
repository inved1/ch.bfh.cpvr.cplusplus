#pragma once
#pragma region "CPoint"

#include "CFigure.h"

using namespace std;

class CPoint : public CFigure 
{

	//friend

	friend class CLine;
	friend class CRect;
	friend class CCircle;


private:
	unsigned long ulCount = 0;
	float myX;
	float myY;
	ColorType myColor;

public:
	CPoint(){ myX = 0; myY = 0; myColor = BLACK;  CPoint::ulCount++; };
	CPoint(float x, float y, ColorType c) :myX(x), myY(y), myColor(c) { CPoint::ulCount++; };
	~CPoint(){ CPoint::ulCount--; };

	void draw() const;
	void erase() const;
	void changeColor(ColorType c);

	//copy constructior
	CPoint(const CPoint& oSource); 

	
	CPoint operator+ (const CPoint& oSource) const { return CPoint(myX + oSource.myX, myY + oSource.myY, oSource.myColor); }
	CPoint operator- (const CPoint& oSource) const { return CPoint(myX - oSource.myX, myY - oSource.myY, oSource.myColor); }
	//assignment
	CPoint& operator= (const CPoint& oSource);


	static float pointSize;


	void set(float x, float y);
	void setX(float x);
	void setY(float y);

	float getX(void);
	float getY(void);
	void listX(void);
	void listY(void);

	void list(void);



};

#pragma endregion
