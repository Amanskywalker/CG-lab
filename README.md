# Computer Graphic Lab Manual

Written according to linux system (Written on Ubuntu 14.04)

## Installation of OpneGL
  For installation instruction visit [http://www.prinmath.com/csci5229/misc/install.html](http://www.prinmath.com/csci5229/misc/install.html) 

## Instruction to Execute program

 - Navigate to the dir CG-lab/
 - Execute the `make` command
 - The Executable File with the same name as of Source file will be formed

### To Manually Compile a single Program  
 - For C `gcc -o <output filename> <filename>.c -lglut -lGLU -lGL`
 - For C++ `g++ -o <output filename> <filename>.cpp -lglut -lGLU -lGL`

## Additional Instructions for Specific Programs
### lp1
  - Can Override the n value (default = 0) by passing a number as commnd line parameter
    eg: `./lp1 3` where n=3
