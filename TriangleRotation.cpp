#include<math.h>
#include<glut.h>
float p1[3][2] = { {20,40},{40,60},{60,40} };
float p2[3][2];
int xp = 20, yp = 40;
float t = 3.14 / 2;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}
void draw_tri(float p[3][2], int n)
{
	glBegin(GL_POLYGON);
	glVertex2fv(p[0]);
	glVertex2fv(p[1]);
	glVertex2fv(p[2]);
	glEnd();
	glFlush();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	draw_tri(p1, 3);
	for (int i = 0; i < 3; i++)
	{
		p2[i][0] = p1[i][0] * cos(t) - p1[i][1] * sin(t) - xp * cos(t) + yp * sin(t) + xp;
		p2[i][1] = p1[i][0] * sin(t) + p1[i][1] * cos(t) - xp * sin(t) - yp * cos(t) + yp;
	}
	glColor3f(0, 0, 1);
	draw_tri(p2, 3);
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Roatation of triangle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}