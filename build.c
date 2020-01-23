#include "map/map.c"

int main(int argc, char **argv)
{
	map_p map = map_new(13);
	char *keys[] = { "health", "level", "score" };
	int data[] = { 100, 5, 30, 50 };
	for( ui i = 0; i < 3; i++ ) map_put( map, keys[i], &data[i] );

	printf( "level=%d\n", *(int*)map_get( map, "level" ) );
	printf("score=%d\n", *(int *)map_get(map, "score"));

	printf( "health=%d\n", *(int*)map_get( map, "health" ) );
	map_rep( map, "health", &data[3] );
	printf( "health=%d\n", *(int*)map_get( map, "health" ) );

	printf( "level_ptr=%p\n", map_get( map, "level" ) );
	map_del( map, "level" );
	printf( "level_ptr=%p\n", map_get( map, "level" ) );

	map_free(map);
	return 0;
}