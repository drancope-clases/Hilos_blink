#include "ventana.h"
#include <glm/glm.hpp>

using namespace glm;

int initVentanas() {
	if( !glfwInit() ) {
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

GLFWwindow* creaVentana(/*int px, int py*/){
	GLFWwindow *window = glfwCreateWindow( 224, 168, "LED", NULL, NULL);
	if( window == NULL ) {
		fprintf( stderr, "Fallo al abrir ventana GLFW.\n" );
		getchar();
		glfwTerminate();
		return NULL;
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwMakeContextCurrent(window);
    return window;
}
bool estado= false;
void blink(/*bool estado, GLFWwindow* window*/) {
  printf("entra en blink\n");
  if (estado) {
	glClearColor(0.0, 0.8, 0.4, 0.0);
	glClear( GL_COLOR_BUFFER_BIT );
	glfwSwapBuffers(window);
	glfwPollEvents();
  } else {
	glClearColor(0.0, 0.0, 0.4, 0.0);
	glClear( GL_COLOR_BUFFER_BIT );
	glfwSwapBuffers(window);
	glfwPollEvents();
  }
  estado = !estado;
}
