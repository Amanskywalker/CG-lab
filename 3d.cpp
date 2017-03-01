#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

int n=0,j=0;
GLfloat v[4][3]={{0,1,-1},{1,-1,-1},{0,0,1},{-1,-1,-1}};

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
    glColor3f(1,0,0);
    glVertex2fv(a);
    glColor3f(0,1,0);
    glVertex2fv(b);
    glColor3f(0,0,1);
    glVertex2fv(c);
}

void tertrahedron(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
    glColor3f(0.5,0.5,0);
    triangle(a,b,c);
    glColor3f(1,1,0);
    triangle(a,d,c);
    glColor3f(0,0.5,0.5);
    triangle(b,d,c);
    glColor3f(0,1,1);
    triangle(c,b,a);
}

void divide_tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
    GLfloat mid[6][3];
    if(m>0)
    {
        for (j = 0; j < 3; ++j)
        {
            mid[0][j]=(a[j]+b[j])/2;
            mid[1][j]=(b[j]+d[j])/2;
            mid[2][j]=(a[j]+d[j])/2;
            mid[3][j]=(a[j]+c[j])/2;
            mid[4][j]=(d[j]+c[j])/2;
            mid[5][j]=(b[j]+c[j])/2;
        }
        divide_tetra(a,mid[0],mid[2],mid[3],m-1);
        divide_tetra(b,mid[0],mid[1],mid[5],m-1);
        divide_tetra(c,mid[4],mid[3],mid[5],m-1);
        divide_tetra(d,mid[1],mid[2],mid[4],m-1);
    }
    else
        tertrahedron(a,b,c,d);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        divide_tetra(v[0],v[1],v[2],v[3],n);
    glEnd();
    glFlush();
}

void myinit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glClear(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,-1.0,1.0,-1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{   glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("3D recursive gasket");
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
