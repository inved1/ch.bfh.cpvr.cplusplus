#pragma once
#pragma region "CPoint"

using namespace std;

class CPoint
{

	//friend

	friend class CLine;
	friend class CRect;
	friend class CCircle;


private:
	unsigned long ulCount = 0;


private:
	float X;
	float Y;

public:
	CPoint(){ X = 0; Y = 0; CPoint::ulCount++; };
	CPoint(float x, float y) :X(x), Y(y) { CPoint::ulCount++; };
	~CPoint(){ CPoint::ulCount--; };

	//copy constructior
	CPoint(const CPoint& oSource); 

	
	CPoint operator+ (const CPoint& oSource) const { return CPoint(X + oSource.X, Y + oSource.Y); }
	CPoint operator- (const CPoint& oSource) const { return CPoint(X - oSource.X, Y - oSource.Y); }
	//assignment
	CPoint& operator= (const CPoint& oSource);

	//draw stuff
	void drawPoint(void);
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
