#include <fcntl.h>
#include <errno.h>
#include <err.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#ifndef MAP_FILE
#define MAP_FILE MAP_SHARED
#endif
int fsize(int fd) {
  struct stat stat;
  int res = fstat(fd,&stat);
  return stat.st_size;
}
int printll(char* s) {
  while (*s != '\n' && *s != ',' && *s != '\t') {
    putchar(*s++);
  }
  return 0;
}
long hash(char *str0, int len)
{
  unsigned char* str = (unsigned char*)str0;
  unsigned long hash = 5381;
  int c;
  while ((c = *str++) && len--)
  hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash;
}
void Snippet(char*);
int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("usage: query <filename>\n");
    return 0;
  }
  Snippet(argv[1]);
  return 0;
}
/*****************************************
Emitting C Generated Code
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void Snippet(char* x0) {
  printf("%s\n", "Name");
  int x2 = open("src/data/t.csv",0);
  int x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  int x5 = 0;
  while (x4[x5] != ',') ({
    x5 = x5 + 1;
  });
  x5 = x5 + 1;
  int x9 = 0;
  while (x4[x5] != ',') ({
    x9 = x9 * 10 + (int)(x4[x5] - '0');
    x5 = x5 + 1;
  });
  x5 = x5 + 1;
  while (x4[x5] != '\n') ({
    x5 = x5 + 1;
  });
  x5 = x5 + 1;
  while (x5 < x3) ({
    int x15 = x5;
    while (x4[x5] != ',') ({
      x5 = x5 + 1;
    });
    x5 = x5 + 1;
    int x18 = 0;
    while (x4[x5] != ',') ({
      x18 = x18 * 10 + (int)(x4[x5] - '0');
      x5 = x5 + 1;
    });
    x5 = x5 + 1;
    int x21 = x5;
    while (x4[x5] != '\n') ({
      x5 = x5 + 1;
    });
    int x23 = x5 - x21;
    x5 = x5 + 1;
    ((x23 == 3 && ({
      char* x24 = x4 + x21;
      int x25 = 0;
      while (x25 < x23 && x24[x25] == "yes"[x25]) ({
        x25 = x25 + 1;
      });
      x25 == x23;
    })) ? ({
      printll(x4 + x15);
      printf("%s\n", "");
    }) : ({}));
  });
  close(x2);
}
/*****************************************
End of C Generated Code
*******************************************/
