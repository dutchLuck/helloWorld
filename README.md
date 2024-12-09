# helloWorld
This code started out as Git newbie test drive code;
I have used RCS as a version control method, but it appears git is
the present and at least the near future. I have also used this
code to try out git's Actions to see what advantages the git provided
tools may have, even though this code is rather trivial.

This code has been expanded a number of times to test out
aspects of compiler configuration or operation. For example
it outputs a list of Pre-defined values known by the c compiler.

If this code is compiled with a -DCLOCKS options 
the code will output the resolution of various clocks
and timers provided by the compiler in combination
with the operating system.

Sample output from helloWorld on MacOS Sequoia 15.1.1 with -DCLOCKS used; -
'''

Hello World, courtesy of 'helloWorld'

'helloWorld' compiled from 'helloWorld.c', on Dec  9 2024 at 23:33:59
Now executing line 227 in function 'main'
Source File 'helloWorld.c' last Modified on Mon Dec  9 23:07:59 2024

__STDC__ defined - Compiler claims conformance to ISO Standard C.
__STDC_VERSION__ defined - Compiler claims conformance to ISO Standard C version 201710.
__STDC_HOSTED__ defined - Compiler claims support for entire standard library.
__GNUC__ defined as 4 - Compiled by gnu gcc or compatible compiler
__GNUC_MINOR__ defined as 2, __GNUC_PATCHLEVEL__ defined as 1
__VERSION__ defined - Compiler version 'Apple LLVM 16.0.0 (clang-1600.0.26.4)'

This compiler system doesn't define __unix__.
This compiler system doesn't define __linux__.
__APPLE__ defined - This compiler system claims to be an apple based system.
This compiler system doesn't define __CYGWIN__.
This compiler system doesn't define __OpenBSD__.
This compiler system doesn't define __FreeBSD__.
This compiler system doesn't define __MINGW32__.
This compiler system doesn't define __MINGW64__.
This compiler system claims to be a little endian based system.
The number of bits in a byte ("CHAR_BIT") is 8
The most negetive value of char ("CHAR_MIN") is -128
The most positive value of char ("CHAR_MAX") is 127
The maximum value of unsigned char ("UCHAR_MAX") is 255
The most negetive value of short int ("SHRT_MIN") is -32768
The most positive value of short int ("SHRT_MAX") is 32767
The maximum value of unsigned short int ("USHRT_MAX") is 65535
The most negetive value of int ("INT_MIN") is -2147483648
The most positive value of int ("INT_MAX") is 2147483647
The maximum value of unsigned int ("UINT_MAX") is 4294967295
The most negetive value of long int ("LONG_MIN") is -9223372036854775808
The most positive value of long int ("LONG_MAX") is 9223372036854775807
The maximum value of unsigned long int ("ULONG_MAX") is 18446744073709551615
The maximum value produced by rand() ("RAND_MAX") is 2147483647

This compiler/system has the following resolution timers/clocks; -
1000 [nS] resolution claimed for CLOCK_REALTIME
 CLOCK_REALTIME time is 1733747656.986469000 [S] i.e. Mon Dec  9 23:34:16 2024
 Time change noticed after 43 clock reads. Time stamp was 1733747656.986470000 [S] = Delta of 1000 [nS]

1000 [nS] resolution claimed for CLOCK_MONOTONIC
 CLOCK_MONOTONIC time is 716404.570205000 [S]
 Time change noticed after 15 clock reads. Time stamp was 716404.570206000 [S] = Delta of 1000 [nS]

42 [nS] resolution claimed for CLOCK_MONOTONIC_RAW
 CLOCK_MONOTONIC_RAW time is 716410.845156250 [S]
 Time change noticed after 1 clock reads. Time stamp was 716410.845156333 [S] = Delta of 83 [nS]

42 [nS] resolution claimed for CLOCK_MONOTONIC_RAW_APPROX
 CLOCK_MONOTONIC_RAW_APPROX time is 716410.845949333 [S]
 Time change noticed after 312 clock reads. Time stamp was 716410.845956250 [S] = Delta of 6917 [nS]

42 [nS] resolution claimed for CLOCK_UPTIME_RAW
 CLOCK_UPTIME_RAW time is 98852.545927000 [S]
 Time change noticed after 1 clock reads. Time stamp was 98852.545927083 [S] = Delta of 83 [nS]

42 [nS] resolution claimed for CLOCK_UPTIME_RAW_APPROX
 CLOCK_UPTIME_RAW_APPROX time is 98852.545938833 [S]
 Time change noticed after 44569 clock reads. Time stamp was 98852.546801916 [S] = Delta of 863083 [nS]

1000 [nS] resolution claimed for CLOCK_PROCESS_CPUTIME_ID
 CLOCK_PROCESS_CPUTIME_ID time is 0.014877000 [S]
 Time change noticed after 1 clock reads. Time stamp was 0.014879000 [S] = Delta of 2000 [nS]

42 [nS] resolution claimed for CLOCK_THREAD_CPUTIME_ID
 CLOCK_THREAD_CPUTIME_ID time is 0.014883291 [S]
 Time change noticed after 1 clock reads. Time stamp was 0.014883708 [S] = Delta of 417 [nS]

The clock_gettime() function uses "struct timespec" (16 bytes) to store nS time.
The gettimeofday() function uses "struct timeval" (16 bytes) to store uS time.
'''
