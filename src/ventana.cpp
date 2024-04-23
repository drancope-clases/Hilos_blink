#include <GL/glut.h>
#include "ventana.h"
#ifdef VENTANA
int estado =0;

void blink() {
    if (estado==0) {
	    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    glClearColor(0.1,.8,0.11,0);
	    glutSwapBuffers();
        estado = 1;
    } else {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glClearColor(0.1,0.1,0.1,0);
    	glutSwapBuffers();
        estado = 0;
    }
}

void initGlut(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(100, 80);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Blink");
    glutDisplayFunc(blink);
}
#endif
