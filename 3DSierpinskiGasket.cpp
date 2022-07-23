 #include<glut.h>
float v[4][3] = { {-0.5,-0.25,0}, {0,0.5,0},{0.5,-0.25,0},{0,0,0.25} };
int n = 2;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void draw_tri(float* a, float* b, float* c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	glFlush();
}
void draw_tetra(float* a, float* b, float* c, float* d)
{
	glColor3f(1, 0, 0);
	draw_tri(a, b, c);
	glColor3f(1, 1, 0);
	draw_tri(a, b, d);
	glColor3f(1, 0, 1);
	draw_tri(b, c, d);
	glColor3f(0, 1, 1);
	draw_tri(a, d, c);
	glFlush();
}
void divide_tetra(float* a, float* b, float* c, float* d, int n)
{
	float ab[3], bc[3], ac[3], bd[3], cd[3], ad[3];
	if (n > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			ab[i] = (a[i] + b[i]) / 2;
			bc[i] = (c[i] + b[i]) / 2;
			ac[i] = (a[i] + c[i]) / 2;
			bd[i] = (d[i] + b[i]) / 2;
			cd[i] = (c[i] + d[i]) / 2;
			ad[i] = (a[i] + d[i]) / 2;
		}
		divide_tetra(a, ab, ac, ad, n - 1);
		divide_tetra(ab, b, bc, bd, n - 1);
		divide_tetra(ac, bc, c, cd, n - 1);
		divide_tetra(bd, ad, cd, d, n - 1);
	}
	else
		draw_tetra(a, b, c, d);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	divide_tetra(v[0], v[1], v[2], v[3], n);
	glFlush();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sierpinski Gasket");
	myinit();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}