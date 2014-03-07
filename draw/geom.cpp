
#include "geom.h";
#include <cmath>;
#include <iostream>;


using namespace std;


#pragma region "static"

int CPoint::iCount = 0;
int CCircle::iCount = 0;
int CLine::iCount = 0;
int CRectangle::iCount = 0;

#pragma endregion



#pragma region "CPoint"

CPoint::CPoint(float x , float y)
:X(x),Y(y){
	CPoint::iCount++;
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

float CPoint::getX(void){
	return this->X;
}
float CPoint::getY(void){
	return this->Y;
}
void CPoint::listX(void){
	cout << "CPoint : x= "<< this->X;
}
void CPoint::listY(void){
	cout << "CPoint : y= " << this->Y;
}
void CPoint::list(void){
	cout << "CPoint : x= " << this->X << ", y= " << this->Y <<endl;
}


#pragma endregion

#pragma region "CLine"


CLine::CLine(CPoint start, CPoint end)
:pStart(start), pEnd(end){
	CLine::iCount++;
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

#pragma region "CRectangle"

CRectangle::CRectangle(CPoint BotLeft, CPoint TopRight):
pBotLeft(BotLeft), pTopRight(TopRight){
	CRectangle::iCount++;
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
	cout <<  "--topRight-- "; this->pTopRight.list();
	cout << endl;
}

#pragma endregion

#pragma region "CCircle"


CCircle::CCircle(CPoint Center, float Radius)
:pCenter(Center),fRadius(Radius) {
	CCircle::iCount++;
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