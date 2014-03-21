#include "CLine.h"
#include <cmath>
#include <iostream>

using namespace std;

#pragma region "static"

int CLine::iCount = 0;
#pragma endregion


#pragma region "CLine"


CLine::CLine(CPoint start, CPoint end)
:pStart(start), pEnd(end){
	CLine::iCount++;
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