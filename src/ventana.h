#include "../include/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
 
#include <unistd.h>
#include "config.h"

void blink(bool *estado, GLFWwindow* ventana);
void initGlfw();
//void initGlut(int argc, char **argv);
GLFWwindow* creaVentana();