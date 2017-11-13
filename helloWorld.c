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


#include  <stdio.h>	/* printf() */

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
#ifdef __STDC__
	printf( "Compiler claims conformance to ISO Standard C.\n" );
#else
	printf( "Compiler does not claim comformance with ISO Standard C.\n" );
#endif
#ifdef __STDC_VERSION__
	printf( "Compiler claims conformance to ISO Standard C version %ld.\n", __STDC_VERSION__ );
#else
	printf( "Compiler does not define ISO Standard C version date.\n" );
#endif
#ifdef __GNUC__
	printf( "Compiled by gnu gcc or compatible compiler\n" );
#else
	printf( "Compiler does not claim to be compatible with gnu gcc\n" );
#endif
	printf( "Compiler version '%s'\n", __VERSION__ );
#ifdef __unix__
	printf( "This compiler system claims to be a unix based system.\n" );
#else
	printf( "This compiler system doesn't define __unix__.\n" );
#endif
#ifdef __linux__
	printf( "This compiler system claims to be a linux based system.\n" );
#else
	printf( "This compiler system doesn't define __linux__.\n" );
#endif
#ifdef __APPLE__
	printf( "This compiler system claims to be an apple based system.\n" );
#else
	printf( "This compiler system doesn't define __APPLE__.\n" );
#endif
#ifdef __CYGWIN__
	printf( "This compiler system claims to be a cygwin based system.\n" );
#else
	printf( "This compiler system doesn't define __CYGWIN__.\n" );
#endif
#ifdef __OpenBSD__
	printf( "This compiler system claims to be an OpenBSD based system.\n" );
#else
	printf( "This compiler system doesn't define __OpenBSD__.\n" );
#endif
#ifdef __MINGW32__
	printf( "This compiler system claims to be an MINGW32 Windows based system.\n" );
#else
	printf( "This compiler system doesn't define __MINGW32__.\n" );
#endif
	return 0;
}
