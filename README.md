# c-hashmap
A Simple C hashmap with underlying doubly linked lists for collision resolution. Uses djb2 for hashing. Prime numbers for hashmap size will result in better key distribution. If no collisions are present for a key lookup, yields O(1). If collisions exist, yields O(n/2) where n is the number of collisions in the indexes linked list.

## API

### Creates and returns a map pointer.
```c
map_p map_new( ui size );
```
### Deallocates the map, the linked list array, and all data the linked lists point to.
```c
void map_free( map_p map );
```
### Enters a key value pair into the specified map.
```c
void map_put( map_p, char_p, void_p );
```
### Replaces a key value pair into the specified map.
```c
void map_rep( map_p, char_p, void_p );
```
### Retrieves a key value pair from the specified map or null.
```c
void_p map_get( map_p, char_p );
```
### Attempts to delete a key value pair from the specified map.
```c
void map_del( map_p, char_p );
```
