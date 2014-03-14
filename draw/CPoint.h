#pragma once
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

	//copy constructior
	CPoint(const CPoint& oSource); 

	//assignment
	CPoint& operator= (const CPoint& oSource);

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
