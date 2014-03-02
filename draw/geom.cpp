
#include "geom.h";
#include <cmath>;



#pragma region "CPoint"
CPoint::CPoint(float x = 0, float y = 0){
	this->X = x;
	this->Y = y;
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

float CPoint::listX(){
	return this->X;
}

float CPoint::listY(){
	return this->Y;
}


#pragma endregion

#pragma region "CLine"

CLine::CLine(CPoint start, CPoint end){
	this->pStart = start;
	this->pEnd = end;
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
		(pow((float)(this->pStart.listX() - this->pEnd.listX()), 2.0) +
		pow((float)(this->pStart.listY() - this->pEnd.listY()), 2.0))));

}

#pragma endregion

#pragma region "CRectangle"

CRectangle::CRectangle(CPoint BotLeft, CPoint TopRight){
	this->pBotLeft = BotLeft;
	this->pTopRight = TopRight;
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
	return abs((this->pBotLeft.listX() - this->pTopRight.listX()))*
		abs((this->pBotLeft.listY() - this->pTopRight.listY()));
}

#pragma endregion

#pragma region "CCircle"

CCircle::CCircle(CPoint Center, float Radius){
	this->pCenter = Center;
	this->fRadius = Radius;

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

#pragma endregion