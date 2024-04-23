#include <unistd.h>
#include <cstdio>
#include "config.h"
#include <chrono>

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
  using namespace std::chrono;
  time_point antes = high_resolution_clock::now();
 
  setbuf(stdout, NULL);
  for(;1;) {
    time_point ahora   = high_resolution_clock::now();
    auto mseconds = duration_cast<milliseconds>(ahora - antes).count();
    if (mseconds > 1000) {
      	blink();
        antes = ahora;
    }

    printf("hola");
  }
}
