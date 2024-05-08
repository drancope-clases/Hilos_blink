
#include "clase.h"
extern void interrupcion1(Led *t);

Led::Led(int ti) {
    tiempo = ti;
    estado = false;
    ventana = creaVentana();
    gladLoadGL(glfwGetProcAddress);
    glfwMakeContextCurrent(ventana);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.8,.1,0.1,0);
    glfwSwapBuffers(ventana);
    glfwPollEvents();
    later later_int1(this, true, &interrupcion1, this);
}

