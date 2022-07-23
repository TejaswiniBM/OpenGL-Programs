#include<stdio.h>
#include<glut.h>

double xmin = 50, ymin = 50,xmax = 100, ymax = 100;
double xvmin = 200, yvmin = 200, xvmax = 300, yvmax = 300;
const int right = 2;
const int left = 1;
const int top = 8;
const int bottom = 4;
int x1 = 60, y1 = 60, x2 = 120, y2 = 120;

#define outcode int

outcode computeoutcode(double x, double y)
{
	outcode code = 0;
	if (y > ymax)
		code |= top;
	else if (y < ymin)
		code |= bottom;
	if (x > xmax)
		code |= right;
	else if (x < xmin)
		code |= left;
	return code;
}

void cohen(double x0, double y0, double x1, double y1)
{
	outcode op1, op2, op3;
	bool accept = false, done = false;
	op1 = computeoutcode(x0, y0);
	op2 = computeoutcode(x1, y1);

	do {
		if (!(op1 | op2))
		{
			done=true;accept=true;
		}
		else if(op1&op2)
			done=true;
		else
		{
			double x, y;
			op3 = op1 ? op1 : op2;
			if (op3 & top)
			{
				y = ymax;
				x = x0 + ((x1 - x0) * (ymax - y0)) / (y1 - y0);
			}
			else if (op3 & bottom)
			{
				y = ymin;
				x = x0 + ((x1 - x0) * (ymin - y0)) / (y1 - y0);
			}
			if (op3 & right)
			{
				x = xmax;
				y = y0 + ((y1 - y0) * (xmax - x0)) / (x1 - x0);
			}
			else if (op3 & left)
			{
				x = xmin;
				y = y0 + ((y1 - y0) * (xmin - x0)) / (x1 - x0);
			}

			if (op3 == op1)
			{
				x0 = x; y0 = y;
				op1 = computeoutcode(x0, y0);
			}
			else
			{
				x1 = x; y1 = y;
				op2 = computeoutcode(x1, y1);
			}
		}
	} while (!(done));

	if (accept)
	{
		double sx, sy, vx0, vy0, vx1, vy1;
		sx = (xvmax - xvmin) / (xmax - xmin);
		sy = (yvmax - yvmin) / (ymax - ymin);

		vx0 = xvmin + (x0 - xmin) * sx;
		vy0 = yvmin + (y0 - ymin) * sy;
		vx1 = xvmin + (x1 - xmin) * sx;
		vy1 = yvmin + (y1 - ymin) * sy;

		glColor3f(1, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2d(xvmin, yvmin);
		glVertex2d(xvmax, yvmin);
		glVertex2d(xvmax, yvmax);
		glVertex2d(xvmin, yvmax);
		glEnd();
		// draws blue colour viewport
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex2d(vx0, vy0);
		glVertex2d(vx1, vy1);
		glEnd();
	}
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();

	// draw blue coloured window
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();
	cohen(x1, y1, x2, y2);
	glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}


void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}