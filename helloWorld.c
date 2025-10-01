/*
 *
 * H E L L O W O R L D
 *
 * Explore aspects of the compiler MACRO definitions
 *  and underlying system capabilties.
 *
 * helloWorld.c last edited on Wed Oct  1 23:21:12 2025 
 *
 */

/*
 * Code to get details on which pre-defined Names the
 * c compiler recognizes. This code can also output info
 * about size of number types and clock/timer resolution.
 * Usage information can be obtained with the -h option.
 * E.g.   ./helloWorld -h
 * 
 */

/*
 * cpp -dM can provide a list Predefined Macros
 * recognized by the (gnu) c language compiler
 *
 */

/*
 * 0v13 Added warning message to inform user who specifies -C
 * when the -DCLOCKS wasn't used at compile time
 *
 */

#include  <stdio.h>   /* printf(), perror() */
#include  <stdlib.h>  /* free() */
#include  <string.h>	/* strdup() */
#include  <libgen.h>	/* basename() */
#include  <sys/param.h>	/* Endian macros? */
#include  <limits.h>    /* MIN and MAX size of number types */
#include  <float.h>     /* MIN and MAX size of floating point numbers */
#include  "config.h"    /* init Configuration */
#ifdef CLOCKS
#include  <time.h>		/* clock_gettime() clock_getres() and struct timespec */
#include  <sys/time.h>	/* struct timeval used by gettimeofday() */
#endif

#define VERSION_INFO "0v13"

#ifdef CLOCKS
void  printClockResolutions( void );
#endif
void  setExecutableName( char *  argv[] );
void  cleanupStorage( void );


char *  exePath = NULL;
char *  exeName = NULL;


