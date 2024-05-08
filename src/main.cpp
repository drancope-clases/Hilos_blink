#include <unistd.h>
#include <cstdio>
#include "config.h"
#include <chrono>
#include "clase.h"

int main(int argc, char **argv) {
  initGlfw();
  setbuf(stdout, NULL);
  Led t1(1000);
  Led t2(800);
  for(;;) {
    printf("hola.");
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }
}
