#include<random>
#include<glut.h>

void myinit()
{
	glMatrixMode
	(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 50, 0, 50);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	float p[3][2] = { {10,10},{20,20},{30,10} };
	float rp[2] = { 15,15 };



	glLineWidth(5);
	glColor3f(1,0,0);

	for (int i = 0; i < 5000; i++)
	{
		int v = rand() % 3;
		rp[0] = (rp[0] + p[v][0]) / 2;
		rp[1] = (rp[1] + p[v][1]) / 2;

		glBegin(GL_POINTS);
		glVertex2f(rp[0], rp[1]);
		glEnd();
		glFlush();
	}

}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D Sierpinski Gasket");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();

}