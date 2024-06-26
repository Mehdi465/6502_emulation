#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;


struct Mem{
    static constexpr MAX_MEM = 1024*64;
    Byte Data[MAX_MEM];

    void Initialize(){
        for (u32 i=0;i<MAX_MEM;i++){
            Data[i] = 0;
        }
    }

};


struct CPU {

    
    Word PC;    // Program counter 
    Word SP;    // Stack Pointer
    
    Byte A,X,Y;     //Accumulator  

    Byte C : 1;     // Carry Flag
    Byte Z : 1;     // Zero Flag
    Byte I : 1;     // Interrupt Flag
    Byte D : 1;     // Decimal Mode
    Byte B : 1;     // Break command
    Byte V : 1;     // Overflow flag
    Byte N : 1;     // Negative Flag

    void Reset(Mem& memory){
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;

        memory.Initialize();
    }



};




int main(){
    Mem mem;
    CPU cpu;

    cpu.Reset(mem);

    return 0;
}