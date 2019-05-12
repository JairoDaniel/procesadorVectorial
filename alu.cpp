 #include <stdint.h>
class Alu{
private:
	uint8_t op;
	unsigned char a, b;
	unsigned char addV();
	unsigned char xorV();
	unsigned char subV();
	unsigned char sclV();
	unsigned char scrV();
public:
	Alu():a(0),b(0), op(0){}
	void setData(unsigned char, unsigned char);
	void setOp(uint8_t);
	unsigned char function();
	
	
};

unsigned char Alu::function(){
	switch(op){
		case 0:
			return addV();
		case 1:
			return subV();
		case 2:
			return xorV();
		case 3:
			return sclV();
		case 4:
			return scrV();
		default:
			return 0;
	}
}


void Alu::setData(unsigned char pA, unsigned char pB){
		a = pA;
		b= pB;
}

void Alu::setOp(uint8_t pOp){
		op=pOp;
}

unsigned char Alu::addV(){
		return a+b;
	}
unsigned char Alu::xorV(){
	return a^b;
}
unsigned char Alu::subV(){
		return a-b;
	}

unsigned char Alu::sclV(){
	unsigned char temp;
	uint8_t i;
	for (i = 0; i < b; i++){
		temp = a>>7;
		a=a<<1;
		a+=temp;
	}
	return a;
}

unsigned char Alu::scrV(){
	unsigned char temp;
	uint8_t i;
	for (i = 0; i < b; i++){
		temp = a&1;
		temp=temp<<7;
		a=a>>1;
		a+=temp;
	}
	return a;
}