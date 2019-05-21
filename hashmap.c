#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashmap.h"
#include "crc32.h"

#define INITIAL_SIZE (256)
#define MAX_CHAIN_LENGTH (8)

// create new type of struct with string, int, and any value
typedef struct _hashmap_el{
  char* key;
  int in_use;
  any value;
} hashmap_el;

typedef struct _hashmap_map {
  int table_size;
  int size;
  hashmap_el *data; // pointer to element
} hashmap_map;

// Return null if failure
HashMap new_hashmap(){

  /* Memory Allocation

    malloc allocates block of memory and returns void pointer that can be cast to any type of pointer (hashmap_map*)
        "hashmap_map pointer m is declared and defined as a pointer
        for a new allocation of memory the size of a hashmap_map struct"

  */
  hashmap_map* m = (hashmap_map*) malloc(sizeof(hashmap_map));
  if(!m) goto err;

  /* Contiguous Allocation

    calloc dynamically allocates potentially multiple blocks of a type
     "The member data of m is a hashmap_el pointer to an address that
      is allocated INITIAL_SIZE number of hashmap_el's"

  */
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

unsigned int hashmap_hash_int(hashmap_map* m, char* keystring){

  unsigned long key = crc32((unsigned char*)(keystring), strlen(keystring));

  key += (key << 12);
  key ^= (key >> 22);
  key += (key << 4);
  key ^= (key >> 9);
  key += (key << 10);
  key ^= (key >> 2);
  key += (key << 7);
  key ^= (key >> 12);

  key = (key >> 3) * 2654435761;

  return key % m->table_size;
}

// returns hash index to place a key
int hashmap_hash(HashMap in, char* key){

  // get pointer for hashmap
  hashmap_map* m = (hashmap_map*) in;

  if(m->size >= (m->table_size/2)) return MAP_FULL;

  // finds good index
  int curr = hashmap_hash_int(m, key);

  // goes through data to find place to put key
  for(int i = 0; i < MAX_CHAIN_LENGTH; i++)
  {
    if(m->data[curr].in_use == 0)
      return curr;
    if(m->data[curr].in_use == 1 && ( strcmp(m->data[curr].key,key) == 0 ))
      return curr;
    curr = (curr + 1) % m->table_size;
  }
  return MAP_FULL;
}

// Reallocate size to double and rehash keys
int hashmap_rehash(HashMap in){
  hashmap_el* curr;

  hashmap_map* m = (hashmap_map*) in;
  hashmap_el* tmp = (hashmap_el*) calloc(2 * m->table_size, sizeof(hashmap_el));
  if(!tmp) return MAP_OMEM;

  curr = m->data;
  m->data = tmp;

  
}

int main(){
  printf("%d",5);
  return 0;
}