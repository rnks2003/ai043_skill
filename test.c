#include <stdio.h>
#include "/usr/include/GL/glut.h"

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2d(10.0,20.0);
    glEnd();
    glFlush();
}
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400,400,-400,400);
}
void main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400,300);
    glutInitWindowPosition(0,0);

    glutCreateWindow("Dot");
    init();

    glutDisplayFunc(display);
    glutMainLoop();
}