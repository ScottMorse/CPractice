#ifndef __HASH_MAP__
#define __HASH_MAP__

#define MAP_MISSING -3
#define MAP_FULL -2
#define MAP_OEM -1

// any type
typedef void* any;

// function pointer to any func with two any args that returns int
typedef int (*PFany)(any,any);

typedef any HashMap;

extern HashMap new_hashmap();

extern int hashmap_iterate(HashMap in, PFany f, any value);

extern int hashmap_put(HashMap in, char* key, any value);




#endif __HASH_MAP__;