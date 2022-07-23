#include<glut.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100, -100, 200);
	glMatrixMode(GL_MODELVIEW);
}
void draw()
{
	glPushMatrix();//leg 1
	glColor3f(1, 1, 0);
	glTranslatef(-35, -10, 80);
	glScalef(5, 50, 5);//for legs y scaling
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();//leg 2
	glColor3f(1, 1, 0);
	glTranslatef(60, -10, 80);
	glScalef(5, 50, 5);//for legs y scaling
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();//leg 3
	glColor3f(1, 1, 0);
	glTranslatef(33, -40, -80);
	glScalef(5, 50, 5);//for legs y scaling
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();//leg 4
	glColor3f(1, 1, 0);
	glTranslatef(-55, -35, -80);
	glScalef(5, 50, 5);//for legs y scaling
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();//teapot
	glTranslatef(5,20,30);
	glutSolidTeapot(15);
	glPopMatrix();

	glPushMatrix();//table top
	glScalef(100,5,100);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();//floor
	glTranslatef(-40, -90, -100);
	glScalef(200, 1, 300);
	glutSolidCube(1);
	glPopMatrix();
}
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//GLfloat light_int[] = { 0.1,0.2,0.2,1 };
	//GLfloat lightpos[] = { 100,100,100 };
	//glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_int);
	//GLfloat mat_ambient[] = { .7,.7,.7,1 };
	//GLfloat mat_diffuse[] = { .5,.5,.5,1 };
	//GLfloat mat_shininess[] = { 50 };
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLoadIdentity();
	gluLookAt(10, 10, 30, 0, 0, 5, 0, 10, 0);
	glMatrixMode(GL_MODELVIEW);
	draw();
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scene");
	myinit();
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}