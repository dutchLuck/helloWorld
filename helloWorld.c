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


#include  <stdio.h>	/* printf(), perror() */
#include  <string.h>	/* strdup() */
#include  <libgen.h>	/* basename() */

int main( int  argc, char *  argv[])
{
	char *  exePath;
	char *  name;	/* Name of executable */

	name = argv[0];	/* default to using argv for executable name */
	if(( exePath = strdup( argv[0] )) == NULL )  {
		perror( "?? Unable to duplicate path to this executable" );
	}
	else if(( name = basename( exePath )) == NULL )  {
		perror( "?? Unable to obtain the name of this executable" );
		name = argv[0];
	}
	printf( "\nHello World, courtesy of '%s'\n\n", name );

#ifdef __FILE__
	printf( "'%s' compiled from '%s', ", name, __FILE__ );
#else
	printf( "'%s' compiled from an unspecified source file, ", name );
#endif
#ifdef __DATE__
	printf( "on %s ", __DATE__ );
#else
	printf( "on an unspecified date " );
#endif
#ifdef __TIME__
	printf( "at %s\n", __TIME__ );
#else
	printf( "at an unspecified time\n" );
#endif

#ifdef __LINE__
	printf( "Now executing line %d in function '%s'\n", __LINE__, __func__ );
#else
	printf( "Unable to specify this line that is being executed\n" );
#endif
#ifdef __TIMESTAMP__
	printf( "Source File '%s' last Modified on %s\n", __FILE__, __TIMESTAMP__ );
#endif
	printf( "\n" );
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
#ifdef __STDC_HOSTED__
	printf( "Compiler claims support for entire standard library.\n" );
#else
	printf( "Compiler does not claim support for entire standard library.\n" );
#endif
#ifdef __GNUC__
	printf( "Compiled by gnu gcc or compatible compiler\n" );
#else
	printf( "Compiler does not claim to be compatible with gnu gcc\n" );
#endif
#ifdef __VERSION__
	printf( "Compiler version '%s'\n", __VERSION__ );
#else
	printf( "Compiler does not define version with __VERSION__\n", __VERSION__ );
#endif
	printf( "\n" );
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
#ifdef __FreeBSD__
	printf( "This compiler system claims to be an FreeBSD based system.\n" );
#else
	printf( "This compiler system doesn't define __FreeBSD__.\n" );
#endif
#ifdef __MINGW32__
	printf( "This compiler system claims to be a MINGW32 Windows based system.\n" );
#else
	printf( "This compiler system doesn't define __MINGW32__.\n" );
#endif
#ifdef __MINGW64__
	printf( "This compiler system claims to be a MINGW64 Windows based system.\n" );
#else
	printf( "This compiler system doesn't define __MINGW64__.\n" );
#endif
	return 0;
}
