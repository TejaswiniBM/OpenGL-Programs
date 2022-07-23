#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <glut.h>
int size = 1;
int s1, s2, s3;
int flag = 1; // 2 square  1 triangle 3 circle
int colorf = 1;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);
	glMatrixMode(GL_MODELVIEW);
}
void size_sub_menu(int id)
{
	switch (id)
	{
	case 1://if (size >= 1) // logical error 
		//size *= 2;
		glScaled(2.0f,2.0f,2.0f);
		break;
	case 2://if (size >= 1)
		//size /= 2; 
		glScaled(0.5f, 0.5f, 0.5f); 
		break;
	}
	glutPostRedisplay();
}
void color_sub_menu(int id)
{
	switch (id) {
	case 3:
		colorf = 1;
		break;
	case 4:
		colorf = 2;
		break;
	case 5:
		colorf = 3;
		break;
	}
	glutPostRedisplay();
}
void draw_square()
{

	glBegin(GL_POLYGON);
	glVertex2f(-10 * size, -10 * size);
	glVertex2f(10 * size, -10 * size);
	glVertex2f(10 * size, 10 * size);
	glVertex2f(-10 * size, 10 * size);
	glEnd();
	glFlush();
}
void draw_circle()
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex2f((size + 10) * cos(i), (size + 10) * sin(i));
	}
	glEnd();
	glFlush();
}
void draw_triangle()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(-10*size, -10*size);
	glVertex2f(size *0, size*10);
	glVertex2f(10 * size, -10 * size);
	glEnd();
	glFlush();
}
void primitive_sub_menu(int id)
{
	switch (id)
	{
	case 6:flag = 1; break;
	case 7:flag = 2; break;
	case 8:flag = 3; break;
	}
	glutPostRedisplay();
}
void demo_menu(int id)
{
	switch (id)
	{
	case 0: exit(0); break;
	}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	switch (colorf)
	{
	case 1: glColor3f(1, 0, 0);
		break;
	case 2: glColor3f(0, 1, 0);
		break;
	case 3: glColor3f(0, 0, 1);
		break;

	}
	switch (flag)
	{
	case 1: draw_triangle(); break;
	case 2: draw_square(); break;
	case 3: draw_circle(); break;
	}

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

	s1 = glutCreateMenu(size_sub_menu);
	glutAddMenuEntry("Increase Size", 1);
	glutAddMenuEntry("Decrease Size", 2);

	s2 = glutCreateMenu(color_sub_menu);
	glutAddMenuEntry("Red", 3);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Blue", 5);

	s3 = glutCreateMenu(primitive_sub_menu);
	glutAddMenuEntry("Triangle", 6);
	glutAddMenuEntry("Square", 7);
	glutAddMenuEntry("Circle", 8);

	glutCreateMenu(demo_menu);
	glutAddSubMenu("Size", s1);
	glutAddSubMenu("Color", s2);
	glutAddSubMenu("Primitive", s3);
	glutAddMenuEntry("Quit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}