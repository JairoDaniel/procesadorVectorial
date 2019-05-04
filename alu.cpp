 #include <stdint.h>
class Alu{
private:
	uint8_t a, b, op;
	uint8_t addV();
	uint8_t xorV();
	uint8_t subV();
	uint8_t sclV();
	uint8_t scrV();
public:
	Alu():a(0),b(0), op(0){}
	void setData(uint8_t, uint8_t, uint8_t);
	uint8_t function();
	
	
};

uint8_t Alu::function(){
	switch(op){
		case 0:
			addV();
			break;
		case 1:
			subV();
			break;
		case 2:
			xorV();
			break;
		case 3:
			sclV();
			break;
		case 4:
			scrV();
			break;
		default:
			return 0;
			break;
	}
}


void Alu::setData(uint8_t pA, uint8_t pB, uint8_t pOp){
		a = pA;
		b= pB;
		op=pOp;
	}

uint8_t Alu::addV(){
		return a+b;
	}
uint8_t Alu::xorV(){
	return a^b;
}
uint8_t Alu::subV(){
		return a-b;
	}

uint8_t Alu::sclV(){
	uint8_t temp;
	int8_t i;
	for (i = 0; i < b; i++){
		temp = a>>7;
		a=a<<1;
		a+=temp;
	}
	return a;
}

uint8_t Alu::scrV(){
	uint8_t temp;
	int8_t i;
	for (i = 0; i < b; i++){
		temp = a&1;
		temp=temp<<7;
		a=a>>1;
		a+=temp;
	}
	return a;
}