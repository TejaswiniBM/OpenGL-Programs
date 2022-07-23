#include<stdio.h>
#include<iostream>
#include "glut.h"
#define base 111
using namespace std;

int r1 = 30, r2 = 50;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glNewList(base, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		for (int i = 0; i <= 360; i = i++)
		{
			glVertex2f(r1 * cos(i), r1 * sin(i));
			glVertex2f(r2 * cos(i), r2 * sin(i));
		}
	}
	glEnd();
	glEndList();
	glCallList(base);
	glFlush();
}


int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Letter O");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}