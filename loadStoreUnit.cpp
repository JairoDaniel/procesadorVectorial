#include <stdlib.h> 
#include "constants.h"
#include "memoryD.cpp"

class LoadStoreUnit{
private:
	MemoryD * mem1;
	MemoryD * mem2;
	MemoryD * mem3;
	MemoryD * mem4;

	int direction;
	int8_t flagM;
	bool RD, WR;
	int8_t regWR;


public:
	LoadStoreUnit():
		direction(0), flagM(2), RD(false), WR(false), regWR(0){

    	mem1 = new MemoryD();
    	mem2 = new MemoryD();
    	mem3 = new MemoryD();
    	mem4 = new MemoryD();
		}
	void setDir(int);
	void setRegWR(int8_t);
	void setFlagM(int8_t);
	void setRD(bool);
	void setWR(bool);
	int8_t getFlagM();
	bool getRD();
	bool getWR();
	int getDir();
	std::array<char,4> readData();
	void storeData(std::array<char,4>);

};

void LoadStoreUnit::setDir(int pdirection){
	direction=pdirection;
}

void LoadStoreUnit::setRegWR(int8_t pregWR){
	regWR=pregWR;
}

void LoadStoreUnit::setFlagM(int8_t pflagM){
	flagM=pflagM;
}

void LoadStoreUnit::setRD(bool pRD){
	RD=pRD;
}

void LoadStoreUnit::setWR(bool pWR){
	WR=pWR;
}

int LoadStoreUnit::getDir(){
	return direction;
}

int8_t LoadStoreUnit::getFlagM(){
	return flagM;
}

bool LoadStoreUnit::getRD(){
	return RD;
	
}

bool LoadStoreUnit::getWR(){
	return WR;
}

std::array<char,4> LoadStoreUnit::readData(){
	if(RD==true){
		if(flagM == 0){
			if(direction<BASEM2)
				return mem1->readData(direction);
			else
				return mem2->readData(direction-BASEM2);
		}
		else{
			if(direction<BASEM3)
				return mem3->readData(direction);
			else
				return mem4->readData(direction-BASEM4);
		}
	}
}

void LoadStoreUnit::storeData(std::array<char,4> dataV){
	if(WR==true){
		if(flagM == 0){
			if(direction<BASEM2)
				mem1->saveData(direction, dataV);
			else
				mem2->saveData(direction-BASEM2, dataV);
		}
		else{
			if(direction<BASEM3)
				mem3->saveData(direction, dataV);
			else
				mem4->saveData(direction-BASEM4, dataV);
		}
	}
}


