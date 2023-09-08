#!/bin/bash

set -xe

gcc -Wall -Wextra -std=c11 -pedantic -ggdb params.c rotas.c main.c -o chr
