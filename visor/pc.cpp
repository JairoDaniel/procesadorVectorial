class Pc{
private:
	int pcReg;
public:
	Pc(): pcReg(0){}
	int getPc();
	void setPc(int);
	
};

int Pc::getPc(){
	return pcReg;
}
void Pc::setPc (int pcValue){
	pcReg=pcValue;
}