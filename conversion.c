#include <stdio.h>

/* 
  printf: 
  %d int
  %f float
  %o octal
  %x hexadecimal
  %c char
  %s string
  %% %
*/

/* 
  The reason these constants don't
  have type declarations is
  because they are "replacement text",
  not typed values
*/

#define LOWER 0
#define UPPER 300
#define STEP 20

int intFahrToCelcius(int fahr){
  /* Division truncates for ints, 
      so (fahr - 32) * (5/9) isnt used,
      since 5/9 it will truncate to 0 */
  return 5 * (fahr - 32) / 9;
}

/* to get a float from an operation,
 one or both numbers must be a float */
float floatFahrToCelcius(float fahr){
  return (5. / 9.) * (fahr - 32.);
}

int main(){
  float fahr, celsius;

  fahr = LOWER;

  while (fahr <= UPPER) {

    celsius = floatFahrToCelcius(fahr);

    printf("%5.2f \t %5.2f\n", fahr, celsius);

    fahr = fahr + STEP;
  }

  return 0;
}