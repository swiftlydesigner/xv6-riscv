#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  set_priority(95);

  int child = fork();

  if (child == 0) {
    set_priority(5);
    for (int v = 500; v > 0; --v) {
      write(1, "C", 1);
    }
    exit(0);
  }

  for (int v = 500; v > 0; --v) {
    write(1, "P", 1);
  }

  wait(0);


  exit(0);
}
