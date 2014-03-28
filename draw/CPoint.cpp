#include <gl\glut.h>

#include "CPoint.h"
#include <iostream>
#include <cmath>


using namespace std;

#pragma region "static"


static float pSize = 3.0;

#pragma endregion



#pragma region "CPoint"



//Copy constructor
CPoint::CPoint(const CPoint& oSource){
	*this  = oSource;
	CPoint::ulCount++;
}

//assignment
CPoint& CPoint::operator=(const CPoint& oSource){

	X = oSource.X;
	Y = oSource.Y;
	
	return *this; //referenz auf mich selbst
}

//draw stuff
void  CPoint::drawPoint(void){
	glPointSize(CPoint::pointSize);
	glBegin(GL_POINTS);
	glVertex3f(X, Y, 0.0);
	glEnd();

}

float CPoint::pointSize = pSize;
void CPoint::set(float x, float y){
	this->X = x;
	this->Y = y;
}

void CPoint::setX(float x){
	this->X = x;
}

void CPoint::setY(float y){
	this->Y = y;
}

float CPoint::getX(void){
	return this->X;
}
float CPoint::getY(void){
	return this->Y;
}
void CPoint::listX(void){
	cout << "CPoint : x= " << this->X;
}
void CPoint::listY(void){
	cout << "CPoint : y= " << this->Y;
}
void CPoint::list(void){
	cout << "CPoint : x= " << this->X << ", y= " << this->Y << endl;
}


#pragma endregion
