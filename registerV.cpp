 #include <stdint.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <array>

class RegisterV{
private:
	std::array<std::array<char,8>,10> reg;
	bool upperF, lowerF, regRD, wrF, wrFO;
	int8_t regA, regB, regWR;
public:
	RegisterV():regWR(0), regA(0), regB(0), upperF(false), lowerF(false), wrF(false), wrFO(false),regRD(false){
		reg[1]={(char)10,(char)10,(char)10,(char)10,(char)10,(char)10,(char)10,(char)10};
		reg[2]={3,3,3,3,3,3,3,3};
	} 
	void write(std::array<char,4>);
	void writeOp(std::array<char,8>);
	std::array<char,8> readA();
	std::array<char,8> readB();
	void setA(int8_t);
	void setB(int8_t);
	void setWR(int8_t);
	void setFlags(bool, bool, bool, bool, bool);
	std::array<char,4> readStore();
	void printV(int);
};

void RegisterV::write(std::array<char,4> pdata){
	if(wrF==true){
		if(upperF==true){
			for (int i = 3; i >=0 ; i--)
					reg[regWR][i]=pdata[i];
		}
		else{
			for (int i = 7; i >= 4; i--)
				reg[regWR][i]=pdata[i-4];
		}
	}
}

void RegisterV::writeOp(std::array<char,8> pdata){
	if(wrFO==true){
		for(int i=0; i<8; i++)
			reg[regWR][i]=pdata[i];
	}
}

std::array<char,8> RegisterV::readA(){
	std::array<char,8> temp = {0,0,0,0,0,0,0,0};
	if(regRD==true){
		temp=reg[regA];
	}

	return temp;
	
}

std::array<char,8> RegisterV::readB(){
	std::array<char,8> temp = {0,0,0,0,0,0,0,0};
	if(regRD==true){
		temp=reg[regB];
	}

	return temp;
	
}

std::array<char,4> RegisterV::readStore(){
	std::array<char,4> temp = {0,0,0,0};
		if(regRD==true){
			if(upperF==true){
			for (int i = 3; i >=0 ; i--)
				temp[i]=reg[regA][i];
		}
		else{
			for (int i = 7; i >= 4; i--)
				temp[i-4]=reg[regA][i];
		}
	}
	
	return temp;
}

void RegisterV::setWR(int8_t pregWr){
	regWR=pregWr;
}

void RegisterV::setA(int8_t pregA){
	regA=pregA;
}

void RegisterV::setB(int8_t pregB){
	regB=pregB;
}

void RegisterV::setFlags(bool pUpper, bool pLower, bool pregRD, bool pwrF, bool pwrFO){
	upperF=pUpper;
	lowerF=pLower;
	regRD=pregRD;
	wrF=pwrF;
	wrFO=pwrFO;
}

void RegisterV::printV(int t){
	for(int i=0; i<8; i++){
		printf("%d  ", reg[t][i]);
	}
}