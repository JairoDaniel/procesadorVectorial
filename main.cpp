#include "pc.cpp"
#include "adder.cpp"
#include "mux21.cpp"
#include "bus32.cpp"
#include "memoryI.cpp"
/**/
#include "loadStoreUnit.cpp"
#include "registerV.cpp"
#include "bus64.cpp"
#include "alu.cpp"
#include "registerE.cpp"
#include "decoder.cpp"

#include "iostream"
#include <bits/stdc++.h> 
#include <stdint.h>
#include <fstream>
#include <array>


Pc * pc;
Adder *sum;
Mux21 *muxPc;
Bus32 * busPcOut;
MemoryI * memI ;
RegisterV *regV;
Bus64 *busRegV1;
Bus64 *busRegV2;
Alu * aluV0;
Alu * aluV1;
Alu * aluV2;
Alu * aluV3;
Alu * aluV4;
Alu * aluV5;
Alu * aluV6;
Alu * aluV7;
Decoder * dec;


LoadStoreUnit * LSUnit;
RegisterE *regE;
Adder *sumE;

void connections(){
    int it=0;
    while(it<6){
    busPcOut->setData(pc->getPc());
    sum->add(busPcOut->getData(), 1);
    //muxPc->setA(busPcOut->getData());
    //muxPc->setB(sum->getResult());
    
    memI->setDir(busPcOut->getData());
    pc->setPc(sum->getResult());
    dec->setInst(memI->readMem());
    dec->decode();

    regV->setA(dec->regA);
    regV->setB(dec->regB);
    regV->setWR(dec->regWR);
    regV->setFlags(dec->upperF, dec->lowerF, dec->regRD, dec->wrF, dec->wrFO);



    /**/
    busRegV1->setData(regV->readA());
    busRegV2->setData(regV->readB());

    aluV0->setOp(dec->op);
    aluV1->setOp(dec->op);
    aluV2->setOp(dec->op);
    aluV3->setOp(dec->op);
    aluV4->setOp(dec->op);
    aluV5->setOp(dec->op);
    aluV6->setOp(dec->op);
    aluV7->setOp(dec->op);


    aluV0->setData((int8_t)(busRegV1->getData())[0],(int8_t)(busRegV2->getData())[0] );
    aluV1->setData((int8_t)(busRegV1->getData())[1],(int8_t)(busRegV2->getData())[1] );
    aluV2->setData((int8_t)(busRegV1->getData())[2],(int8_t)(busRegV2->getData())[2] );
    aluV3->setData((int8_t)(busRegV1->getData())[3],(int8_t)(busRegV2->getData())[3] );
    aluV4->setData((int8_t)(busRegV1->getData())[4],(int8_t)(busRegV2->getData())[4] );
    aluV5->setData((int8_t)(busRegV1->getData())[5],(int8_t)(busRegV2->getData())[5] );
    aluV6->setData((int8_t)(busRegV1->getData())[6],(int8_t)(busRegV2->getData())[6] );
    aluV7->setData((int8_t)(busRegV1->getData())[7],(int8_t)(busRegV2->getData())[7] );
    
    std::array<char,8> temp;
    temp[0]= aluV0->function();
    temp[1]= aluV1->function();
    temp[2]= aluV2->function();
    temp[3]= aluV3->function();
    temp[4]= aluV4->function();
    temp[5]= aluV5->function();
    temp[6]= aluV6->function();
    temp[7]= aluV7->function();

    //BANDERAS
    regV->writeOp(temp);

    LSUnit->setDir(dec->direction);
    LSUnit->setFlagM(dec->flagM);
    LSUnit->setRD(dec->RD);
    LSUnit->setWR(dec->WR);

    regE->setFlags(dec->rdFE, dec->wrFE);
    regE->setA(dec->regA);
    regE->setWR(dec->regWR);

    LSUnit->setDir(regE->read());
    sumE->add(regE->read(), 1);
    regE->write(sumE->getResult());
    regV->write(LSUnit->readData());
    LSUnit->storeData(regV->readStore());

    printf("------------\n");
    regV->printV(1);
    printf("\n------------\n");
    regV->printV(2);
    printf("\n------------\n");
    regV->printV(0);
    printf("\n------------\n");

    it++;

}



}

int main() { 
    pc = new Pc();
    sum = new Adder();
    muxPc = new Mux21();
    busPcOut= new Bus32();    
    memI = new MemoryI();
    /**/
    regV = new RegisterV();
    busRegV1 = new Bus64();
    busRegV2 = new Bus64();

    aluV0= new Alu();
    aluV1= new Alu();
    aluV2= new Alu();
    aluV3= new Alu();
    aluV4= new Alu();
    aluV5= new Alu();
    aluV6= new Alu();
    aluV7= new Alu();


    LSUnit = new LoadStoreUnit();
    regE = new RegisterE();
    sumE = new Adder();
    dec = new Decoder();

    connections();




    return 0; 
} 