#include "ventana.h"
#include "hilos.h"


int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  Timer t1;
  Timer t2;
  initVentanas();
  t1.ventana = creaVentana(50, 50);
  t1.setInterval(blink, 1000);
  t2.ventana = creaVentana(120,50);
  t2.setInterval(blink, 1200);
  do {
    printf("hola");
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  } while MANTENER_ABIERTO;

  glfwTerminate();
}
