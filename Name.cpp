#include<stdio.h>
#include<math.h>
#include<iostream>
#include<glut.h>
using namespace std;
char s[10] = "tejaswini";
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
}
void output(int x, int y, char* s)
{
	int len, i;
	glRasterPos2f(x, y);
	len = int(strlen(s));
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);

	for (i = 1; i < len; i++)
	{
		glRasterPos2f(x, y - (i * 20));
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
	}
	for (i = 1; i < len; i++)
	{
		glRasterPos2f(x + (i * 20), y + (i * 20));
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
	}

}

void display()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	output(5, 50, s);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Name");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}