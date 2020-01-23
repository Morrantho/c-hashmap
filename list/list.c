#include "list.h"

struct list_node_t
{
	void_p key;
	void_p value;
	void_p next;
	void_p previous;
};

struct list_t
{
	list_node_p head;
	list_node_p tail;
	ui size;
};

void list_init( list_p list )
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

list_p list_new()
{
	list_p list = malloc( sizeof( list_t ) );
	list_init( list );
	return list;
}

void list_free( list_p list )
{
	for( list_node_p h = list->head; h != NULL; h = h->next)
	{
		list_node_p h_prev = h;
		h = h->next;
		free( h_prev );
	}
	list_init( list );
}

void list_push( list_p list, char_p key, void_p value )
{
	list_node_p new_node = malloc( sizeof( list_node_t ) );
	new_node->next       = NULL;
	new_node->previous   = NULL;
	new_node->key        = key;
	new_node->value      = value;
	if( list->head == NULL || list->tail == NULL ) // no first node exists yet
	{
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return;
	}
	new_node->previous = list->tail;
	list->tail->next = new_node;
	list->tail = new_node;
	list->size++;
}

void_p list_pop( list_p list )
{
	list_node_p t = list->tail;
	void_p value = t->value;
	list->tail = list->tail->previous;
	list->tail->next = NULL;
	free( t );
	list->size--;
	return value;
}

void_p list_popfront( list_p list )
{
	list_node_p node = list->head;
	void_p value = node->value;
	list->head = list->head->next;
	free( node );
	return value;
}

void_p list_swap( list_node_p n )
{
	list_node_p previous = n->previous;
	previous->next = n->next;
	list_node_p next = n->next;
	next->previous = n->previous;
	void_p value = n->value;
	free( n );
	return value;
}

void_p list_remove( list_p list, char_p key )
{
	list_node_p h = list->head;
	list_node_p t = list->tail;
	for( ; h != NULL && t != NULL; h = h->next, t = t->previous )
	{
		bool should_remove = strcmp( h->key, key ) == 0;
		if( should_remove )
		{
			if( h == list->head )
				return list_popfront( list );
			else if( t == list->tail )
				return list_pop( list );
			else
				return list_swap( h );
		}
	}
}

bool list_has( list_p list, char_p key )
{
	list_node_p h = list->head;
	list_node_p t = list->tail;
	for( ; h != NULL && t != NULL; h = h->next, t = t->previous )
	{
		if ( strcmp( h->key, key ) == 0 || strcmp( t->key, key ) == 0 )
			return true;
	}
	return false;
}

void list_set( list_p list, char_p key, void_p value )
{
	list_node_p h = list->head;
	list_node_p t = list->tail;
	for( ; h != NULL && t != NULL; h = h->next, t = t->previous )
	{
		if( strcmp( h->key, key ) == 0 )
		{
			h->value = value;
			return;
		}
		if( strcmp( t->key, key ) == 0 )
		{
			t->value = value;
			return;
		}
	}
}

list_node_p list_get( list_p list, char_p key )
{
	list_node_p h = list->head;
	list_node_p t = list->tail;
	for( ; h != NULL && t != NULL; h = h->next, t = t->previous )
	{
		if( strcmp( h->key, key ) == 0 ) return h;
		if( strcmp( t->key, key ) == 0 ) return t;
	}
	return NULL;
}

void list_iter( list_p list, list_func cb )
{
	for( list_node_p n = list->head; n != NULL; n = n->next )
		cb( n );
}