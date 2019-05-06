 #include <stdint.h>

class Bus8{
private:
	int8_t data;
public:
	Bus8():data(0){}
	int8_t getData();
	void setData(int8_t)

};

void Bus8::setData(int8_t pData){
	data=pData;
}

int8_t Bus8::getData(){
	return data;
}