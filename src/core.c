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

#include "core.h"
#include "mem.h"

static void skip_loop(FILE *code) {
    int opened_loops = 1;

    while (!feof(code) && opened_loops != 0) {
        int command = getc(code);

        if (command == '[') {
            opened_loops += 1;
        }
        else if (command == ']') {
            opened_loops -= 1;
        }
    }
}

void interpret_brainfuck(char *path) {
    FILE *code = fopen(path, "r");

    if (code == NULL) {
        fprintf(stderr, "Error: file does not exist\n");
        exit(1);
    }

    size_t buffer_size = 1000;
    int buffer_index = 0;
    char *buffer = allocate_memory(buffer_size);

    size_t loop_positions_size = 20;
    int loop_index = 0;
    int *loop_positions = allocate_memory(loop_positions_size);

    while (!feof(code)) {
        int command = fgetc(code);

        if (command == '>') {
            if (buffer_index == buffer_size - 1) {
                buffer = resize_buffer(buffer, &buffer_size);
            }

            buffer_index++;
        }
        else if (command == '<') {
            if (buffer_index == 0) {
                fprintf(stderr, "Error: buffer underflow detected\n");
                exit(1);
            }

            buffer_index--;
        }
        else if (command == '+') {
            buffer[buffer_index] += 1;
        }
        else if (command == '-') {
            buffer[buffer_index] -= 1;
        }
        else if (command == '.') {
            putc(buffer[buffer_index], stdout);
        }
        else if (command == ',') {
            buffer[buffer_index] = getc(stdin);
        }
        else if (command == '[') {
            if (!buffer[buffer_index]) {
                skip_loop(code);
            }
            else {
                loop_positions[loop_index] = ftell(code);
                loop_index += 1;
            }
        }
        else if (command == ']') {
            if (loop_index == 0) {
                fprintf(stderr, "Syntax error: unexpected ']'\n");
                exit(1);
            }

            if (buffer[buffer_index]) {
                fseek(code, loop_positions[loop_index - 1], SEEK_SET);
            }
            else {
                loop_index -= 1;
            }
        }
    }

    free(buffer);
    free(loop_positions);

    fclose(code);
}
