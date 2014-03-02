


#include <iostream>
#include "geom.h"

using namespace std;


int main(){

	float x1,y1,x2,y2,x3,y3 = 0.0;
	
	cout << "punkt 1 x eingeben" << endl;
	cin >> x1;
	cout << "punkt 1 y eingeben" << endl;
	cin >> y1;
	cout << "punkt 2 x eingeben" << endl;
	cin >> x2;
	cout << "punkt 2 y eingeben" << endl;
	cin >> y2;
	cout << "punkt 3 x eingeben" << endl;
	cin >> x3;
	cout << "punkt 3 y eingeben" << endl;
	cin >> y3;


	CPoint* oPoint1 = new CPoint(x1, y2);
	CPoint* oPoint2 = new CPoint(x2, y2);
	CPoint* oPoint3 = new CPoint(x3, y3);
	CLine* oLine1 = new CLine(*oPoint1, *oPoint2);
	CLine* oLine2 = new CLine(*oPoint2, *oPoint3);
	
	CRectangle* oRect1 = new CRectangle(*oPoint1, *oPoint2);
	CRectangle* oRect2 = new CRectangle(*oPoint2, *oPoint3);

	CCircle* oCircle1 = new CCircle(*oPoint1, x2);
	CCircle* oCircle2 = new CCircle(*oPoint2, x3);

	cout << "-------------------------------" << endl;
	cout << "Resultate: " << endl;
	cout << "L�nge Linie 1 - Punkt 1 -> Punkt 2 : " << oLine1->getLength() << endl;
	cout << "L�nge Linie 2 - Punkt 2 -> Punkt 3 : " << oLine2->getLength() << endl;
	cout << "-------------------------------" << endl;
	cout << "Fl�che Rect 1 - Punkt 1 (BotLeft) & Punkt 2 (TopRight) : " << oRect1->getArea() << endl;
	cout << "Fl�che Rect 2 - Punkt 2 (BotLeft) & Punkt 3 (TopRight) : " << oRect2->getArea() << endl;
	cout << "-------------------------------" << endl;
	cout << "Fl�che Circle 1 - Punkt 1 & Radius x1 : " << oCircle1->getArea() << endl;
	cout << "Fl�che Circle 2 - Punkt 2 & Radius x3 : " << oCircle2->getArea() << endl;



	system("pause");
	return 0;
}