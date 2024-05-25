#include <stdio.h>
#include "/usr/include/GL/glut.h"

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    for(float x= 0; x<100;x+=2)
        for(float y =0;y<600;y+=2)
            glVertex2f(x,y);
    for(float x=100;x<200;x+=2)
        for(float y=0;y<100;y+=2){
            glVertex2f(x,y+200);
            glVertex2f(x,y+500);
        }
    for(float x=150;x<250;x+=2)
        for(float y=300;y<500;y+=2)
            glVertex2f(x,y);

    for(float x =150;x<250;x+=2)
        for(float y=200;y>250-x ;y-=2)
            glVertex2f(x,y);

    for(float x = 300;x<375;x+=2)
        for(float y=0;y<600;y+=2)
            glVertex2f(x,y);

    for(float x=300;x<500;x+=2)
        for(float y=598;y>700-x;y-=2){
            float o = x-400;
            if(y> 550-o){
                continue;
            }
            glVertex2f(x,y);
        }
    for(float x=500;x<575;x+=2)
        for(float y=0;y<600;y+=2)
            glVertex2f(x,y);

    for(float x=625;x<700;x+=2)
        for(float y=0;y<600;y+=2)
            glVertex2f(x,y);

    for(float x=700;x<900;x+=2)
        for(float y=598;y>1000-x;y-=2){
            float o = x-700;
            if(y> 550-o){
                continue;
            }
            glVertex2f(x,y-200);
        }

    for(float x=700;x<900;x+=2)
        for(float y=300;y<600;y+=2){
            if(y>x-300){
                continue;
            }
            glVertex2d(x,y);
        }

    for(float x=1000;x<1300;x+=2)
        for(float y=0;y<100;y+=2){
            glVertex2f(x,y);
            glVertex2f(x,y+200);
            glVertex2f(x,y+500);
        }
    for(float x=1000;x<1100;x+=2)
        for(float y=300;y<600;y+=2)
            glVertex2f(x,y);
    
    for(float x=1200;x<1300;x==2)
        for(float y=100;y<300;y+=2)
            glVertex2f(x,y);
    
    glEnd();
    glFlush();
}
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1400,-100,700);
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