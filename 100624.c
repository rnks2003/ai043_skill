#include <GL/glut.h>

static int spinning = 1;
static const int FPS = 1000;

static GLfloat currentAngleOfRotation = 0.0;

void reshape(GLint w, GLint h){
    glViewport(0,0,w,h);
    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        glOrtho(-50.,50.,-50./aspect,50./aspect,-1.,1.);
    }else{
        glOrtho(-50./aspect,50./aspect,-50.,50.,-1.,1.);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(currentAngleOfRotation,0.,0.,1.);
    glRectf(-2.,-2.,2.,2.);
    glFlush();
    glutSwapBuffers();
}

void timer(int v){
    if(spinning){
        currentAngleOfRotation +=1.0;
        if(currentAngleOfRotation>360.){
            currentAngleOfRotation-=360.;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000/FPS,timer,v);
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        spinning = 1;
    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        spinning = 0;
    }
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(80,80);
    glutCreateWindow("Spining square");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);
    glutMouseFunc(mouse);
    glutMainLoop();
}