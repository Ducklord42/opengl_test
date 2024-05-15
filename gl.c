#include <stdio.h>
#include <GL/glut.h>
#include <stdint.h>
#include <stdbool.h>

void displaymatrix(char *matrix, unsigned x, unsigned y)
{
    for (unsigned yy = 0; yy < 14; yy++)
    {
        for (unsigned xx = 0; xx < 10; xx++)
        {
            if (matrix[(yy * 10) + xx] == '1')
            {
                glVertex2i(x + xx, y - yy);
            }
        }
    }
}

//font numbers
char *t0 = "";
char *t1 = "00000000000000100000000110000000101000000100100000000010000000001000000000100000000010000000001000000000100000000010000011111111100000000000";
char *t2 = "";
char *t3 = "";
char *t4 = "";
char *t5 = "";
char *t6 = "";
char *t7 = "";
char *t8 = "";
char *t9 = "";

void numbertext(uint8_t num, unsigned x, unsigned y)
{
if (num == 1) {
    displaymatrix(t1, x, y);
}
}

void myInit()
{
    //background black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 0.0); //red in RGB

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //window res
    gluOrtho2D(-780, 780, -420, 420);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x, y, i;

    for (i = 0; i < 30; i++)
    {
        x = 100;
        y = i + 100;
        glVertex2i(x, y);
    }
    numbertext(1, 20, 20);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Maximum frames");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
