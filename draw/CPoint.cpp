#include "CPoint.h"
#include <iostream>
#include <cmath>

using namespace std;

#pragma region "static"

int CPoint::iCount = 0;
#pragma endregion



#pragma region "CPoint"

CPoint::CPoint(float x, float y)
:X(x), Y(y){
	CPoint::iCount++;
}

//Copy constructor
CPoint::CPoint(const CPoint& oSource){
	this->X = oSource.X;
	this->Y = oSource.Y;
}

//assignment
CPoint& CPoint::operator=(const CPoint& oSource){

	this->X = oSource.X;
	this->Y = oSource.Y;

	return *this; //referenz auf mich selbst
}


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
