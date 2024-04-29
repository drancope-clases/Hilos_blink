#include "ventana.h"
#include "hilos.cpp"


//bool estado = 0;

int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  initVentanas();
  Timer t1 = Timer();
  t1.setInterval(blink, 1000);
  t1.window = creaVentana();
  do {
    printf("hola");
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  } while MANTENER_ABIERTO;

  glfwTerminate();
}
