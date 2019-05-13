#include "mainwindow.h"
#include <QApplication>
#include <sstream>
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
#include "clock.cpp"
#include "iostream"
#include <bits/stdc++.h>
#include <stdint.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <array>
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <omp.h>

using namespace cv;

Pc * pc;
Adder *sumPc;
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

QApplication *a;
LoadStoreUnit * LSUnit;
RegisterE *regE;
Adder *sumE;
MainWindow *w;
Clock * clockSignal;
char mode;
bool exec;

int it=0;

void connections(){
    int it=0;
    while(it<memI->i){
        usleep(1);
        busPcOut->setData(pc->getPc());
        sumPc->add(busPcOut->getData(), 1);

        memI->setDir(busPcOut->getData());
        pc->setPc(sumPc->getResult());
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

        std::array<unsigned char,8> temp={0,0,0,0,0,0,0,0};
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

        LSUnit->setFlagM(dec->flagM);
        LSUnit->setRD(dec->RD);
        LSUnit->setWR(dec->WR);

        regE->setFlags(dec->rdFE, dec->wrFE);
        regE->setA(dec->regAE);
        regE->setWR(dec->regWRE);

        LSUnit->setDir(regE->read());
        sumE->add(regE->read(), 4);
        regE->write(sumE->getResult());

        regV->write(LSUnit->readData());
        LSUnit->storeData(regV->readStore());
        it++;

        usleep(1);
    }
}

void runStep(){
            busPcOut->setData(pc->getPc());
            sumPc->add(busPcOut->getData(), 1);

            memI->setDir(busPcOut->getData());
            pc->setPc(sumPc->getResult());
            dec->setInst(memI->readMem());
            dec->decode();

            regV->setA(dec->regA);
            regV->setB(dec->regB);
            regV->setWR(dec->regWR);
            regV->setFlags(dec->upperF, dec->lowerF, dec->regRD, dec->wrF, dec->wrFO);

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

            std::array<unsigned char,8> temp={0,0,0,0,0,0,0,0};
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

            LSUnit->setFlagM(dec->flagM);
            LSUnit->setRD(dec->RD);
            LSUnit->setWR(dec->WR);

            regE->setFlags(dec->rdFE, dec->wrFE);
            regE->setA(dec->regAE);
            regE->setWR(dec->regWRE);

            LSUnit->setDir(regE->read());
            sumE->add(regE->read(), 4);
            regE->write(sumE->getResult());

            regV->write(LSUnit->readData());
            LSUnit->storeData(regV->readStore());
            std::stringstream ss;
            std::string out_string;
            //REG VECTOR
            ss<<(int)dec->regA;
            out_string = ss.str();
            w->regA=out_string;
            ss.str("");
            ss<<(int)dec->regB;
            out_string = ss.str();
            w->regB=out_string;
            ss.str("");
            ss<<(int)dec->regWR;
            out_string = ss.str();
            w->regWR=out_string;
            //LSU
            ss.str("");
            ss<<(int)dec->flagM;
            out_string = ss.str();
            w->regAE=out_string;
            if(dec->RD==true)
                w->RD="true";
            else
                w->RD="false";
            if(dec->WR==true)
                w->WR="true";
            else
                w->WR="false";
            //ALU
            ss.str("");
            ss<<(int)dec->op;
            out_string = ss.str();
            w->op=out_string;
            //REG ESCALAR
            if(dec->rdFE==true)
                w->rdFE="true";
            else
                w->rdFE="false";
            if(dec->wrFE==true)
                w->wrFE="true";
            else
                w->wrFE="false";
            ss.str("");
            ss<<(int)dec->regAE;
            out_string = ss.str();
            w->regAE=out_string;
            ss.str("");
            ss<<(int)dec->regWRE;
            out_string = ss.str();
            w->regWRE=out_string;
            it++;

}


void showResults(){
    Mat imageEncr(96,96,CV_8UC1);
    Mat imageDecr(96,96,CV_8UC1);
    std::array<unsigned char,4> imageMem={0,0,0,0};
    LSUnit->setFlagM(1);
    LSUnit->setRD(true);
    for(int imgI=0; imgI<96; imgI++){
        for(int imgJ=0; imgJ<96; imgJ++){
            LSUnit->setDir(96*imgI+imgJ);
            imageMem=LSUnit->readData();
            imageEncr.at<uchar>(imgI,imgJ)=imageMem[0];
            imageEncr.at<unsigned char>(imgI,imgJ+1)=imageMem[1];
            imageEncr.at<unsigned char>(imgI,imgJ+2)=imageMem[2];
            imageEncr.at<unsigned char>(imgI,imgJ+3)=imageMem[3];
        }
    }

    imwrite( "../Resources/encrypt.jpg", imageEncr);

    for(int imgI=0; imgI<96; imgI++){
        for(int imgJ=0; imgJ<96; imgJ++){
            LSUnit->setDir(9216+(96*imgI+imgJ));
            imageMem=LSUnit->readData();
            imageDecr.at<uchar>(imgI,imgJ)=imageMem[0];
            imageDecr.at<uchar>(imgI,imgJ+1)=imageMem[1];
            imageDecr.at<uchar>(imgI,imgJ+2)=imageMem[2];
            imageDecr.at<uchar>(imgI,imgJ+3)=imageMem[3];
        }
    }
    imwrite( "../Resources/decrypt.jpg", imageDecr);

}

int main(int argc, char *argv[])
{
    double start_time, run_time;
    a = new QApplication(argc, argv);
    w = new MainWindow();

        mode= argv[1][0];
        pc = new Pc();
        sumPc = new Adder();
        muxPc = new Mux21();
        busPcOut= new Bus32();
        memI = new MemoryI(argv[2][0]);
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
        clockSignal = new Clock();

        if(mode=='0'){
            start_time = omp_get_wtime();
            connections();
            run_time = omp_get_wtime() - start_time;
            printf("\n Execution time is %f seconds.\n",run_time);
        }
        else{
            while(it<memI->i){
                runStep();
                w->test();
                a->exec();
            }
        }

        showResults();




    return 0;
}
