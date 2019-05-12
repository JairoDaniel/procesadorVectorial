 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <array>

class MemoryD{
private:
	std::array<unsigned char, 20000> mem;
public:	
	void saveData(int,unsigned char);
	unsigned char readData(int);
};

void MemoryD::saveData(int pposMem, unsigned char pdata){
	usleep(1);
	mem[pposMem]= pdata;
}

unsigned char MemoryD::readData(int pposMem){
	usleep(1);
	return mem[pposMem];
}

