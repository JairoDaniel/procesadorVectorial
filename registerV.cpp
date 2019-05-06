 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

class RegisterV{
private:
	char reg[10][8];
	bool upperF, lowerF, regRD, regWR;
	int regA, regB;
public:
	void saveData(int,char*);
	char* readA();
	char* readB();
};

void RegisterV::saveData(int pregName, char* pdata){
	if(regWR==true){
		if(upperF==true){
			for (int i = 4; i < 8; i++)
					reg[pregName][i]=pdata[i-4];
		}
		else{
			for (int i = 0; i < 4; i++)
					reg[pregName][i]=pdata[i];
		}

	}
	

}

char* RegisterV::readA(){
	return reg[regA];
	
}

char* RegisterV::readB(){
	return reg[regB];
	
}
