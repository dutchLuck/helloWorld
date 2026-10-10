@Echo off
Rem
Rem Build the helloWorld_vc.exe executable using Microsoft C compiler
Rem
cl /Wall /FehelloWorld_vc.exe getopt.c config.c genFun.c helloWorld.c
