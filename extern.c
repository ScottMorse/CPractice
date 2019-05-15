#include <stdio.h>

// Success, declare & define, then assign value
// int var;
// int main(void){
//   var = 10;
//   printf("%d", var);
//   return 0;
// }

// Success, declare and never allocate or use at all
// extern int var;
// int main(void){
//   return 0;
// }

// Failure, no defined symbol for var, never allocated
// extern int var;
// int main(void){
//   var = 10;
//   printf("%d",var);
//   return 0;
// }

// Success, var defined in ./extern.h
// #include "extern.h"
// extern int var;
// int main(void){
//   var = 10;
//   printf("%d",var);
//   return 0;
// }

//Success with warning, defines before intializing
extern int var = 10;
int main(void){
  printf("%d",var);
  return 0;
}