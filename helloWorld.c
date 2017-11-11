/*
 *
 * H E L L O W O R L D
 *
 */

/*
 * Snippet of code to experiment with
 *
 */

/*
 * cpp -dM can provide a list Predefined Macros
 * recognized by the (gnu) compiler
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
#ifdef __TIMESTAMP__
	printf( "Source File last Modified on %s\n", __TIMESTAMP__ );
#endif
#ifdef __GNUC__
	printf( "Compiled by gnu gcc or compatible compiler\n" );
#else
	printf( "Compiler does not claim to be compatible with gnu gcc\n" );
#endif
	printf( "Compiler version '%s'\n", __VERSION__ );
#ifdef __unix__
	printf( "This system claims to be a unix system\n" );
#endif
#ifdef __linux__
	printf( "This system claims to be a linux system\n" );
#endif
	return 0;
}
