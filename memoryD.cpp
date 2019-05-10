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
	void saveData(int,std::array<unsigned char,4>);
	std::array<unsigned char,4> readData(int);
};

void MemoryD::saveData(int pposMem, std::array<unsigned char,4> pdata){
	for (int i = 0; i < 4; i++){
		mem[pposMem+i]= pdata[i];
	}

}

std::array<unsigned char,4> MemoryD::readData(int pposMem){
	std::array<unsigned char,4> temp;
	for(int i = 0; i < 4; i++){
		usleep(1);
		temp[i]=mem[pposMem+i];
	}

	return temp;
}

