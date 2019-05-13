 #include <stdint.h>

class Mux21{
private:
	uint8_t flag;
	int a, b;
public:
	Mux21():flag(0), a(0), b(0){};
	void setA(int);
	void setB(int);
	void setFlag(uint8_t);
	int getValue();

};

void Mux21::setA(int pA){
	a=pA;
}

void Mux21::setB(int pB){
	b=pB;
}

void Mux21::setFlag(uint8_t pFlag){
	flag=pFlag;
}

int Mux21::getValue(){
	if(flag==0)
		return a;
	else
		return b;
}