 #include <stdint.h>
class Alu{
private:
	uint8_t op;
	char a, b;
	char addV();
	char xorV();
	char subV();
	char sclV();
	char scrV();
public:
	Alu():a(0),b(0), op(0){}
	void setData(uint8_t, uint8_t);
	void setOp(uint8_t);
	char function();
	
	
};

char Alu::function(){
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


void Alu::setData(uint8_t pA, uint8_t pB){
		a = pA;
		b= pB;
}

void Alu::setOp(uint8_t pOp){
		op=pOp;
}

char Alu::addV(){
		return a+b;
	}
char Alu::xorV(){
	return a^b;
}
char Alu::subV(){
		return a-b;
	}

char Alu::sclV(){
	char temp;
	int8_t i;
	for (i = 0; i < b; i++){
		temp = a>>7;
		a=a<<1;
		a+=temp;
	}
	return a;
}

char Alu::scrV(){
	char temp;
	int8_t i;
	for (i = 0; i < b; i++){
		temp = a&1;
		temp=temp<<7;
		a=a>>1;
		a+=temp;
	}
	return a;
}