# Three Language Quine Relay

quine.c is a C program which generates a Java programme which generates a Python programme which generates quine2.c - a programme with identical code to quine.c. This project was heavily inspired by Yusuke Endoh's [128 step quine relay](https://github.com/mame/quine-relay.git) who has made some amazing obfuscation and metaprogramming programmes and I encourage you to check him out. 

# How to use

You can either manually compile and run each step of the quine relay or run "make" with the Makefile in your directory to automate this process. Note that the Makefile uses gcc to compile.

# Details

The code itself is crude but functional, it inserts the original C code into a Python payload which is inserted into a Java payload. All of these payloads are wrapped by escape characters to ensure they are preserved and do not interfere with external code. I used my [text escape tool](https://github.com/TheoKritzinger/text-escape-tool.git) to automate this process depending on how many layers the payload needs to be protected from. 
