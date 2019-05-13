#include <array>

class Bus64{
private:
	std::array<unsigned char,8> data;
public:
	std::array<unsigned char,8> getData();
	void setData(std::array<unsigned char,8>);

};

void Bus64::setData(std::array<unsigned char,8> pData){
	for(int i=0; i<8; i++){
		data[i]=pData[i];		
	}
	
}

std::array<unsigned char,8> Bus64::getData(){
	return data;
}