#include<stdio.h>
#include<iostream>
#include "glut.h"
#define box 22
#define triangle 24
using namespace std;


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
	glNewList(box, GL_COMPILE);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();
	glEndList();
	glCallList(box);
	glColor3f(0,1, 0);
	glNewList(triangle, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	glVertex2f(-100, 100);
	glVertex2f(0, -100);
	glVertex2f(100, 100);
	glEnd();
	glEndList();
	glCallList(triangle);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Display Lists");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}