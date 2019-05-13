#include <unistd.h>

class Clock{
private:
	int value;
public:
	void setValue(int);
	int getValue();
	void run();
};

void Clock::setValue(int pValue){
	value=pValue;
}

int Clock::getValue(){
	return value;
}

void Clock::run(){
	while(true){
		value=1;
		usleep(1);
		value=0;
		usleep(1);
	}
}