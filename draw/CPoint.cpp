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

	myX = oSource.myX;
	myY = oSource.myY;
	myColor = oSource.myColor;
	
	return *this; //referenz auf mich selbst
}

//draw stuff
void  CPoint::draw() const{
	glPointSize(CPoint::pointSize);
	glColor3f(CPoint::myR, CPoint::myG, CPoint::myB);
	glBegin(GL_POINTS);

	glVertex3f(myX, myY, 0.0);
	glEnd();

}

void CPoint::erase() const {

}



float CPoint::pointSize = pSize;
void CPoint::set(float x, float y){
	this->myX = x;
	this->myY = y;
}

void CPoint::setX(float x){
	this->myX = x;
}

void CPoint::setY(float y){
	this->myY = y;
}

float CPoint::getX(void){
	return this->myX;
}
float CPoint::getY(void){
	return this->myY;
}
void CPoint::listX(void){
	cout << "CPoint : x= " << this->myX;
}
void CPoint::listY(void){
	cout << "CPoint : y= " << this->myY;
}
void CPoint::list(void){
	cout << "CPoint : x= " << this->myX << ", y= " << this->myY << endl;
}


#pragma endregion
