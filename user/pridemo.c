#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  set_priority(95);

  int child = fork();

  if (child == 0) {
    set_priority(5);
  }

  for (int v = 100; v > 0; --v) {
    sleep(2);
    write(1, child == 0 ? "L" : "H", 1);
  }

  exit(0);
}
