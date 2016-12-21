/*
 *
 * H E L L O W O R L D
 *
 */

#include  <stdio.h>

int main()
{
	printf( "Hello World, courtesy of " );
#ifdef __GNUC__
	printf( "cc " );
#endif
#ifdef __FILE__
	printf( "%s, ", __FILE__ );
#endif
#ifdef __DATE__
	printf( "compiled on %s ", __DATE__ );
#endif
#ifdef __TIME__
	printf( "at %s ", __TIME__ );
#endif
	printf( "\n" );
	return 0;
}
