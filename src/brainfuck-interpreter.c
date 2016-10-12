/*
Copyright (C) 2016 Joris van der Kallen

This file is part of Brainfuck Interpreter.

Brainfuck Interpreter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Brainfuck Interpreter is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
                        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Brainfuck Interpreter.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"

void usage(char *executable) {
    printf("Usage: %s <filename>\n", executable);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 2 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        usage(argv[0]);
    }

    interpret_brainfuck(argv[1]);

    return 0;
}