/*
 * C O N F I G . C
 *
 * Last Modified on Wed Jul 31 13:25:15 2024
 *
 */

#include <stdio.h>    /* printf() */
#include <stdlib.h>   /* floating point double */
#include <unistd.h>   /* getopt() */
#include <ctype.h>    /* isprint()*/
#include <limits.h>   /* INT_MIN INT_MAX LONG_MIN LONG_MAX */
#include <float.h>    /* DBL_MIN DBL_MAX */
#include <string.h>   /* strchr() */
#include "config.h"   /* struct config */
#include "genFun.h"   /* convertOptionStringToInteger() limitIntegerValueToEqualOrWithinRange() */


int  configureIntegerOption( struct optInt *  intStructPtr, char *  intString ) {
  intStructPtr->active = TRUE;
  intStructPtr->optionInt = convertOptionStringToInteger( intStructPtr->defaultVal, intString,
    intStructPtr->optID, &intStructPtr->active, TRUE );
  intStructPtr->optionInt = limitIntegerValueToEqualOrWithinRange( intStructPtr->optionInt,
    intStructPtr->mostNegLimit, intStructPtr->mostPosLimit );
  return( intStructPtr->active );
}


int  configureLongOption( struct optLng *  longStructPtr, char *  longString ) {
  longStructPtr->active = TRUE;
  longStructPtr->optionLng = convertOptionStringToLong( longStructPtr->defaultVal, longString,
    longStructPtr->optID, &longStructPtr->active, TRUE );
  longStructPtr->optionLng = limitLongValueToEqualOrWithinRange( longStructPtr->optionLng,
    longStructPtr->mostNegLimit, longStructPtr->mostPosLimit );
  return( longStructPtr->active );
}


int  configureDoubleOption( struct optDbl *  dblStructPtr, char *  dblString ) {
  dblStructPtr->active = TRUE;
  dblStructPtr->optionDbl = convertOptionStringToDouble( dblStructPtr->defaultVal, dblString,
    dblStructPtr->optID, &dblStructPtr->active, TRUE );
  dblStructPtr->optionDbl = limitDoubleValueToEqualOrWithinRange( dblStructPtr->optionDbl,
    dblStructPtr->mostNegLimit, dblStructPtr->mostPosLimit );
  return( dblStructPtr->active );
}


// Functions for Command Line Options Configuration from JSON Data
void  usage( struct config *  opt, char *  exeName )  {
  printf( "Usage:\n");
  printf( " %s [-a INT][-b INT][-C][-c][-D][-h][-m TXT][-N][-v][-V] [FILES]\n", exeName );
  printf( " %s %s\n", opt->a.optID, opt->a.helpStr ); /* after */
  printf( " %s %s\n", opt->b.optID, opt->b.helpStr ); /* before */
  printf( " %s %s\n", opt->C.optID, opt->C.helpStr ); /* clocks */
  printf( " %s %s\n", opt->c.optID, opt->c.helpStr ); /* compiler */
  printf( " %s %s\n", opt->D.optID, opt->D.helpStr ); /* debug */
  printf( " %s %s\n", opt->h.optID, opt->h.helpStr ); /* help */
  printf( " %s %s\n", opt->m.optID, opt->m.helpStr ); /* message */
  printf( " %s %s\n", opt->N.optID, opt->N.helpStr ); /* numbers */
  printf( " %s %s\n", opt->v.optID, opt->v.helpStr ); /* verbose */
  printf( " %s %s\n", opt->V.optID, opt->V.helpStr ); /* version */
}

void  initConfiguration ( struct config *  opt )  {
// after: optLng
  opt->a.active = FALSE;
  opt->a.optID = "-a";
  opt->a.helpStr = "INT .. output INT blank lines after hello - where 0 <= INT <= 10";
  opt->a.mostPosLimit = 10;
  opt->a.mostNegLimit = 0;
  opt->a.optionLng = 0;
  opt->a.defaultVal = 0;
// before: optInt
  opt->b.active = FALSE;
  opt->b.optID = "-b";
  opt->b.helpStr = "INT .. output INT blank lines before hello - where 0 <= INT <= 10";
  opt->b.mostPosLimit = 10;
  opt->b.mostNegLimit = 0;
  opt->b.optionInt = 0;
  opt->b.defaultVal = 0;
// clocks: optFlg
  opt->C.active = FALSE;
  opt->C.optID = "-C";
  opt->C.helpStr = "...... enable clock information in output";
// compiler: optFlg
  opt->c.active = FALSE;
  opt->c.optID = "-c";
  opt->c.helpStr = "...... enable compiler internal defines information in output";
// debug: optFlg
  opt->D.active = FALSE;
  opt->D.optID = "-D";
  opt->D.helpStr = "...... enable debug output mode";
// help: optFlg
  opt->h.active = FALSE;
  opt->h.optID = "-h";
  opt->h.helpStr = "...... this help / usage information";
// message: optStr
  opt->m.active = FALSE;
  opt->m.optID = "-m";
  opt->m.helpStr = "TXT .. output the TXT as a message after saying hello";
  opt->m.optionStr = "";
// numbers: optFlg
  opt->N.active = FALSE;
  opt->N.optID = "-N";
  opt->N.helpStr = "...... enable number size information in output";
// verbose: optFlg
  opt->v.active = FALSE;
  opt->v.optID = "-v";
  opt->v.helpStr = "...... enable more verbose information output";
// version: optFlg
  opt->V.active = FALSE;
  opt->V.optID = "-V";
  opt->V.helpStr = "...... enable version information output";
}

