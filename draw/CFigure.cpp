#include "CFigure.h"
#include <iostream>


using namespace std;


CFigure::CFigure(float x, float y, ColorType c) : myX(x), myY(y), myColor(c)
{
	cout << "Figure constructor: x/y: [" << myX << "/" << myY << "] color " << myColor << endl;
}


CFigure::~CFigure()
{
	cout << "Figure destructor: x/y: [" << myX << "/" << myY << "] color " << myColor << endl;
}

void CFigure::changeColor(ColorType c){
	cout << "Change color, from->to : " << myColor << "->" << c << endl;
	myColor = c;
	switch (c)
	{
		case BLACK:
			myR = 0;
			myG = 0;
			myB = 0;
			break;

		case BLUE:
			myR = 0;
			myG = 0;
			myB = 1;
			break;
		case GREEN:			
			myR = 0;
			myG = 1;
			myB = 0;
			break;
		case CYAN:
			myR = 0;
			myG = 1;
			myB = 1;
			break;
		case RED:
			myR = 1;
			myG = 0;
			myB = 0;
			break;
		case MAGENTA:
			myR = 1;
			myG = 0;
			myB = 1;
			break;
		case BROWN:
			myR = 165 / 255;
			myG = 42 / 255;
			myB = 42 / 255;
			break;
		case LIGHTGRAY:
			myR = 211 / 255;
			myG = 211 / 255;
			myB = 211 / 255;
			break;
		case DARKGRAY:
			myR = 169 / 255;
			myG = 169 / 255;
			myB = 169 / 255;
			break;
		case LIGHTBLUE:
			myR = 173 / 255;
			myG = 216 / 255;
			myB = 230 / 255;
			break;
		case LIGHTGREEN:
			myR = 144 / 255;
			myG = 238 / 255;
			myB = 144 / 255;
			break;
		case LIGHTCYAN:
			myR = 224 / 255;
			myG = 1;
			myB = 1;
			break;
		case LIGHTRED:
			myR = 1;
			myG = 69 / 255;
			myB = 0;
			break;
		case YELLOW:
			myR = 1;
			myG = 1;
			myB = 0;
			break;

		case WHITE:
			myR = 1;
				myG = 1;
				myB = 1;
				break;
	}

}

