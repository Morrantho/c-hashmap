# c-hashmap
A Simple C hashmap with underlying linked lists for collision resolution.

## API

### Creates and returns a map pointer.
```c
map_p map_new( ui size );
```
### Deallocates the map, the linked list array, and all data the linked lists point to.
```c
void map_free( map_p map );
```
### djb2 hash function
```c
ui map_hash( char_p key );
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
