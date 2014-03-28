#include "CCircle.h"
#include <gl\glut.h>
#include <cmath>
#include <iostream>

#define PI  3.14159265358979324

using namespace std;


#pragma region "static"

static int iVertices = 3650;
#pragma endregion


#pragma region "CCircle"

CCircle::CCircle(){
	CCircle::ulCount++;
}

CCircle::CCircle(CPoint Center, float Radius)
:pCenter(Center), fRadius(Radius) {
	CCircle::ulCount++;
}
CCircle::CCircle(float x, float y, float Radius){
	this->pCenter = CPoint(x, y);
	this->fRadius = Radius;
}

CCircle::CCircle(const CCircle& oSource)
:fRadius(oSource.fRadius),pCenter(oSource.pCenter) {
	CCircle::ulCount++;
}

//assignment
CCircle& CCircle::operator=(const CCircle& oSource){
	this->fRadius = oSource.fRadius;
	this->pCenter = oSource.pCenter;

	return *this; //referenz auf mich selbst
}

//draw circle
void CCircle::drawCircle(void){
	float angle = 0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= iVertices; i++){
		glVertex3d(this->pCenter.getX() + this->fRadius * cos(angle),
			this->pCenter.getY() + this->fRadius * sin(angle),
			0.0);
		angle += 2 * PI / iVertices;
	}
	glEnd();
	glFlush();


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