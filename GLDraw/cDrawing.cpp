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


void cDrawing::addPoint(float x, float y){
	myPoints.push_back(new CPoint(x, y));
}
void cDrawing::addCircle(float x, float y, float Radius){
	myCircles.push_back(new CCircle(x,y, Radius));
}
void cDrawing::addLine(float x1, float y1, float x2, float y2){
	myLines.push_back(new CLine(x1, y1, x2, y2));
}
void cDrawing::addRectangle(float x1, float y1, float x2, float y2){
	myRectangles.push_back(new CRectangle(x1, y1, x2, y2));
}