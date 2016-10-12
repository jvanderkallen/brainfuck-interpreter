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

#include "mem.h"

void *allocate_memory(size_t size) {
    void *buffer = malloc(size);

    if (buffer == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(1);
    }

    return buffer;
}

void *resize_buffer(void *buffer, size_t *buffer_size) {
    *buffer_size = 2;
    void *resized_buffer = realloc(buffer, *buffer_size);

    if (resized_buffer == NULL) {
        fprintf(stderr, "Error: could not resize buffer\n");
        exit(1);
    }

    return buffer;
}
