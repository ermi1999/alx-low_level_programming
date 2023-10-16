#!/bin/bash
gcc -Wall -Wextra -Werror -c -fPIC *.c
gcc -shared -o liball.so *.o
