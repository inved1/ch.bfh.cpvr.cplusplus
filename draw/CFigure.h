#pragma once


enum ColorType{
	BLACK, 
	BLUE, 
	GREEN, 
	CYAN, 
	RED, 
	MAGENTA, 
	BROWN, 
	LIGHTGRAY, 
	DARKGRAY,
	LIGHTBLUE, 
	LIGHTGREEN, 
	LIGHTCYAN, 
	LIGHTRED, 
	LIGHTMAGENTA, 
	YELLOW, 
	WHITE
};


class CFigure
{
protected:
	char* myName;
	ColorType myColor;
	float myX, myY;
	float myR, myG, myB;


public:
	//CFigure(void);
	CFigure(float x = 0.0, float y = 0.0, ColorType c = ColorType(0));


	virtual ~CFigure();

	void changeColor(ColorType c);


	virtual void draw() const = 0;

	virtual void erase() const = 0;




};

