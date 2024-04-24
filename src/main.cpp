#include <unistd.h>
#include <cstdio>
#include "config.h"
#include <chrono>
#include "clase-later.cpp"
#include "ventana.h"

void interrupcion1(void)
{
    blink();
}

int main(int argc, char **argv) {
  initGlut(argc, argv);
  setbuf(stdout, NULL);

  later later_int1(1000, false, &interrupcion1);
 
  for(;1;) {
    printf("hola.");
  }
}
