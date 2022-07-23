//ratation about fixed point
#include<stdio.h>
#include<glut.h>
float px, py, r;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}
void draw_tr()
{
	glBegin(GL_TRIANGLES);
	{
		
		glVertex2f(40, 40);
		glVertex2f(60, 60);
		glVertex2f(80, 40);
	}
	glEnd();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	draw_tr();
	glLoadIdentity();
	glTranslatef(px, py, 0);
	glRotatef(r, 0, 0, 1);
	glTranslatef(-px, -py, 0);
	glColor3f(1, 0, 0);
	draw_tr();
	glFlush();
}

int main(int argc, char** argv)
{
	printf("Enter the fixed point:");
	scanf_s("%f %f", &px, &py);
	printf("Enter theta value:");
	scanf_s("%f", &r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Create and Rotate Triangle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}