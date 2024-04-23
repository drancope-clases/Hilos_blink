#include <unistd.h>
#include <cstdio>
#include "config.h"

#ifdef VENTANA
  #include "ventana.h"
#else
bool estado = 0;

void blink() {
    printf("%d",estado);
    estado = !estado;
}
#endif

int main(int argc, char **argv) {
#ifdef VENTANA
  initGlut(argc, argv);
#endif

  setbuf(stdout, NULL);
  for(;1;) {
    blink();
    sleep(1);
    printf("hola");
  }
}
