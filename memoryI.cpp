#include <fstream>
#include <iostream>
#include <string>
#include <array>

class MemoryI{
private:
	int direction;
	std::array<int,42000>data;
public:
	MemoryI(): direction(0){
		std::ifstream file("binary.txt");
		if (file.is_open()) {
			std::string line;
			int i=0;
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