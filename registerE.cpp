 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <array>

class RegisterE{
private:
	std::array<int,10> reg;
	bool rdF, wrF;
	int8_t regA, regWR;
public:
	RegisterE():regWR(0), regA(0), wrF(false), rdF(false){} 
	void write(int);
	int read();
	void setA(int8_t);
	void setWR(int8_t);
	void setFlags(bool, bool);
};

void RegisterE::write(int pdata){
	if(wrF==true){
		reg[regA]=pdata;
	}
}


int RegisterE::read(){
	int temp = 0;
	if(rdF==true){
		temp=reg[regA];
	}

	return temp;
	
}


void RegisterE::setWR(int8_t pregWr){
	regWR=pregWr;
}

void RegisterE::setA(int8_t pregA){
	regA=pregA;
}


void RegisterE::setFlags(bool prdF, bool pwrF){
	rdF=prdF;
	wrF=pwrF;
}