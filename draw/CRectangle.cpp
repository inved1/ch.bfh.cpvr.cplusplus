#include "CRectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

#pragma region "static"

int CRectangle::iCount = 0;
#pragma endregion


#pragma region "CRectangle"

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