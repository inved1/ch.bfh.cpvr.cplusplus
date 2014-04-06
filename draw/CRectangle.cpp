#include <gl\glut.h>

#include "CRectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

#pragma region "static"

#pragma endregion


#pragma region "CRectangle"

CRectangle::CRectangle(){
	CRectangle::ulCount++;
}

CRectangle::CRectangle(float x1, float y1, float x2, float y2, ColorType c){
	this->myBotLeft.setX(x1);
	this->myBotLeft.setY(y1);
	this->myTopRight.setX(x2);
	this->myTopRight.setY(y2);
	this->myColor = c;
	CRectangle::ulCount++;
}

CRectangle::CRectangle(CPoint BotLeft, CPoint TopRight, ColorType c) :
myBotLeft(BotLeft), myTopRight(TopRight), myColor(c){
	CRectangle::ulCount++;
}


//Copy constructor
CRectangle::CRectangle(const CRectangle& oSource)
:myBotLeft(oSource.myBotLeft),myTopRight(oSource.myTopRight), myColor(oSource.myColor){
}

//assignment
CRectangle& CRectangle::operator=(const CRectangle& oSource){
	this->myBotLeft = oSource.myBotLeft;
	this->myTopRight = oSource.myTopRight;
	this->myColor = oSource.myColor;

	return *this; //referenz auf mich selbst
}

//draw stuff
void CRectangle::draw(void) const{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(CRectangle::myBotLeft.myX, CRectangle::myBotLeft.myY, CRectangle::myTopRight.myX, CRectangle::myTopRight.myY);

}
void CRectangle::erase(void) const{

}

void CRectangle::set(CPoint BotLeft, CPoint TopRight){
	this->myBotLeft = BotLeft;
	this->myTopRight = TopRight;
}

void CRectangle::setBotLeft(CPoint BotLeft){
	this->myBotLeft = BotLeft;
}
void CRectangle::setTopRight(CPoint TopRight){
	this->myTopRight = TopRight;
}

CPoint CRectangle::listBotLeft(){
	return this->myBotLeft;
}
CPoint CRectangle::listTopRight(){
	return this->myTopRight;
}
float CRectangle::getArea(){
	return abs((this->myBotLeft.getX() - this->myTopRight.getX()))*
		abs((this->myBotLeft.getY() - this->myTopRight.getY()));
}
void CRectangle::list(void){
	cout << "CLine :" << endl << "--botLeft-- "; this->myBotLeft.list();
	cout << "--topRight-- "; this->myTopRight.list();
	cout << endl;
}

#pragma endregion