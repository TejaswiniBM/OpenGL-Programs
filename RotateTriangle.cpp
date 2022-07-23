#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
GLfloat p[3][2] = { {40,40}, {60, 60}, {80, 40} };
GLfloat p1[3][2] = { {0},{0},{0} };
//GLfloat p1[2][2] = { {0},{0} };
GLfloat theta,px,py;

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
	glColor3f(1, 0, 0);//initially red
	glBegin(GL_POLYGON);
	glVertex2fv(p[0]);
	glVertex2fv(p[1]);
	glVertex2fv(p[2]);
	glEnd();
	glLoadIdentity();
	glColor3f(0, 0, 1);//after rotation blue
	for (int i = 0; i < 3; i++)
	{
		p1[i][0] = (p[i][0] * cos(theta)) - (p[i][1] * sin(theta))- (px * cos(theta)) + (py * sin(theta))+px;
		p1[i][1] = (p[i][0] * sin(theta)) - (p[i][1] * cos(theta))- (px * sin(theta)) - (py * cos(theta))+py;
	}
	glBegin(GL_POLYGON);
	glVertex2fv(p1[0]);
	glVertex2fv(p1[1]);
	glVertex2fv(p1[2]);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	printf("Enter the rotation angle: ");
	scanf_s("%f", &theta);
	printf("Enter the fixed point:");
	scanf_s("%f %f", &px, &py);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Triangle Rotation about a fixed point");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
/*only rotation
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
GLfloat p[3][2] = { {40,40}, {60, 60}, {80, 40} };
GLfloat p1[3][2] = { {0},{0},{0}};
//GLfloat p1[2][2] = { {0},{0} };
GLfloat theta;

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
	glColor3f(1, 0, 0);//initially red
	glBegin(GL_POLYGON);
	glVertex2fv(p[0]);
	glVertex2fv(p[1]);
	glVertex2fv(p[2]);
	glEnd();
	glLoadIdentity();
	glColor3f(0, 0, 1);//after rotation blue
	for (int i = 0; i < 3; i++)
	{
		p1[i][0] = (p[i][0] * cos(theta)) - (p[i][1] * sin(theta));
		p1[i][1] = (p[i][0] * sin(theta)) - (p[i][1] * cos(theta));
	}
	glBegin(GL_POLYGON);
		glVertex2fv(p1[0]);
		glVertex2fv(p1[1]);
		glVertex2fv(p1[2]);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	printf("Enter the rotation angle: ");
	scanf_s("%f", &theta);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Triangle Rotation");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
*/
