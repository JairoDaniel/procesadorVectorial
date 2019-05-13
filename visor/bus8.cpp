 #include <stdint.h>

class Bus8{
private:
	unsigned char data;
public:
	Bus8():data(0){}
	unsigned char getData();
    void setData(unsigned char);

};

void Bus8::setData(unsigned char pData){
	data=pData;
}

unsigned char Bus8::getData(){
	return data;
}
