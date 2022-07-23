#include<stdio.h>
#include<math.h>
#include<iostream>
#include "glut.h"

using namespace std;
int w = 500, h = 500;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}
void myReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)w, 0, (GLdouble)h);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0,100);
	glVertex2f(100, 100);
	glVertex2f(100, 0);
	glEnd();
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Square");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}