int  setConfiguration ( int  argc, char *  argv[], struct config *  opt )  {
  int c;

  opterr = 0;
  while ((c = getopt (argc, argv, OPTIONS )) != -1 ) {
    switch ( c ) {
      case 'a': configureLongOption( &opt->a, optarg ); break; /* after */
      case 'b': configureIntegerOption( &opt->b, optarg ); break; /* before */
      case 'C': opt->C.active = TRUE; break; /* clocks */
      case 'c': opt->c.active = TRUE; break; /* compiler */
      case 'D': opt->D.active = TRUE; break; /* debug */
      case 'h': opt->h.active = TRUE; break; /* help */
      case 'm': opt->m.active = TRUE; opt->m.optionStr = optarg; break; /* message */
      case 'N': opt->N.active = TRUE; break; /* numbers */
      case 'v': opt->v.active = TRUE; break; /* verbose */
      case 'V': opt->V.active = TRUE; break; /* version */
      case '?' : {
        if ( strchr( "abm", optopt ) != NULL ) {
          fprintf (stderr, "Error: Option -%c requires an argument.\n", optopt);
          switch ( optopt ) {
            case 'a': opt->a.active = FALSE; break;
            case 'b': opt->b.active = FALSE; break;
            case 'm': opt->m.active = FALSE; break;
          }
        }
        else if (isprint (optopt))
          fprintf (stderr, "Warning: Unknown option \"-%c\" ? - ignoring it!\n", optopt);
        else
          fprintf (stderr, "Warning: Unknown non-printable option character 0x%x ? - ignoring it!\n", optopt);
        break;
      }
    }
  }
  return( optind );
}

void  configuration_status( struct config *  opt )  {
  printf( "Debug: option -a is %sctive (-a %s)\n", (opt->a.active) ? "a" : "ina", opt->a.helpStr); /* after */
  printf( "Debug: option -a value is %ld, limits: %ld .. %ld\n", opt->a.optionLng, opt->a.mostNegLimit, opt->a.mostPosLimit); /* after */
  printf( "Debug: option -b is %sctive (-b %s)\n", (opt->b.active) ? "a" : "ina", opt->b.helpStr); /* before */
  printf( "Debug: option -b value is %d, limits: %d .. %d\n", opt->b.optionInt, opt->b.mostNegLimit, opt->b.mostPosLimit); /* before */
  printf( "Debug: option -C is %sctive (-C %s)\n", (opt->C.active) ? "a" : "ina", opt->C.helpStr); /* clocks */
  printf( "Debug: option -c is %sctive (-c %s)\n", (opt->c.active) ? "a" : "ina", opt->c.helpStr); /* compiler */
  printf( "Debug: option -D is %sctive (-D %s)\n", (opt->D.active) ? "a" : "ina", opt->D.helpStr); /* debug */
  printf( "Debug: option -h is %sctive (-h %s)\n", (opt->h.active) ? "a" : "ina", opt->h.helpStr); /* help */
  printf( "Debug: option -m is %sctive (-m %s)\n", (opt->m.active) ? "a" : "ina", opt->m.helpStr); /* message */
  printf( "Debug: option -m value is \"%s\"\n", opt->m.optionStr); /* message */
  printf( "Debug: option -N is %sctive (-N %s)\n", (opt->N.active) ? "a" : "ina", opt->N.helpStr); /* numbers */
  printf( "Debug: option -v is %sctive (-v %s)\n", (opt->v.active) ? "a" : "ina", opt->v.helpStr); /* verbose */
  printf( "Debug: option -V is %sctive (-V %s)\n", (opt->V.active) ? "a" : "ina", opt->V.helpStr); /* version */
}
