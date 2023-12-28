/*
 *
 * H E L L O W O R L D
 *
 * Explore aspects of the compiler MACRO definitions
 *  and underlying system capabilties.
 *
 * helloWorld.c last edited on Thu Dec 28 19:59:47 2023 
 *
 */

/*
 * Snippet of code to experiment with pre-defined Names
 #
 * use -DCLOCKS to compile in clock/timer
 * investigation code.
 */

/*
 * cpp -dM can provide a list Predefined Macros
 * recognized by the (gnu) compiler
 *
 */


#include  <stdio.h>	/* printf(), perror() */
#include  <string.h>	/* strdup() */
#include  <libgen.h>	/* basename() */
#include  <sys/param.h>	/* Endian macros? */
#ifdef CLOCKS
#include  <time.h>		/* clock_gettime() clock_getres() and struct timespec */
#include  <sys/time.h>	/* struct timeval used by gettimeofday() */

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

int  main( int  argc, char *  argv[])  {
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
	printf( "__STDC__ defined - " );
	printf( "Compiler claims conformance to ISO Standard C.\n" );
#else
	printf( "Compiler does not claim comformance with ISO Standard C.\n" );
#endif
#ifdef __STDC_VERSION__
	printf( "__STDC_VERSION__ defined - " );
	printf( "Compiler claims conformance to ISO Standard C version %ld.\n", __STDC_VERSION__ );
#else
	printf( "Compiler does not define ISO Standard C version date.\n" );
#endif
#ifdef __STDC_HOSTED__
	printf( "__STDC_HOSTED__ defined - " );
	printf( "Compiler claims support for entire standard library.\n" );
#else
	printf( "Compiler does not claim support for entire standard library.\n" );
#endif
#ifdef __GNUC__
	printf( "__GNUC__ defined as %d - ", __GNUC__ );
	printf( "Compiled by gnu gcc or compatible compiler\n" );
	printf( "__GNUC_MINOR__ defined as %d, ", __GNUC_MINOR__ );
	printf( "__GNUC_PATCHLEVEL__ defined as %d\n", __GNUC_PATCHLEVEL__ );
#else
	printf( "Compiler does not claim to be compatible with gnu gcc\n" );
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
#ifdef CLOCKS
	printf( "\nThis compiler/system has the following resolution timers/clocks; -\n" );
	printClockResolutions();
#ifdef __MINGW64__
	printf( "The clock_gettime() function uses \"struct timespec\" (%llu bytes) to store nS time.\n", sizeof( struct timespec ));
	printf( "The gettimeofday() function uses \"struct timeval\" (%llu bytes) to store uS time.\n", sizeof( struct timeval ));
#else
	printf( "The clock_gettime() function uses \"struct timespec\" (%lu bytes) to store nS time.\n", sizeof( struct timespec ));
	printf( "The gettimeofday() function uses \"struct timeval\" (%lu bytes) to store uS time.\n", sizeof( struct timeval ));
#endif	
#endif
	return 0;
}
