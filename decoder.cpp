class Decoder{
public:
	int instruction;
	char opCode;
	//REGV
	int8_t regA, regB, regWR;
	bool upperF, lowerF, regRD, wrF, wrFO;
	//ALU
	uint8_t op;
	//LSU
	int direction;
	int8_t flagM;
	bool RD, WR;
	//REGE
	bool rdFE, wrFE;

public:
	Decoder():instruction(0), opCode(0){}
	void setInst(int);	
	void decode();
};

void Decoder::setInst(int pInstruction){
	instruction=pInstruction;
}

void Decoder::decode(){
	opCode=instruction>>26;
	if(opCode==0){
		//ADDV
		regA=(instruction<<24)>>28;
		regB=(instruction<<28)>>28;
		regWR=(instruction<<20)>>28;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=0;
		direction=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
	}
	else if(opCode==1){
		//SUBV
		regA=(instruction<<24)>>28;
		regB=(instruction<<28)>>28;
		regWR=(instruction<<20)>>28;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=1;
		direction=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
	}
	else if(opCode==2){
		//SUBV
		regA=(instruction<<24)>>28;
		regB=(instruction<<28)>>28;
		regWR=(instruction<<20)>>28;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=2;
		direction=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
	}
	else if(opCode==3){
		//SCLV
		regA=(instruction<<24)>>28;
		regB=(instruction<<28)>>28;
		regWR=(instruction<<20)>>28;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=3;
		direction=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
	}
	else if(opCode==4){
		//SCRV
		regA=(instruction<<24)>>28;
		regB=(instruction<<28)>>28;
		regWR=(instruction<<20)>>28;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=4;
		direction=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
	}


}