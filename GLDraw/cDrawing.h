#pragma once

#include "..\draw\CPoint.h"
using namespace std;

class cDrawing
{
public:

	

	//copy from prof
	enum eFigType
	{
		FIG_POINT = 0x00, 
		FIG_LINE = 0x10, 
		FIG_RECT = 0x20, 
		FIG_CIRCLE = 0x30
	};
	
	static void displayDrawing();

	
	static void clearDrawing();
						
	static void addFigure( CPoint * p1,  CPoint * p2);

	static void addPoint( float x,  float y,ColorType c);

	static void addCircle(float x, float y, float Radius, ColorType c);

	static void addLine(float x1, float y1, float x2, float y2, ColorType c);

	static void addRectangle(float x1, float y1, float x2, float y2, ColorType c);





private:
	
};

