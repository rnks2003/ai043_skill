#include <stdio.h>
#include "/usr/include/GL/glut.h"
char i=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glBegin(GL_POINTS);
    for(float x=250.0;x<500;x+=2)
        for(float y=0.0;y<250;y+=2){
            if(x+y < 400 && x-y > 100){
                glColor4f(1.0,0.0,0.0,0.5);
            }
            else if(x+y < 570 && x-y > 0){
                glColor4f(0.0,1.0,0.0,0.5);
            }
            else{
                glColor4f(0.0,0.0,1.0,0.5);
            }
            glVertex2f(x+y,y);
            glVertex2f(x-y,y);

        }
    glEnd();
    glFlush();
}
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,-100,300);
}
void main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000,500);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Dot");
    init();

    glutDisplayFunc(display);
    glutMainLoop();
}