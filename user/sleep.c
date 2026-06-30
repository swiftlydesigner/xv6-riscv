#include "kernel/types.h"
#include "user/user.h" // fprintf exit atoi pause

void sleep(int n) {
  pause(n * 10);
}

int main(int argc, char* argv[]) {

  if (argc != 2) {
    fprintf(2,"Usage: sleep TIME\n");
    exit(1);
  }

  sleep(atoi(argv[1]));

  exit(0);
}
