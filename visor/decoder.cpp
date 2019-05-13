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
	int8_t flagM;
	bool RD, WR;
	//REGE
	bool rdFE, wrFE;
	int8_t regAE, regWRE;

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
		regA=(instruction>>4)&15;
		regB=(instruction&15);
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=0;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
		regAE=0;
		regWRE=0;
	}
	else if(opCode==1){
		//SUBV
		regA=(instruction>>4)&15;
		regB=(instruction&15);
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=1;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
		regAE=0;
		regWRE=0;
	}
	else if(opCode==2){
		//XORV
		regA=(instruction>>4)&15;
		regB=(instruction&15);
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=2;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
		regAE=0;
		regWRE=0;
	}
	else if(opCode==3){
		//SCLV
		regA=(instruction>>4)&15;
		regB=(instruction&15);
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=3;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
		regAE=0;
		regWRE=0;
	}
	else if(opCode==4){
		//SCRV
		regA=(instruction>>4)&15;
		regB=(instruction&15);
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=true;
		op=4;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=false;
		wrFE=false;
		regAE=0;
		regWRE=0;
	}
	else if(opCode==5){
		//LDVU
		regA=0;
		regB=0;
		regWR=(instruction>>8)&15;
		upperF=true;
		lowerF=false;
		regRD=false;
		wrF=true;
		wrFO=false;
		op=5;
		flagM=instruction&1;
		RD=true;
		WR=false;
		rdFE=true;
		wrFE=false;
		regAE=((instruction>>4)&15);
		regWRE=0;
	}
	else if(opCode==6){
		//LDVL
		regA=0;
		regB=0;
		regWR=(instruction>>8)&15;
		upperF=false;
		lowerF=true;
		regRD=false;
		wrF=true;
		wrFO=false;
		op=5;
		flagM=instruction&1;
		RD=true;
		WR=false;
		rdFE=true;
		wrFE=false;
		regAE=((instruction>>4)&15);
		regWRE=0;
	}
	else if(opCode==7){
		//STVU
		regA=(instruction>>8)&15;
		regB=0;
		regWR=0;
		upperF=true;
		lowerF=false;
		regRD=true;
		wrF=false;
		wrFO=false;
		op=5;
		flagM=instruction&1;
		RD=false;
		WR=true;
		rdFE=true;
		wrFE=false;
		regAE=((instruction>>4)&15);
		regWRE=0;
	}
	else if(opCode==8){
		//STVL
		regA=(instruction>>8)&15;
		regB=0;
		regWR=0;
		upperF=false;
		lowerF=true;
		regRD=true;
		wrF=false;
		wrFO=false;
		op=5;
		flagM=instruction&1;
		RD=false;
		WR=true;
		rdFE=true;
		wrFE=false;
		regAE=((instruction>>4)&15);
		regWRE=0;
	}
	else if(opCode==9){
		//ADDE
		regA=0;
		regB=0;
		regWR=0;
		upperF=false;
		lowerF=false;
		regRD=false;
		wrF=false;
		wrFO=false;
		op=5;
		flagM=2;
		RD=false;
		WR=false;
		rdFE=true;
		wrFE=true;
		regAE=(instruction>>4)&15;
		regWRE=(instruction>>8)&15;
	}



}
