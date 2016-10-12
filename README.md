# Brainfuck Interpreter
This is an interpreter for the Brainfuck language.

The interpreter uses a cell size of 8 bits. If a buffer underflow is detected the program will quit. The buffer of cells grows dynamically if the buffer is full.

## Building
Run the following commands in the root of the project to build the program:

```
mkdir build
cd build
cmake ..
make
```

Optionally you may want to run `sudo make install` to install the program on your system. Run `sudo xargs rm < install_manifest.txt` to remove it.

## Usage
The program takes a single argument: the path of a file containing Brainfuck code.