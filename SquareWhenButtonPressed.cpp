#include<stdio.h>
#include<math.h>
#include<iostream>
#include "glut.h"

using namespace std;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void mymouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		
		glColor3f(1, 0, 0);
		x = x;
		y = 500 - y;
		glBegin(GL_POLYGON);
		glVertex2f(x,y);
		glVertex2f(x, y -100);
		glVertex2f(x +100, y -100);
		glVertex2f(x + 100, y);
		glEnd();
		glFlush();
	}
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
		exit(0);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Square");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutMainLoop();
}