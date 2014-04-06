#include <gl\glut.h>

#include "CLine.h"
#include <cmath>
#include <iostream>

using namespace std;

#pragma region "static"


#pragma endregion


#pragma region "CLine"


CLine::CLine(CPoint start, CPoint end,ColorType c)
:myStart(start), myEnd(end), myColor(c) {
	CLine::ulCount++;
}

CLine::CLine(float x1, float y1, float x2, float y2, ColorType c){
	this->myStart.setX(x1);
	this->myStart.setY(y1);
	this->myEnd.setX(x2);
	this->myEnd.setY(y2);
	this->myColor = c;
	CLine::ulCount++;
}

//Copy constructor
CLine::CLine(const CLine& oSource)
:myStart(oSource.myStart),myEnd(oSource.myEnd), myColor(oSource.myColor)  {

}

//assignment
CLine& CLine::operator=(const CLine& oSource){

	this->myStart = oSource.myStart;
	this->myEnd = oSource.myEnd;
	this->myColor = oSource.myColor;

	return *this; //referenz auf mich selbst
}

//draw stuff
void CLine::draw(void) const{
	glBegin(GL_LINES);
	glVertex3f(CLine::myStart.myX, CLine::myStart.myY, 0.00);
	glVertex3f(CLine::myEnd.myX, CLine::myEnd.myY, 0.00);
	glEnd();
}
void CLine::erase(void) const{

}

void CLine::set(CPoint start, CPoint end){
	this->myStart = start;
	this->myEnd = end;
}

void CLine::setStart(CPoint start){
	this->myStart = start;
}
void CLine::setEnd(CPoint end){
	this->myEnd = end;
}

CPoint CLine::listStart(){
	return this->myStart;
}

CPoint CLine::listEnd(){
	return this->myEnd;
}

float CLine::getLength(){
	return
		abs(
		sqrt(
		(pow((float)(this->myStart.getX() - this->myEnd.getX()), 2.0) +
		pow((float)(this->myStart.getY() - this->myEnd.getY()), 2.0))));

}

void CLine::list(void){
	cout << "CLine :" << endl << "--s-- "; this->myStart.list();
	cout << "--e-- "; this->myEnd.list();
	cout << endl;
}

#pragma endregion