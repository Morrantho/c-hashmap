#ifndef MAP_H
#define MAP_H
#include "../def.h"

typedef struct map_t map_t, *map_p, **map_dp;

map_p map_new( ui size );
void map_free( map_p map );
ui map_hash( char_p key );
void map_put( map_p, char_p, void_p );
void map_rep( map_p, char_p, void_p );
void_p map_get( map_p, char_p );
void map_del( map_p, char_p );
#endif // MAP_H