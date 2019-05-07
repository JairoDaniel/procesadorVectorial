 #include <stdint.h>

class Bus8{
private:
	char data;
public:
	Bus8():data(0){}
	char getData();
	void setData(char)

};

void Bus8::setData(char pData){
	data=pData;
}

char Bus8::getData(){
	return data;
}