int  main( int  argc, char *  argv[])  {
  struct config  config;
  int  indexToFirstNonConfig;
  int  index;

	/* Ensure any allocated memory is free'd */
	atexit( cleanupStorage );
  /* setup the name of this program */
  setExecutableName( argv );
  /* set defaults for all configuration options */
  initConfiguration( &config );
  /* set any configuration options that have been specified in the command line */
  indexToFirstNonConfig = setConfiguration( argc, argv, &config );
  if ( config.D.active )  {
    configuration_status( &config);
    for ( index = indexToFirstNonConfig; index < argc; index++)
      printf ( "Debug: Non-option argument ( %d ): \"%s\"\n", index, argv[index]);
  }
  /* if -V, -v or -D then show version information */
  if ( config.V.active || config.v.active || config.D.active )
    printf( "%s version %s\n", exeName, VERSION_INFO );
  if ( config.h.active )  usage( &config, exeName );

  for ( index = ( config.b.active ) ? config.b.optionInt : config.b.defaultVal; index > 0; --index )  printf( "\n" );
	printf( "Hello World" );
  if( config.v.active )  printf( ", courtesy of '%s'\n", exeName );
  else  printf( "!\n" );
  for ( index = ( int )(( config.a.active ) ? config.a.optionLng : config.a.defaultVal); index > 0; --index )  printf( "\n" );
  if ( config.m.active )  printf( "%s\n", config.m.optionStr );
  
  if ( config.c.active )  {
#ifdef __FILE__
  	printf( "'%s' compiled from '%s', ", exeName, __FILE__ );
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
	  printf( "Unable to specify this line that is being executed (i.e. __LINE__ isn't defined).\n" );
#endif
#ifdef __TIMESTAMP__
  	printf( "Source File '%s' last Modified on %s\n", __FILE__, __TIMESTAMP__ );
#endif
	  printf( "\n" );
#ifdef __STDC__
  	printf( "__STDC__ defined - " );
	  printf( "Compiler claims conformance to ISO Standard C.\n" );
#else
  	printf( "Compiler does not claim comformance with ISO Standard C (i.e. __STDC__ isn't defined).\n" );
#endif
#ifdef __STDC_VERSION__
  	printf( "__STDC_VERSION__ defined - " );
	  printf( "Compiler claims conformance to ISO Standard C version %ld.\n", __STDC_VERSION__ );
#else
  	printf( "Compiler does not define ISO Standard C version date (i.e. __STDC_VERSION__ isn't defined).\n" );
#endif
#ifdef __STDC_HOSTED__
  	printf( "__STDC_HOSTED__ defined - " );
	  printf( "Compiler claims support for entire standard library.\n" );
#else
  	printf( "Compiler does not claim support for entire standard library (i.e. __STDC_HOSTED__ isn't defined).\n" );
#endif
#ifdef __GNUC__
  	printf( "__GNUC__ defined as %d - ", __GNUC__ );
	  printf( "Compiled by gnu gcc or compatible compiler\n" );
  	printf( "__GNUC_MINOR__ defined as %d, ", __GNUC_MINOR__ );
	  printf( "__GNUC_PATCHLEVEL__ defined as %d\n", __GNUC_PATCHLEVEL__ );
#else
  	printf( "Compiler does not claim to be compatible with gnu gcc (i.e. __GNUC__ isn't defined).\n" );
#endif
#ifdef __VERSION__
	  printf( "__VERSION__ defined - " );
  	printf( "Compiler version '%s'\n", __VERSION__ );
#else
	  printf( "Compiler does not define version with __VERSION__\n" );
#endif
  	printf( "\n" );
#ifdef __unix__
  	printf( "__unix__ defined - " );
	  printf( "This compiler system claims to be a unix based system.\n" );
#else
  	printf( "This compiler system doesn't define __unix__.\n" );
#endif
#ifdef __linux__
	  printf( "__linux__ defined - " );
  	printf( "This compiler system claims to be a linux based system.\n" );
#else
	  printf( "This compiler system doesn't define __linux__.\n" );
#endif
#ifdef __APPLE__
  	printf( "__APPLE__ defined - " );
	  printf( "This compiler system claims to be an apple based system.\n" );
#else
  	printf( "This compiler system doesn't define __APPLE__.\n" );
#endif
#ifdef __CYGWIN__
	  printf( "__CYGWIN__ defined - " );
  	printf( "This compiler system claims to be a cygwin based system.\n" );
#else
	  printf( "This compiler system doesn't define __CYGWIN__.\n" );
#endif
#ifdef __OpenBSD__
  	printf( "__OpenBSD__ defined - " );
	  printf( "This compiler system claims to be an OpenBSD based system.\n" );
#else
  	printf( "This compiler system doesn't define __OpenBSD__.\n" );
#endif
#ifdef __FreeBSD__
  	printf( "__FreeBSD__ defined - " );
	  printf( "This compiler system claims to be an FreeBSD based system.\n" );
#else
  	printf( "This compiler system doesn't define __FreeBSD__.\n" );
#endif
#ifdef __MINGW32__
  	printf( "__MINGW32__ defined - " );
	  printf( "This compiler system claims to be a MINGW32 Windows based system.\n" );
#else
  	printf( "This compiler system doesn't define __MINGW32__.\n" );
#endif
#ifdef __MINGW64__
	  printf( "__MINGW64__ defined - " );
  	printf( "This compiler system claims to be a MINGW64 Windows based system.\n" );
#else
	  printf( "This compiler system doesn't define __MINGW64__.\n" );
#endif
  }

  if ( config.N.active )  {
#ifdef __BYTE_ORDER__
	  printf( "This compiler system claims to be a " );
    if( __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ )  printf( "big" );
    else if( __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ )  printf( "little" );
    else if( __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__ )  printf( "little (word swapped)" );
    else printf( "unknown" );
    printf( " endian based system.\n" );
#else
	  printf( "This compiler system doesn't define __BYTE_ORDER, at least not in <sys/param.h>\n" );
#endif
#ifdef CHAR_BIT
    printf("The char number of bits (\"CHAR_BIT\") is %d\n", CHAR_BIT);
#endif
#ifdef CHAR_MIN
    printf("The char most negetive value (\"CHAR_MIN\") is %d\n", CHAR_MIN);
#endif
#ifdef CHAR_MAX
    printf("The char most positive value (\"CHAR_MAX\") is %d\n", CHAR_MAX);
#endif
#ifdef UCHAR_MAX
    printf("The unsigned char maximum value (\"UCHAR_MAX\") is %d\n", UCHAR_MAX);
#endif
#ifdef __SIZEOF_SHORT__ 
    printf("The short int number type has a size of (\"__SIZEOF_SHORT__\") %d bytes\n", __SIZEOF_SHORT__);
#endif
#ifdef SHRT_MIN 
    printf("The short int most negetive value (\"SHRT_MIN\") is %d\n", SHRT_MIN);
#endif
#ifdef SHRT_MAX 
    printf("The short int most positive value (\"SHRT_MAX\") is %d\n", SHRT_MAX);
#endif
#ifdef USHRT_MAX 
    printf("The unsigned short int maximum value (\"USHRT_MAX\") is %u\n", USHRT_MAX);
#endif
#ifdef __SIZEOF_INT__ 
    printf("The int number type has a size of (\"__SIZEOF_INT__\") %d bytes\n", __SIZEOF_INT__);
#endif
#ifdef INT_MIN 
    printf("The int most negetive value (\"INT_MIN\") is %d\n", INT_MIN);
#endif
#ifdef INT_MAX 
    printf("The int most positive value (\"INT_MAX\") is %d\n", INT_MAX);
#endif
#ifdef UINT_MAX 
    printf("The unsigned int maximum value (\"UINT_MAX\") is %u\n", UINT_MAX);
#endif
#ifdef __SIZEOF_LONG__ 
    printf("The long int number type has a size of (\"__SIZEOF_LONG__\") %d bytes\n", __SIZEOF_LONG__);
#endif
#ifdef LONG_MIN 
    printf("The long int most negetive value (\"LONG_MIN\") is %ld\n", LONG_MIN);
#endif
#ifdef LONG_MAX 
    printf("The long int most positive value (\"LONG_MAX\") is %ld\n", LONG_MAX);
#endif
#ifdef ULONG_MAX 
    printf("The unsigned long int maximum value (\"ULONG_MAX\") is %lu\n", ULONG_MAX);
#endif
#ifdef __SIZEOF_LONG_LONG__ 
    printf("The long long int number type has a size of (\"__SIZEOF_LONG_LONG__\") %d bytes\n", __SIZEOF_LONG_LONG__);
#endif
#ifdef LLONG_MIN
    printf("The long long int most negetive value (\"LLONG_MIN\") is %lld\n", LLONG_MIN);
#endif
#ifdef LLONG_MAX 
    printf("The long long int most positive value (\"LLONG_MAX\") is %lld\n", LLONG_MAX);
#endif
#ifdef ULLONG_MAX 
    printf("The unsigned long long int maximum value (\"ULLONG_MAX\") is %llu\n", ULLONG_MAX);
#endif
#ifdef RAND_MAX 
    printf("The rand() maximum value (\"RAND_MAX\") is %d\n", RAND_MAX);
#endif
#ifdef __SIZEOF_FLOAT__ 
    printf("The float precision number has a size of (\"__SIZEOF_FLOAT__\") %d bytes\n", __SIZEOF_FLOAT__);
#endif
#ifdef FLT_MAX 
    printf("The float precision maximum floating point value (\"FLT_MAX\") is %g\n", FLT_MAX);
#endif
#ifdef FLT_MIN 
    printf("The float precision minimum floating point value (\"FLT_MIN\") is %g\n", FLT_MIN);
#endif
#ifdef FLT_DIG 
    printf("The float precision floating point value (\"FLT_DIG\") has %d digits\n", FLT_DIG);
#endif
#ifdef FLT_DECIMAL_DIG
    printf("The float precision floating point value (\"FLT_DECIMAL_DIG\") has %d decimal digits\n", FLT_DECIMAL_DIG);
#endif
#ifdef FLT_MANT_DIG
    printf("The float precision floating point value (\"FLT_MANT_DIG\") has %d mantissa bits\n", FLT_MANT_DIG);
#endif
#ifdef FLT_EPSILON
    printf("The float precision epsilon floating point value (\"FLT_EPSILON\") is %g\n", FLT_EPSILON);
#endif
#ifdef __SIZEOF_DOUBLE__ 
    printf("The double precision number has a size of (\"__SIZEOF_DOUBLE__\") %d bytes\n", __SIZEOF_DOUBLE__);
#endif
#ifdef DBL_MAX 
    printf("The double precision maximum floating point value (\"DBL_MAX\") is %lg\n", DBL_MAX);
#endif
#ifdef DBL_MIN 
    printf("The double precision minimum floating point value (\"DBL_MIN\") is %lg\n", DBL_MIN);
#endif
#ifdef DBL_DIG 
    printf("The double precision floating point value (\"DBL_DIG\") has %d digits\n", DBL_DIG);
#endif
#ifdef DBL_DECIMAL_DIG
    printf("The double precision floating point value (\"DBL_DECIMAL_DIG\") has %d decimal digits\n", DBL_DECIMAL_DIG);
#endif
#ifdef DBL_MANT_DIG
    printf("The double precision floating point value (\"DBL_MANT_DIG\") has %d mantissa bits\n", DBL_MANT_DIG);
#endif
#ifdef DBL_EPSILON
    printf("The double precision epsilon floating point value (\"DBL_EPSILON\") is %lg\n", DBL_EPSILON);
#endif
#ifdef __SIZEOF_LONG_DOUBLE__ 
    printf("The long double precision number has a size of (\"__SIZEOF_LONG_DOUBLE__\") %d bytes\n", __SIZEOF_LONG_DOUBLE__);
#endif
#ifdef LDBL_MAX 
    printf("The long double precision maximum floating point value (\"LDBL_MAX\") is %Lg\n", LDBL_MAX);
#endif
#ifdef LDBL_MIN 
    printf("The long double precision minimum floating point value (\"LDBL_MIN\") is %Lg\n", LDBL_MIN);
#endif
#ifdef LDBL_DIG 
    printf("The long double precision floating point value (\"LDBL_DIG\") has %d digits\n", LDBL_DIG);
#endif
#ifdef LDBL_DECIMAL_DIG
    printf("The long double precision floating point value (\"LDBL_DECIMAL_DIG\") has %d decimal digits\n", LDBL_DECIMAL_DIG);
#endif
#ifdef LDBL_MANT_DIG
    printf("The long double precision floating point value (\"LDBL_MANT_DIG\") has %d mantissa bits\n", LDBL_MANT_DIG);
#endif
#ifdef LDBL_EPSILON
    printf("The long double precision epsilon floating point value (\"LDBL_EPSILON\") is %Lg\n", LDBL_EPSILON);
#endif
  }
#ifdef CLOCKS
  if ( config.C.active )  {
	  printf( "\nThis compiler/system has the following resolution timers/clocks; -\n" );
  	printClockResolutions();
#ifdef __MINGW64__
	  printf( "The clock_gettime() function uses \"struct timespec\" (%llu bytes) to store nS time.\n", sizeof( struct timespec ));
  	printf( "The gettimeofday() function uses \"struct timeval\" (%llu bytes) to store uS time.\n", sizeof( struct timeval ));
#else
  	printf( "The clock_gettime() function uses \"struct timespec\" (%lu bytes) to store nS time.\n", sizeof( struct timespec ));
	  printf( "The gettimeofday() function uses \"struct timeval\" (%lu bytes) to store uS time.\n", sizeof( struct timeval ));
#endif
  }
#else /* i.e. CLOCKS not defined */
  if ( config.C.active )  {
    printf( "Warning: -C specified, but no clock code was compiled into this binary.")
    printf( "You could try recompiling the source with the -DCLOCKS flag specified.")
  }
#endif
	return 0;
}


