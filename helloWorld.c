/*
 *
 * H E L L O W O R L D
 *
 */

/*
 * Snippet of code to experiment with
 *
 */

#include  <stdio.h>

int main( int  argc, char *  argv[])
{
	printf( "Hello World, courtesy of '%s'\n", argv[0] );
#ifdef __FILE__
	printf( "Compiled from %s, ", __FILE__ );
#endif
#ifdef __DATE__
	printf( "on %s ", __DATE__ );
#endif
#ifdef __TIME__
	printf( "at %s\n", __TIME__ );
#endif
	printf( "%s\n", __VERSION__ );
	return 0;
}
