#include <stdlib.h> 
#include "constants.h"
#include "memoryD.cpp"	
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
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
    	Mat image;
		
		image = imread( "./Resources/original96.jpg", 1 );
		Mat gray_image;
 		cvtColor( image, gray_image, CV_BGR2GRAY );
 		std::array<unsigned char,4> pdata= {0,0,0,0};
 		int cont=0;
 		int posMem = 0;
 		for (int i=0; i<gray_image.rows; i++){
 			for(int j=0; j<gray_image.cols; j++){
 					mem1->saveData(posMem, gray_image.at<unsigned char>(i,j));
 					posMem++;
 			}
 		}
 		pdata[0]=255;
 		pdata[1]=20;
 		pdata[2]=68;
 		pdata[3]=145;
 		for(int i=0; i<4; i++)
 			mem1->saveData(9216+i, pdata[i]);
 		pdata[0]=89;
 		pdata[1]=200;
 		pdata[2]=45;
 		pdata[3]=9;
 		for(int i=0; i<4; i++)
 			mem1->saveData(9220+i, pdata[i]);

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
	std::array<unsigned char,4> readData();
	void storeData(std::array<unsigned char,4>);
	

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

std::array<unsigned char,4> LoadStoreUnit::readData(){
	std::array<unsigned char,4> temp = {0,0,0,0};
	if(RD==true){
		if(flagM == 0){
			if(direction<BASEM2){
				for (int i = 0; i < 4; i++)
					temp[i]=mem1->readData(direction+i);
			}
			else{
				for (int i = 0; i < 4; i++)
					temp[i]=mem2->readData(direction-BASEM2+i);
			}
		}
		else{
			if(direction<BASEM2){
				for (int i = 0; i < 4; i++)
					temp[i]=mem3->readData(direction+i);
			}
			else{
				for (int i = 0; i < 4; i++)
					temp[i]=mem4->readData(direction-BASEM2+i);
			}
		}
	}
	return temp;
}

void LoadStoreUnit::storeData(std::array<unsigned char,4> dataV){
	if(WR==true){
		if(flagM == 0){
			if(direction<BASEM2){
				for (int i = 0; i < 4; i++)
					mem1->saveData(direction+i, dataV[i]);
			}
			else{
				for (int i = 0; i < 4; i++)
					mem2->saveData(direction-BASEM2+i, dataV[i]);
			}
		}
		else{
			if(direction<BASEM2){
				for (int i = 0; i < 4; i++)
					mem3->saveData(direction+i, dataV[i]);
			}
			else{
				for (int i = 0; i < 4; i++)
					mem4->saveData(direction-BASEM2+i, dataV[i]);
			}
		}
	}
}


