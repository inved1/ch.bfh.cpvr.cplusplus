
#pragma region "CPoint"

class CPoint
{
	//publics
private:
	float X;
	float Y;

public:
	CPoint(float x, float y);

	void set(float x, float y);
	void setX(float x);
	void setY(float y);

	float listX();
	float listY();

	//?
	const float* list[2];


			
};

#pragma endregion

#pragma region "CLine"

class CLine{
 
private:
	CPoint pStart;
	CPoint pEnd;

public:
	CLine(CPoint Start, CPoint End);

	void set(CPoint Start, CPoint End);
	void setStart(CPoint Start);
	void setEnd(CPoint End);

	CPoint listStart();
	CPoint listEnd();

	float getLength();
	
	//?
	const CPoint* list[2];

};

#pragma endregion

#pragma region "CRectangle"


class CRectangle{
private:
	CPoint pBotLeft;
	CPoint pTopRight;

public:
	CRectangle(CPoint BotLeft, CPoint TopRight);

	void set(CPoint BotLeft, CPoint TopRight);
	void setBotLeft(CPoint BotLeft);
	void setTopRight(CPoint TopRight);

	CPoint listBotLeft();
	CPoint listTopRight();
	float getArea();
	const CPoint* list[2];
};

#pragma endregion

#pragma region "CCircle"

class CCircle{
private:
	CPoint pCenter;
	float fRadius;

public:
	CCircle(CPoint Center, float Radius);


	void set(CPoint Center, float Radius);
	void setCenter(CPoint Center);
	void setRadius(float Radius);

	CPoint listCenter();
	float listRadius();
	float getArea();
};

#pragma endregion