void  setExecutableName( char *  argv[] ) {
/* Isolate the name of the executable */
  if(( exePath = strdup( argv[0] )) == NULL )
    perror( "Warning: Unable to create duplicate of path to this executable" );
  else if(( exeName = basename( exePath )) == NULL )  {
    perror( "Warning: Unable to obtain the name of this executable" );
  }
  if ( exeName == NULL )  exeName = argv[ 0 ];
}


void  cleanupStorage( void )  {
	if( exePath != NULL )  free(( void *) exePath );
}


#ifdef CLOCKS

int  isTimespecEqual( struct timespec *  tp1, struct timespec *  tp2 )  {
  return(( tp2->tv_nsec == tp1->tv_nsec ) && ( tp2->tv_sec == tp1->tv_sec ));
}


long  nsTimeDiff( struct timespec *  tpEarlier, struct timespec *  tpLater )  {
  if( tpLater->tv_sec != tpEarlier->tv_sec )  {
    tpLater->tv_nsec = ( tpLater->tv_sec - tpEarlier->tv_sec ) * 1000000000;
  }
  return( tpLater->tv_nsec - tpEarlier->tv_nsec );
}

int  printClockTime( clockid_t  clockIdentifier, struct timespec *  nsTime )  {
  int  result;
  int  clockReadCount = 0;
  struct timespec  ts, ts2;
  char  timeAndDateStr[ 64 ];
  
  if(( result = clock_gettime( clockIdentifier, &ts2 )) != 0 )  {
    printf( "? clock_gettime() failed as it returned a value of %d ?\n", result );
    perror( "clock_gettime()" );
    return( result );
  }
  else  {
  /* Inital clock read was successful so loop looking for a time reading change */
    do {
      result = clock_gettime( clockIdentifier, &ts );
    }  while (( result == 0 ) && ( ts.tv_nsec == ts2.tv_nsec ) && ( ts.tv_sec == ts2.tv_sec ));
    if( result != 0 )  {
      printf( "? clock_gettime() in loop 1 failed as it returned a value of %d ?\n", result );
      perror( "clock_gettime()" );
      return( result );
    }
    else  {
    /* First time reading change was successfully found so look for a second time reading change */
    /* and count how many reads before we get a change */
      do {
        result = clock_gettime( clockIdentifier, &ts2 );
        clockReadCount += 1;
      }  while (( result == 0 ) && ( ts.tv_nsec == ts2.tv_nsec ) && ( ts.tv_sec == ts2.tv_sec ));
      /* now that the time critical stuff is done print info about the first time rading change */
      nsTime->tv_nsec = ts.tv_nsec;
      nsTime->tv_sec = ts.tv_sec;
      if( clockIdentifier == CLOCK_REALTIME )  {
        ctime_r( (time_t * ) &nsTime->tv_sec, timeAndDateStr );
        printf( "%ld.%09ld [S] i.e. %s", nsTime->tv_sec, nsTime->tv_nsec, timeAndDateStr );
      }
      else  {
        printf( "%ld.%09ld [S]\n", nsTime->tv_sec, nsTime->tv_nsec );
      }
      /* if the second time reading change failed then inform user */
      if( result != 0 )  {
        printf( "? clock_gettime() in loop 2 failed as it returned a value of %d ?\n", result );
        perror( "clock_gettime()" );
        return( result );
      }
      else  {
        printf( " Time change noticed after %d clock reads. Time stamp was %ld.%09ld [S]", clockReadCount, ts2.tv_sec, ts2.tv_nsec );
        printf( " = Delta of %ld [nS]\n", nsTimeDiff( nsTime, &ts2 ));
      }
    }
    printf( "\n" );
  }
  return( 0 );
}


