# DSA
Repository for Data Structures and Algorithms

## Explanation

Architecture Selection (ARCH):

By default, the architecture is set to x86, but you can specify ARCH=ARM when running make to build for ARM (32-bit).
The compiler and flags are chosen based on the ARCH variable:
For x86: gcc with -m32 or -m64 (controlled using BITS flag) .
For ARM: arm-linux-gnueabi-gcc (cross-compiler for ARM).


Separate Build Directory (build):

Object files are stored in build/run/.
Assembly files are generated in build/asm/, but only if the --asm flag is passed.


Generating Object Files:

Object files for src/*.c and app/*.c are compiled and placed in the build/run/ directory.
The OBJ_FILES variable is automatically populated by transforming .c file paths into .o file paths.


Generating Assembly Files:

If ASM_FLAG=--asm is provided, the assembly files will be generated in the build/asm/ directory.
Make Targets:

all: Compiles the object files and links them to create the final binary in build/app_binary.
asm: Generates assembly files if the --asm flag is passed.
clean: Cleans up the build/ directory by removing all compiled files and directories.