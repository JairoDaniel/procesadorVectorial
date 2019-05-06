class Bus32{
private:
	int data;
public:
	Bus32():data(0){}
	int getData();
	void setData(int);

};

void Bus32::setData(int pData){
	data=pData;
}

int Bus32::getData(){
	return data;
}