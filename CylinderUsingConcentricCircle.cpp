#include<stdio.h>
#include<math.h>
#include<iostream>
#include "glut.h"

using namespace std;

int r, xc, yc, x, y;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);
	glMatrixMode(GL_MODELVIEW);
}
void plot(int x, int y)
{
	glColor3f(1, 0, 0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void circle(int xc, int yc, int r)
{
		for (int i =0 ; i < 360; i++)
		{
			x = xc+ (r*cos(i));
			y = yc+(r*sin(i));
			plot(x, y);
		}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 20; i++)
	{
		circle(i,i,r);
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Enter radius ";
	cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Concentric Circle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}