#include "alu.cpp"
#include "iostream"
 #include <stdint.h>

int main() { 
  
    // Declare an object of class geeks 
    Alu *alu1 = new Alu(); 
  
    // accessing data member 
    alu1->setData(5,1,0);
  
    uint8_t c;
    c = alu1->function();
    std::cout << "add: " << unsigned(c) <<std::endl; 
    alu1->setData(5,1,1);
    c = alu1->function();
    std::cout << "sub: " << unsigned(c) <<std::endl; 
    alu1->setData(5,1,2);
    c = alu1->function();
    std::cout << "xor: " << unsigned(c) <<std::endl; 
    alu1->setData(5,1,3);
    c = alu1->function();
    std::cout << "scl: " << unsigned(c) <<std::endl; 
    alu1->setData(5,1,4);
    c = alu1->function();
    std::cout << "scr: " << unsigned(c) <<std::endl; 
    return 0; 
} 