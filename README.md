# Assembler for HACK Assembly Language

* Implemented an assembler for [build a computer](https://www.coursera.org/learn/build-a-computer) course on coursera.  
* Hack assembly Language specification [[1]](http://nand2tetris-questions-and-answers-forum.32033.n3.nabble.com/Introduction-to-Hack-Assembly-Language-td4032232.html), [[2]](http://nand2tetris-questions-and-answers-forum.32033.n3.nabble.com/Introduction-to-Hack-Assembly-Language-td4032232.html)    

# Compile Instruction

    mkdir build
    cd build
    cmake ..
    make 

* Binary is created in `/bin` folder

# Usage

    ./hack_assembler -i [input filename] -o [output filename]

* input file must be `.asm` file
* output file generated will be with suffix `.hack`

# How to run assembled programs

* Download [software package](https://www.nand2tetris.org/software) for this course.
* run `tools/CPUSimulator.sh`.
* Load the compiled `.hack` files to run them.