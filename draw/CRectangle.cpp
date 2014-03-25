#include <gl\glut.h>

#include "CRectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

#pragma region "static"

int CRectangle::iCount = 0;
#pragma endregion


#pragma region "CRectangle"

CRectangle::CRectangle(){
	CRectangle::iCount++;
}

CRectangle::CRectangle(int x1, int y1, int x2, int y2){
	this->pBotLeft.setX(x1);
	this->pBotLeft.setY(y1);
	this->pTopRight.setX(x2);
	this->pTopRight.setY(y2);
	CRectangle::iCount++;
}

CRectangle::CRectangle(CPoint BotLeft, CPoint TopRight) :
pBotLeft(BotLeft), pTopRight(TopRight){
	CRectangle::iCount++;
}


//Copy constructor
CRectangle::CRectangle(const CRectangle& oSource)
:pBotLeft(oSource.pBotLeft),pTopRight(oSource.pTopRight){
}

//assignment
CRectangle& CRectangle::operator=(const CRectangle& oSource){
	this->pBotLeft = oSource.pBotLeft;
	this->pTopRight = oSource.pTopRight;

	return *this; //referenz auf mich selbst
}

//draw stuff
void CRectangle::drawRectangle(void){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(this->pBotLeft.getX(), this->pBotLeft.getY(), this->pTopRight.getX(), this->pTopRight.getY());

}

void CRectangle::set(CPoint BotLeft, CPoint TopRight){
	this->pBotLeft = BotLeft;
	this->pTopRight = TopRight;
}

void CRectangle::setBotLeft(CPoint BotLeft){
	this->pBotLeft = BotLeft;
}
void CRectangle::setTopRight(CPoint TopRight){
	this->pTopRight = TopRight;
}

CPoint CRectangle::listBotLeft(){
	return this->pBotLeft;
}
CPoint CRectangle::listTopRight(){
	return this->pTopRight;
}
float CRectangle::getArea(){
	return abs((this->pBotLeft.getX() - this->pTopRight.getX()))*
		abs((this->pBotLeft.getY() - this->pTopRight.getY()));
}
void CRectangle::list(void){
	cout << "CLine :" << endl << "--botLeft-- "; this->pBotLeft.list();
	cout << "--topRight-- "; this->pTopRight.list();
	cout << endl;
}

#pragma endregion