int  getClockResolution( clockid_t  clockIdentifier, struct timespec *  resolution )  {
  int  result;
  
  resolution->tv_nsec = (long) 0;	/* Ensure structure is zero'd */
  resolution->tv_sec = (time_t) 0;	/* Ensure structure is zero'd */
  result = clock_getres( clockIdentifier, resolution );
  if( result != 0 )  {
    printf( "? clock_getres() failed as it returned a value of %d ?\n", result );
    perror( "clock_getres()" );
    return( result );
  }
  else  {
    printf( "%ld [nS] resolution ", resolution->tv_nsec );
  }
  return( 0 );
}


void  printClockResolutions( void )  {
  clockid_t  clockType;
  struct timespec  resolution;
  
  clockType = CLOCK_REALTIME;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_REALTIME\n" );
  printf( " CLOCK_REALTIME time is " );
  printClockTime( clockType, &resolution );
#ifdef  CLOCK_MONOTONIC
  clockType = CLOCK_MONOTONIC;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_MONOTONIC\n" );
  printf( " CLOCK_MONOTONIC time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_MONOTONIC_RAW
  clockType = CLOCK_MONOTONIC_RAW;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_MONOTONIC_RAW\n" );
  printf( " CLOCK_MONOTONIC_RAW time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_MONOTONIC_RAW_APPROX
  clockType = CLOCK_MONOTONIC_RAW_APPROX;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_MONOTONIC_RAW_APPROX\n" );
  printf( " CLOCK_MONOTONIC_RAW_APPROX time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_UPTIME_RAW
  clockType = CLOCK_UPTIME_RAW;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_UPTIME_RAW\n" );
  printf( " CLOCK_UPTIME_RAW time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_UPTIME_RAW_APPROX
  clockType = CLOCK_UPTIME_RAW_APPROX;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_UPTIME_RAW_APPROX\n" );
  printf( " CLOCK_UPTIME_RAW_APPROX time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_PROCESS_CPUTIME_ID
  clockType = CLOCK_PROCESS_CPUTIME_ID;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_PROCESS_CPUTIME_ID\n" );
  printf( " CLOCK_PROCESS_CPUTIME_ID time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_THREAD_CPUTIME_ID
  clockType = CLOCK_THREAD_CPUTIME_ID;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_THREAD_CPUTIME_ID\n" );
  printf( " CLOCK_THREAD_CPUTIME_ID time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_REALTIME_HR
  clockType = CLOCK_REALTIME_HR;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_REALTIME_HR\n" );
  printf( " CLOCK_REALTIME_HR time is " );
  printClockTime( clockType, &resolution );
#endif
#ifdef  CLOCK_MONOTONIC_HR
  clockType = CLOCK_MONOTONIC_HR;
  if( getClockResolution( clockType, &resolution ) == 0 )
    printf( "claimed for CLOCK_MONOTONIC_HR\n" );
  printf( " CLOCK_MONOTONIC_HR time is " );
  printClockTime( clockType, &resolution );
#endif
}
#endif
