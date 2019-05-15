#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashmap.h"

#define INITIAL_SIZE (256)
#define CHAR_MAX (8)

// create new type of struct with string, int, and any value
typedef struct _hashmap_el{
  char* key;
  int in_use;
  void* value;
} hashmap_el;

typedef struct _hashmap_map {
  int table_size;
  int size;
  hashmap_el *data;
} hashmap_map;

// Return null if failure
HashMap new_hashmap(){
  hashmap_map* m = (hashmap_map*) malloc(sizeof(hashmap_map));
  if(!m) goto err;

  m->data = (hashmap_el*) calloc(INITIAL_SIZE, sizeof(hashmap_el));
  if(!m->data) goto err;

  m->table_size = INITIAL_SIZE;
  m->size = 0;

  return m;

  // return null if failure and free hashmap
  err:
      if(m)
          hashmap_free(m);
      return NULL;
}

int main(){
  printf("%d",5);
  return 0;
}