# helloWorld
C language code to output "hello, world" has been around a long time,
and was used as the example code in Chapter 1.1 Getting Started in
the 1978 book "The C Programming Language" by Kernighan and Ritchie.
In that chapter they state "The first program to write is the same
for all languages: Print the words  hello, world". Even if exceptions
are found to this statement the hello world program has proved a
popular thing in programming for over four decades. It is sometimes
used as a check that a new compiler/interepreter and/or associated
software environment has been correctly installed and is able to
produce the expected results. Indeed the Rust language automatically
generates a hello world program in the first stage of setting up the
development environment for a new program.

This helloWorld code was adapted from a predecessor, that used a few
predefined compiler macros to enhance the hello world output, so as
to become a Git newbie test drive program.
I have used RCS as a version control method, but it appears Git is
the present and at least the near future. I have also used this
code to try out Github's "Actions" to see what advantages the Github
provided tools may have, even though this code is rather trivial
to be a Github Project.

This code has been expanded a number of times to test out
aspects of C compiler configuration or operation. For example
it can output a list of Pre-defined values known by the compiler.
Most recently this project has been modified to use an automated
method to generate the code to handle options. A set of options
is specified in a json file and makes adding new options relatively
easy.

If this code is compiled with a -DCLOCKS option and run with 
a -C option the code will output the resolution of various clocks
and timers provided by the compiler system in combination
with the operating system.

At the most rudimentary level of having a working C compiler
on a UNIX or linux like system this code can be compiled from
the command line with; -
```
cc -DCLOCKS -o helloWorld helloWorld.c config.c genFun.c
```
and run by typing; -
```
./helloWorld
```
If the user environment has git, make and bash in addition to
the cc compiler, then helloWorld on this Github can be cloned
and run in the users environment with the folowing recipe; -
```
git clone https://github.com/dutchLuck/helloWorld
cd helloWorld
./configure
make
make check
```
An example of the default output from helloWorld is; -
```
% ./helloWorld        
Hello World!
% 
```
The helloWorld program has a number of options available; -
```
% ./helloWorld -h
Usage:
 helloWorld [-a INT][-b INT][-C][-c][-D][-h][-m TXT][-N][-v][-V] [FILES]
 -a INT .. output INT blank lines after hello - where 0 <= INT <= 10
 -b INT .. output INT blank lines before hello - where 0 <= INT <= 10
 -C ...... enable clock information in output
 -c ...... enable compiler internal defines information in output
 -D ...... enable debug output mode
 -h ...... this help / usage information
 -m TXT .. output the TXT as a message after saying hello
 -N ...... enable number size information in output
 -v ...... enable more verbose information output
 -V ...... enable version information output
Hello World!
%
```
Some of the options in use are; -
```
% ./helloWorld -v -b1 -a1 -m "Bye, see you later"
helloWorld version 0v9

Hello World, courtesy of 'helloWorld'

Bye, see you later
%
```
The information options on a MacOS Sequoia system output; -
```
% ./helloWorld -c -C -N                          
Hello World!
'helloWorld' compiled from 'helloWorld.c', on Mar  5 2025 at 21:07:55
Now executing line 100 in function 'main'
Source File 'helloWorld.c' last Modified on Wed Mar  5 21:07:37 2025

__STDC__ defined - Compiler claims conformance to ISO Standard C.
__STDC_VERSION__ defined - Compiler claims conformance to ISO Standard C version 201710.
__STDC_HOSTED__ defined - Compiler claims support for entire standard library.
__GNUC__ defined as 4 - Compiled by gnu gcc or compatible compiler
__GNUC_MINOR__ defined as 2, __GNUC_PATCHLEVEL__ defined as 1
__VERSION__ defined - Compiler version 'Apple LLVM 16.0.0 (clang-1600.0.26.6)'

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
 CLOCK_REALTIME time is 1741173224.967535000 [S] i.e. Wed Mar  5 21:13:44 2025
 Time change noticed after 23 clock reads. Time stamp was 1741173224.967536000 [S] = Delta of 1000 [nS]

1000 [nS] resolution claimed for CLOCK_MONOTONIC
 CLOCK_MONOTONIC time is 101904.294324000 [S]
 Time change noticed after 15 clock reads. Time stamp was 101904.294325000 [S] = Delta of 1000 [nS]

42 [nS] resolution claimed for CLOCK_MONOTONIC_RAW
 CLOCK_MONOTONIC_RAW time is 101909.405377250 [S]
 Time change noticed after 1 clock reads. Time stamp was 101909.405377291 [S] = Delta of 41 [nS]

42 [nS] resolution claimed for CLOCK_MONOTONIC_RAW_APPROX
 CLOCK_MONOTONIC_RAW_APPROX time is 101909.405388583 [S]
 Time change noticed after 102 clock reads. Time stamp was 101909.405391750 [S] = Delta of 3167 [nS]

42 [nS] resolution claimed for CLOCK_UPTIME_RAW
 CLOCK_UPTIME_RAW time is 22980.669270250 [S]
 Time change noticed after 1 clock reads. Time stamp was 22980.669270291 [S] = Delta of 41 [nS]

42 [nS] resolution claimed for CLOCK_UPTIME_RAW_APPROX
 CLOCK_UPTIME_RAW_APPROX time is 22980.669279125 [S]
 Time change noticed after 12057 clock reads. Time stamp was 22980.669671458 [S] = Delta of 392333 [nS]

1000 [nS] resolution claimed for CLOCK_PROCESS_CPUTIME_ID
 CLOCK_PROCESS_CPUTIME_ID time is 0.005502000 [S]
 Time change noticed after 1 clock reads. Time stamp was 0.005503000 [S] = Delta of 1000 [nS]

42 [nS] resolution claimed for CLOCK_THREAD_CPUTIME_ID
 CLOCK_THREAD_CPUTIME_ID time is 0.005513750 [S]
 Time change noticed after 1 clock reads. Time stamp was 0.005514083 [S] = Delta of 333 [nS]

The clock_gettime() function uses "struct timespec" (16 bytes) to store nS time.
The gettimeofday() function uses "struct timeval" (16 bytes) to store uS time.
%
```
