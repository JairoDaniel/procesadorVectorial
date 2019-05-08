#include <stdio.h>
class Adder{
private:
	int result;
public:
	Adder():result(0){}
	int add(int, int);
	int getResult();

};

int Adder::add(int a, int b){
	result = a+b;
}

int Adder::getResult(){
	return result;
}