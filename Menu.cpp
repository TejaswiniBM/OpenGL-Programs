#include "glut.h"
#include<stdio.h>
#include<stdlib.h>
int size = 2;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}
void demo_menu(int id)
{
	switch (id)
	{
	case 1: exit(0); break;
	case 2:if (size > 1)
		size *= 2; break;
	case 3:if (size > 1)
		size /= 2; break;
	}
	glutPostRedisplay();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-10*size, -10*size);
	glVertex2f(10 * size, -10 * size);
	glVertex2f(10 * size, 10 * size);
	glVertex2f(-10 * size, 10 * size);
	glEnd();
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Menu");
	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(demo_menu); 
	glutAddMenuEntry("Quit", 1);
	glutAddMenuEntry("Increase Square Size", 2);
	glutAddMenuEntry("Decrease Square Size", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
