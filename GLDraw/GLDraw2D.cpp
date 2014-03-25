#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


#include "cDrawing.h"
#include "zpr.h"
#include "..\draw\CPoint.h"
#include "..\draw\CCircle.h"
#include "..\draw\CLine.h"
#include "..\draw\CRectangle.h"

#include "myGlobals.h"

using namespace std;



void setup(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void reshape(int w, int h){
	//set viewport size to whole openGL window (sonst ists nur ein ausschnit)
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);


}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	glutPostRedisplay();
}

void mouseControl(int btn, int state, int x, int y){
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		cout << "left btn pressed, x: " << x << " y: " << y << endl;
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP){
		cout << "left btn released, x: " << x << " y: " << y << endl;
	}
}

void mouseMotion(int x, int y)
{
	cout << "mouse move, x: " << x << " y: " << y << endl;
}

void keyInput(unsigned char key, int x, int y){
	switch (key){
	case 27:
		exit(0);
		break;
	case 112: // p , point
//		g_oDraw.addPoint(x, y);
	case 99: // c, circle

	case 114: //r, rectangle 

	case 108: // l, line

	default:
		break;
	}
}

void main(int argc, char *argv[]){

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello OpenGL");
	setup();
	zprInit();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyInput);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseControl);
	glutMotionFunc(mouseMotion);

	glutMainLoop();
	

	exit(EXIT_SUCCESS);

	
}