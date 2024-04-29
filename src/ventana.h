#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>
#include <GL/glx.h>

#define MANTENER_ABIERTO ( glfwGetKey(t1.window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(t1.window) == 0 )

void blink(bool estado, GLFWwindow* window);
int initVentanas();
GLFWwindow* creaVentana();