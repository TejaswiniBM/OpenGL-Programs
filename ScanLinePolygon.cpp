#include<stdio.h>
#include<stdlib.h>
#include<glut.h>
int colorf = 1;
float x1 = 200, x2 = 400, x3 = 600, x4 = 400, y1 = 400, y2 = 200, y3 = 400, y4 = 600;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void draw_pixel(int x, int y)
{
	glPointSize(1.0); 
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

void demo_menu(int id)
{
	switch (id)
	{
	case 1: colorf = 1; break;
	case 2: colorf = 2; break;
	case 3: colorf = 3; break;
	case 4: exit(0); break;
	}
	glutPostRedisplay();
}

void edgedetect(float x1, float y1, float x2, float y2, int* le, int* re)
{
	float mx, x, temp; int i;
	if ((y2 - y1) < 0)
	{
		temp = y1; y1 = y2; y2 = temp;
		temp = x1; x1 = x2; x2 = temp;
	}
	if ((y2 - y1) != 0)
		mx = (x2 - x1) / (y2 - y1);
	else
		mx = (x2 - x1);

	x = x1;

	for (i = y1; i <= y2; i++)
	{
		if (x < (float)le[i])
			le[i] = (int)x;
		if (x > (float)re[i])
			re[i] = (int)x;

		x += mx;
	}
}

void scanline(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	int le[500], re[500];
	for (int i = 0; i < 500; i++)
	{
		le[i] = 500;
		re[i] = 0;
	}
	edgedetect(x1, y1, x2, y2, le, re);
	edgedetect(x2, y2, x3, y3, le, re);
	edgedetect(x3, y3, x4, y4, le, re);
	edgedetect(x4, y4, x1, y1, le, re);

	for (int y = 0; y < 500; y++)
	{
		if (le[y] <= re[y])
		{
			for (int i =(int)le[y]; i < (int)re[y]; i++)
			{
				draw_pixel(i, y);
			}
		}
	}
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	switch (colorf)
	{
	case 1: glColor3f(1, 0, 0); break;
	case 2: glColor3f(0, 1, 0); break;
	case 3: glColor3f(0, 0, 1); break;
	}
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanline(x1, y1, x2, y2, x3, y3, x4, y4);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scanline");

	glutCreateMenu(demo_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Quit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}