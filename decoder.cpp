class Decoder{
private:
	int instruction;
	char opCode;
public:
	Decoder():instruction(0), opCode(0){}
	void setInst(int);	
	void decode();
};

void Decoder::setInst(int pInstruction){
	instruction=pInstruction;
}

void Decoder::decode(){
	opCode=instruction>>27;


}