#include <fstream>
#include <iostream>
#include <string>
#include <array>

class MemoryI{
private:
	int direction;
	std::array<int,42000>data;
public:
    int i=0;
	MemoryI(char alg): direction(0){
        std::ifstream file;
		if(alg=='0')
            file.open("/home/jairo/Desktop/gui/visor/SRCode.txt");
		else if(alg=='1')
            file.open("/home/jairo/Desktop/gui/visor/xorCode.txt");
		else if(alg=='2')
            file.open("/home/jairo/Desktop/gui/visor/shiftCode.txt");
		if (file.is_open()) {
            std::string line;
	        while (getline(file, line)) {
                data[i]=std::stoi(line.c_str(),nullptr,2);
	        	i++;
	        }
	        file.close();
	    }
	}
	void setDir(int);
	int readMem();
	void printM();

};

void MemoryI::setDir(int pDir){
	direction=pDir;
}

int MemoryI::readMem(){
	return data[direction];
}
