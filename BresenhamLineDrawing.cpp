#include<stdio.h>
#include<math.h>
#include<glut.h>

void setpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void Bresenham(int xx, int yy, int xf, int yf)
{
    int p, x, y;
    if (xx > xf)
    {
        x = xf;
        y = yf;
        xf = xx;
        yf = yy;
    }
    else
    {
        x = xx;
        y = yy;
    }

    int dx = fabs(xf - xx);
    int dy = fabs(yf - yy);
    if (dx > dy)
    {
        p = (2 * dy) - dx;
        setpixel(x, y);
        while (x < xx)
        {
            x++;
            if (p < 0)
            {
                p += (2 * dy);
            }
            else
            {
                y++;
                p = p + (2 * (dy - dx));
            }
            setpixel(x, y);
        }
    }
    else {
        p = (2 * dx) - dy;
        setpixel(x, y);
        while (y < yy)
        {
            y++;
            if (p < 0)
            {
                p = p + (2 * dx);
            }
            else
            {
                x++;
                p += (2 * (dx - dy));
            }
            setpixel(x, y);
        }
    }
 
}
void display()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glViewport(300, 300, 100, 100);
    Bresenham(80,80,10,10);
    glFlush();
}

void myinit()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham");
    myinit();
    glutDisplayFunc(display);
    
    glutMainLoop();
}