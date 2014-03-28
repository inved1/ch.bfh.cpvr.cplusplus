#include <gl\glut.h>

#include "CLine.h"
#include <cmath>
#include <iostream>

using namespace std;

#pragma region "static"


#pragma endregion


#pragma region "CLine"

CLine::CLine(){
	CLine::ulCount++;
}

CLine::CLine(CPoint start, CPoint end)
:pStart(start), pEnd(end){
	CLine::ulCount++;
}

CLine::CLine(float x1, float y1, float x2, float y2){
	this->pStart.setX(x1);
	this->pStart.setY(y1);
	this->pEnd.setX(x2);
	this->pEnd.setY(y2);
	CLine::ulCount++;
}

//Copy constructor
CLine::CLine(const CLine& oSource)
:pStart(oSource.pStart),pEnd(oSource.pEnd)  {

}

//assignment
CLine& CLine::operator=(const CLine& oSource){

	this->pStart = oSource.pStart;
	this->pEnd = oSource.pEnd;


	return *this; //referenz auf mich selbst
}

//draw stuff
void CLine::drawLine(){
	glBegin(GL_LINES);
	glVertex3f(this->pStart.getX(), this->pStart.getY(), 0.00);
	glVertex3f(this->pEnd.getX(), this->pEnd.getY(), 0.00);
	glEnd();
}


void CLine::set(CPoint start, CPoint end){
	this->pStart = start;
	this->pEnd = end;
}

void CLine::setStart(CPoint start){
	this->pStart = start;
}
void CLine::setEnd(CPoint end){
	this->pEnd = end;
}

CPoint CLine::listStart(){
	return this->pStart;
}

CPoint CLine::listEnd(){
	return this->pEnd;
}

float CLine::getLength(){
	return
		abs(
		sqrt(
		(pow((float)(this->pStart.getX() - this->pEnd.getX()), 2.0) +
		pow((float)(this->pStart.getY() - this->pEnd.getY()), 2.0))));

}

void CLine::list(void){
	cout << "CLine :" << endl << "--s-- "; this->pStart.list();
	cout << "--e-- "; this->pEnd.list();
	cout << endl;
}

#pragma endregion