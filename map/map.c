#include "map.h"
#include "../list/list.c"

struct map_t
{
	ui size;
	list_t **data;
};

map_p map_new( ui size )
{
	map_p map = malloc( sizeof( map_t ) );
	map->data = malloc( sizeof( list_p ) * size );
	for( ui i = 0; i < size; i++ )
	{
		map->data[i] = malloc( sizeof( list_t ) );
		list_init( map->data[ i ] );
	} 
	map->size = size;
	return map;
}

void map_free( map_p map )
{
	for( ui i = 0; i < map->size; i++ )
	{
		list_free( map->data[ i ] );
		free( map->data[i] );
	}
	free( map->data );
	free( map );
}

ui djb2( char_p key )
{
	ui hash = 5381;
	int c;
	while( c = *key++ )
		hash = ((hash << 5) + hash) + c;
	return hash;
}

void map_put( map_p map, char_p key, void_p value )
{
	ui idx = djb2( key ) % map->size;
	list_p list = map->data[idx];
	list_push( list, key, value );
}

void map_rep( map_p map, char_p key, void_p value )
{
	ui idx = djb2( key ) % map->size;
	list_p list = map->data[idx];
	list_node_p node = list_get( list, key );
	if( node ) node->value = value;
}

void_p map_get( map_p map, char_p key )
{
	ui idx = djb2( key ) % map->size;
	list_p list = map->data[idx];
	list_node_p node = list_get( list, key );
	if( node ) return node->value;
	return NULL;
}

void map_del( map_p map, char_p key )
{
	ui idx = djb2( key ) % map->size;
	list_p list = map->data[idx];
	list_node_p node = list_remove( list, key );
}