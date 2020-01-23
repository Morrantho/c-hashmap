#ifndef LIST_H
#define LIST_H
#include "../def.h"

typedef struct list_node_t list_node_t, *list_node_p, **list_node_dp;
typedef struct list_t list_t, *list_p, **list_dp;
typedef void ( *list_func )( list_node_p );

void list_init( list_p );
list_p list_new();
void list_free( list_p );
void list_push( list_p, char_p, void_p );
void_p list_pop( list_p );
void_p list_popfront( list_p );
void_p list_remove( list_p, char_p );
bool list_has( list_p, char_p );
void list_set( list_p, char_p, void_p );
list_node_p list_get( list_p, char_p );
void list_iter( list_p, list_func );
#endif // LIST_H