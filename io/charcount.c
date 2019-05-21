#include <stdio.h>

// void countInput()
// {
//   long nc;

//   nc = 0;

//   while(getchar() != EOF)
//     ++nc;

//   printf("%ld\n", nc);
// }

long countInput()
{
  long nc;

  for(nc = 0; getchar() != EOF; ++nc)
    ;
  
  printf("%ld",nc);

  return nc;
}

int main()
{
  countInput();

  return 0;
}