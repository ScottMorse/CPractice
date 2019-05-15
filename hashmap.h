// Looks like a Java Interface, but isn't one
// In C, declarations can only have one definition
// In Java, an interface can be used by many classes

#ifndef __HASHMAP_H__ // include guard

#define __HASHMAP_H__

//error codes
#define MAP_MISSING -3
#define MAP_FULL -2
#define MAP_OEM -1
#define MAP_OKAY 0

// any type
typedef void* any;

// function pointer to any func with two any args that returns int
typedef int (*PFany)(any,any);

// pointer to hashmap
typedef any HashMap;

extern HashMap new_hashmap();

// use callback f on hashmap, should return MAP_OKAY or terminate iteration
extern int hashmap_iterate(HashMap in, PFany f, any value);

// standard map put (MAP_OKAY, MAP_MISSING, MAP_OEM)
extern int hashmap_put(HashMap in, char* key, any value);

// get value from key (MAP_OKAY, MAP_MISSING)
extern int hashmap_get(HashMap in, char* key, any *arg);

// remove element (MAP_OKAY, MAP_MISSING)
extern int hashmap_remove(HashMap in, char* key);

// get any element, remove bool-like to remove element (MAP_OKAY, MAP_MISSING)
extern int hashmap_getone(HashMap in, any *arg, int remove);

// Free a hashmap
extern void hashmap_free(HashMap in);

// Get hashmap size
extern void hashmap_len(HashMap in);

#endif __HASHMAP_H__