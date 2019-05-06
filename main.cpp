#include "pc.cpp"
#include "adder.cpp"
#include "mux21.cpp"
#include "bus32.cpp"
#include "memoryI.cpp"

#include "memoryD.cpp"
#include "registerV.cpp"
#include "alu.cpp"
#include "iostream"
#include <bits/stdc++.h> 
#include <stdint.h>
#include <fstream>


Pc * pc;
Adder *sum;
Mux21 *muxPc;
Bus32 * busPcOut;
MemoryI * memI ;

void connections(){
    busPcOut->setData(pc->getPc());
    sum->add(busPcOut->getData(), 1);
    muxPc->setA(busPcOut->getData());
    muxPc->setB(sum->getResult());
    pc->setPc(muxPc->getValue());
    memI->setDir(busPcOut->getData());

}

int main() { 
    pc = new Pc();
    sum = new Adder();
    muxPc = new Mux21();
    busPcOut= new Bus32();    
    memI = new MemoryI();

    connections();
    return 0; 
} 