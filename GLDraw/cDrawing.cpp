#include "cDrawing.h"
#include "..\draw\CCircle.h"
#include "..\draw\CLine.h"
#include "..\draw\CRectangle.h"
#include "..\draw\CPoint.h"

#include <vector>


using namespace std;

vector<CPoint*> myPoints;
vector<CCircle*> myCircles;
vector<CLine*> myLines;
vector<CRectangle*> myRectangles;


void cDrawing::clearDrawing(){

}

void cDrawing::displayDrawing(){

}	


void cDrawing::addFigure(  CPoint* p1, CPoint *p2){
	
	//todo
	

}


void cDrawing::addPoint(float x, float y, ColorType c){
	myPoints.push_back(new CPoint(x, y,c));
}
void cDrawing::addCircle(float x, float y, float Radius, ColorType c){
	myCircles.push_back(new CCircle(x,y, Radius,c));
}
void cDrawing::addLine(float x1, float y1, float x2, float y2, ColorType c){
	myLines.push_back(new CLine(x1, y1, x2, y2, c));
}
void cDrawing::addRectangle(float x1, float y1, float x2, float y2, ColorType c){
	myRectangles.push_back(new CRectangle(x1, y1, x2, y2,c));
}