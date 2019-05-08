 #include <stdint.h>

class Mux218b{
private:
	uint8_t flag, a, b;
public:
	Mux218b():flag(0), a(0), b(0){};
	void setA(uint8_t);
	void setB(uint8_t);
	void setFlag(uint8_t);
	int getValue();

};

void Mux218b::setA(uint8_t pA){
	a=pA;
}

void Mux218b::setB(uint8_t pB){
	b=pB;
}

void Mux218b::setFlag(uint8_t pFlag){
	flag=pFlag;
}

int Mux218b::getValue(){
	if(flag==0)
		return a;
	else
		return b;
}