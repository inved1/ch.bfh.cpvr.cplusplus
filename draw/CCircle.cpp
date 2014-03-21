#include "CCircle.h"
#include <cmath>
#include <iostream>

using namespace std;


#pragma region "static"

int CCircle::iCount = 0;
#pragma endregion


#pragma region "CCircle"


CCircle::CCircle(CPoint Center, float Radius)
:pCenter(Center), fRadius(Radius) {
	CCircle::iCount++;
}
CCircle::CCircle(const CCircle& oSource)
:fRadius(oSource.fRadius),pCenter(oSource.pCenter) {
}

//assignment
CCircle& CCircle::operator=(const CCircle& oSource){
	this->fRadius = oSource.fRadius;
	this->pCenter = oSource.pCenter;

	return *this; //referenz auf mich selbst
}
void CCircle::set(CPoint Center, float Radius){
	this->pCenter = Center;
	this->fRadius = Radius;
}
void CCircle::setCenter(CPoint Center){
	this->pCenter = Center;
}
void CCircle::setRadius(float Radius){
	this->fRadius = Radius;
}
CPoint CCircle::listCenter(){
	return this->pCenter;
}
float CCircle::listRadius(){
	return this->fRadius;
}
float CCircle::getArea(){
	return pow((float)this->fRadius, 2.0) * atan(1.0) * 4; //PI
}
void CCircle::list(void){
	cout << "CCircle :" << endl << "--center-- "; this->pCenter.list();
	cout << "--radius-- " << this->fRadius << endl;

}

#pragma endregion