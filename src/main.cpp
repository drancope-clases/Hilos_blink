#include "ventana.h"
#include "hilos.cpp"


//bool estado = 0;

int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  Timer t1 = Timer();
  initVentanas();
  t1.ventana = creaVentana(50, 50);
  t1.estado = false;
  t1.setInterval(blink, 1000);
  do {
    printf("hola");
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  } while MANTENER_ABIERTO;

  glfwTerminate();
}
