#include "glut.h"
int id;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(25, 25);
	glVertex2f(75, 75);
	glEnd();
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("First");
	myinit();
	glutDisplayFunc(display);
	glutInitWindowPosition(250, 250);
	id = glutCreateWindow("Second");
	glutSetWindow(id);
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
