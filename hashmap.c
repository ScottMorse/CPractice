#include <stdio.h>

#define INITIAL_SIZE (256);
#define CHAR_MAX (8);

// create new type of struct with string, int, and any value
typedef struct _hashmap_el{
  char* key;
  int in_use;
  void* value;
} _hashmap_el;

typedef struct _hashmap_map {
  int table_size;
  int size;
  _hashmap_el *data;
} HashMap;



int main(){
  printf("%d",5);
  return 0;
}