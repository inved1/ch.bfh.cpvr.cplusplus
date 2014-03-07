





#pragma region "CPoint"

class CPoint
{
private: 
	static int iCount;


private:
	float X;
	float Y;

public:
	//CPoint(){ iCount++; };
	CPoint(float x, float y);
	~CPoint(){ iCount--; };

	static int CPoint::getCount() { return iCount; };

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

#pragma region "CLine"

class CLine{

private:
	static int iCount;

private:
	CPoint pStart;
	CPoint pEnd;

public:
	//CLine(){ iCount++; };
	CLine(CPoint Start, CPoint End);
	~CLine(){ iCount--; };
	
	static int CLine::getCount() { return iCount; };

	void set(CPoint Start, CPoint End);
	void setStart(CPoint Start);
	void setEnd(CPoint End);

	CPoint listStart();
	CPoint listEnd();

	float getLength();
	
	void list(void);

};

#pragma endregion

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

#pragma region "CCircle"

class CCircle{

private:
	static int iCount;

private:
	CPoint pCenter;
	float fRadius;

public:
	//CCircle(){ iCount++; };
	CCircle(CPoint Center, float Radius);
	~CCircle(){ iCount--; };

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