#include "ventana.h"
#include <iostream>

void blink(bool *estado, GLFWwindow *ventana) {
    glfwMakeContextCurrent(ventana);
    if (*estado) {
	    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    glClearColor(0.1,.8,0.11,0);
	    glfwSwapBuffers(ventana);
        //glfwPollEvents();
    } else {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glClearColor(0.1,0.1,0.1,0);
	    glfwSwapBuffers(ventana);
        //glfwPollEvents();
    }
    *estado = !*estado;
}

void initGlfw() {
    if (!glfwInit())
    {
    std::cout << "Fallo al iniciar Glfw\n";
    }
 
}
/*
void initGlut(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(100, 80);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Blink");
    glutDisplayFunc(blink);
}*/
GLFWwindow* creaVentana() {
    GLFWwindow* window = glfwCreateWindow(140, 80, "My Title", NULL, NULL);
    if (!window)
    {
        printf("Fallo al crear ventana.\n");
        // Window or OpenGL context creation failed
        return 0;
    }
    glfwMakeContextCurrent(window);
    //gladLoadGL(glfwGetProcAddress);
    //printf("Ventana creada. Devolviendo valor.\n");    
    return window;
}
