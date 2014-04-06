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

CCircle::CCircle(CPoint Center, float Radius, ColorType c)
:myCenter(Center), myRadius(Radius), myColor(c){
	CCircle::ulCount++;
}
CCircle::CCircle(float x, float y, float Radius, ColorType c){
	this->myCenter = CPoint(x, y,c);
	this->myRadius = Radius;
	this->myColor = c;
}

CCircle::CCircle(const CCircle& oSource)
:myRadius(oSource.myRadius), myCenter(oSource.myCenter),myColor(oSource.myColor) {
	CCircle::ulCount++;
}

//assignment
CCircle& CCircle::operator=(const CCircle& oSource){
	this->myRadius = oSource.myRadius;
	this->myCenter = oSource.myCenter;

	return *this; //referenz auf mich selbst
}

//draw circle
void CCircle::draw(void) const{
	float angle = 0;
	glColor3f(CCircle::myR, CCircle::myG, CCircle::myB);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= iVertices; i++){
		glVertex3d(CCircle::myCenter.myX + CCircle::myRadius  * cos(angle),
			CCircle::myCenter.myY + CCircle::myRadius * sin(angle),
			0.0);
		angle += 2 * PI / iVertices;
	}
	glEnd();
	glFlush();


}

void CCircle::erase(void) const {

}

void CCircle::set(CPoint Center, float Radius){
	this->myCenter = Center;
	this->myRadius = Radius;
}
void CCircle::setCenter(CPoint Center){
	this->myCenter = Center;
}
void CCircle::setRadius(float Radius){
	this->myRadius = Radius;
}
CPoint CCircle::listCenter(){
	return this->myCenter;
}
float CCircle::listRadius(){
	return this->myRadius;
}
float CCircle::getArea(){
	return pow((float)this->myRadius, 2.0) * atan(1.0) * 4; //PI
}
void CCircle::list(void){
	cout << "CCircle :" << endl << "--center-- "; this->myCenter.list();
	cout << "--radius-- " << this->myRadius << endl;

}

#pragma endregion