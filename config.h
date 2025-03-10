/*
 * C O N F I G . H
 *
 * Last Modified on Mon Mar 10 15:08:59 2025
 *
 */

#include <stdio.h>

#ifndef  CONFIG_H
#define  CONFIG_H

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE (!(FALSE))
#endif

struct positionParam {
  char *  paramNameStr;
  char *  helpStr;
};

struct optFlg {
  int active;
  char *  optID;
  char *  helpStr;
};

struct optChr {
  int active;
  char *  optID;
  char *  helpStr;
  int  optionChr;
};

struct optStr {
  int active;
  char *  optID;
  char *  helpStr;
  char *  optionStr;
};

struct optInt {
  int active;
  char *  optID;
  char *  helpStr;
  int defaultVal;
  int mostPosLimit;
  int mostNegLimit;
  int optionInt;
};

struct optLng {
  int active;
  char *  optID;
  char *  helpStr;
  long defaultVal;
  long mostPosLimit;
  long mostNegLimit;
  long optionLng;
};

struct optDbl {
  int active;
  char *  optID;
  char *  helpStr;
  double defaultVal;
  double mostPosLimit;
  double mostNegLimit;
  double optionDbl;
};

// Command Line Options Configuration Data
struct config {
  struct optLng a;  /* (after) INT .. output INT blank lines after hello - where 0 <= INT <= 10 */
  struct optInt b;  /* (before) INT .. output INT blank lines before hello - where 0 <= INT <= 10 */
  struct optFlg C;  /* (clocks) ...... enable clock information in output */
  struct optFlg c;  /* (compiler) ...... enable compiler internal defines information in output */
  struct optFlg D;  /* (debug) ...... enable debug output mode */
  struct optFlg h;  /* (help) ...... this help / usage information */
  struct optStr m;  /* (message) TXT .. output the TXT as a message after saying hello */
  struct optFlg N;  /* (numbers) ...... enable number size information in output */
  struct optFlg v;  /* (verbose) ...... enable more verbose information output */
  struct optFlg V;  /* (version) ...... enable version information output */
};

// getopt() option string
#define OPTIONS "a:b:CcDhm:NvV"

void  usage ( struct config *  optStructPtr, char *  exeName );
void  initConfiguration ( struct config *  optStructPtr );
int  setConfiguration ( int  argc, char *  argv[], struct config *  optStructPtr );
void  configuration_status( struct config *  opt );

#endif
