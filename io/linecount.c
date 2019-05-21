#include <stdio.h>

int countLines()
{
  int c, cnt = 0;

  for(;(c = getchar()) != EOF;)
    if (c == '\n') // single quotes represents int value equal to char
      cnt++;
  
  printf("%d\n",cnt);

  return cnt;
}

int main()
{
  countLines();
  return 0;
}