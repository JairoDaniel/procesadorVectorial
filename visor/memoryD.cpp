 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <array>

class MemoryD{
private:
	std::array<unsigned char, 10000> mem;
public:	
	void saveData(int,unsigned char);
	unsigned char readData(int);
};

void MemoryD::saveData(int pposMem, unsigned char pdata){
	usleep(4);
	mem[pposMem]= pdata;
}

unsigned char MemoryD::readData(int pposMem){
	usleep(4);
	return mem[pposMem];
}

