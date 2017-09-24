# 1 "misc.c"
# 1 "/home/embeddedsystemsprogramming/Adigwe_Coursera/Week 3/m3//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "misc.c"
# 20 "misc.c"
# 1 "misc.h" 1
# 35 "misc.h"
int func(int * f1);
# 21 "misc.c" 2



int g5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int func(int * f1)
{
  static int f2;
  unsigned int f3 = 0;
  volatile char * f4 = "Hello World!\n";

  f2++;
  *(&g5[0] + f2) = f3;

  for (f3 = 0; f3 < (6); f3++)
  {
    g5[f3] = f4[f3];
    f2++;
  }

  return f2;
}
