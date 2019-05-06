 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

class MemoryD{
private:
	char mem[20000][4];
public:
	void saveData(int,char*);
	char* readData(int);
};

void MemoryD::saveData(int pposMem, char pdata[4]){
	for (int i = 0; i < 4; i++){
		mem[pposMem][i]= pdata[i];
	}

}

char* MemoryD::readData(int pposMem){
	usleep(1);
	return mem[pposMem];
}


