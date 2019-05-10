#!/usr/bin/env python3
import sys
import Semantic

def translate(newData):
    file= open("../binary.txt","w+")
    if(newData==[]):
        file.close()
        return ["No hay codigo que compilar"]
    elif(("Sintax Error" in newData[0]) == True):
        file.close()
        return [newData[0]]
    else:
        result = []
        flag=True
        tempResult=""
        while (newData !=[] and flag==True):
            if(newData[0] == "addv"):
                tempResult="00000000000000000000"
                numOperando=0
                while(numOperando<3):
                    if(newData[numOperando+1]=="V0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="V1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="V2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="V3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="V4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="V5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="V6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="V7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="V8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="V9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Solo registros vectoriales en esta operacion.\nLos registros vectoriales van de V0 a V9"]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "subv"):
                tempResult="00000100000000000000"
                numOperando=0
                while(numOperando<3):
                    if(newData[numOperando+1]=="V0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="V1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="V2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="V3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="V4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="V5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="V6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="V7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="V8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="V9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Solo registros vectoriales en esta operacion.\nLos registros vectoriales van de V0 a V9"]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "xorv"):
                tempResult="00001000000000000000"
                numOperando=0
                while(numOperando<3):
                    if(newData[numOperando+1]=="V0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="V1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="V2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="V3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="V4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="V5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="V6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="V7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="V8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="V9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Solo registros vectoriales en esta operacion.\nLos registros vectoriales van de V0 a V9"]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "sclv"):
                tempResult="00001100000000000000"
                numOperando=0
                while(numOperando<3):
                    if(newData[numOperando+1]=="V0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="V1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="V2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="V3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="V4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="V5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="V6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="V7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="V8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="V9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Solo registros vectoriales en esta operacion.\nLos registros vectoriales van de V0 a V9"]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "scrv"):
                tempResult="00010000000000000000"
                numOperando=0
                while(numOperando<3):
                    if(newData[numOperando+1]=="V0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="V1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="V2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="V3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="V4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="V5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="V6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="V7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="V8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="V9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Solo registros vectoriales en esta operacion.\nLos registros vectoriales van de V0 a V9"]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "ldvu"):
                tempResult="00010100000000000000"
                numOperando=0
                while(numOperando<3):
                    if(numOperando==0):
                        if(newData[numOperando+1]=="V0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="V1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="V2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="V3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="V4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="V5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="V6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="V7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="V8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="V9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Primer operando debe ser un registro vectorial.\nLos registros vectoriales van de V0 a V9"]
                            break;
                    elif(numOperando==1):
                        if(newData[numOperando+1]=="R0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="R1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="R2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="R3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="R4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="R5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="R6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="R7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="R8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="R9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Segundo operando debe ser un registro escalar.\nLos registros escalares van de R0 a R9"]
                            break;
                    else:
                        if(newData[numOperando+1]=="0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="1"):
                            tempResult+="0001"
                        else:
                            flag=False
                            result=["Error: El inmediato es solo 1 bit."]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "ldvl"):
                tempResult="00011000000000000000"
                numOperando=0
                while(numOperando<3):
                    if(numOperando==0):
                        if(newData[numOperando+1]=="V0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="V1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="V2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="V3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="V4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="V5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="V6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="V7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="V8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="V9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Primer operando debe ser un registro vectorial.\nLos registros vectoriales van de V0 a V9"]
                            break;
                    elif(numOperando==1):
                        if(newData[numOperando+1]=="R0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="R1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="R2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="R3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="R4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="R5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="R6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="R7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="R8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="R9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Segundo operando debe ser un registro escalar.\nLos registros escalares van de R0 a R9"]
                            break;
                    else:
                        if(newData[numOperando+1]=="0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="1"):
                            tempResult+="0001"
                        else:
                            flag=False
                            result=["Error: El inmediato es solo 1 bit."]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "stvu"):
                tempResult="00011100000000000000"
                numOperando=0
                while(numOperando<3):
                    if(numOperando==0):
                        if(newData[numOperando+1]=="V0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="V1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="V2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="V3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="V4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="V5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="V6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="V7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="V8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="V9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Primer operando debe ser un registro vectorial.\nLos registros vectoriales van de V0 a V9"]
                            break;
                    elif(numOperando==1):
                        if(newData[numOperando+1]=="R0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="R1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="R2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="R3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="R4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="R5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="R6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="R7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="R8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="R9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Segundo operando debe ser un registro escalar.\nLos registros escalares van de R0 a R9"]
                            break;
                    else:
                        if(newData[numOperando+1]=="0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="1"):
                            tempResult+="0001"
                        else:
                            flag=False
                            result=["Error: El inmediato es solo 1 bit."]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "stvl"):
                tempResult="00100000000000000000"
                numOperando=0
                while(numOperando<3):
                    if(numOperando==0):
                        if(newData[numOperando+1]=="V0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="V1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="V2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="V3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="V4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="V5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="V6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="V7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="V8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="V9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Primer operando debe ser un registro vectorial.\nLos registros vectoriales van de V0 a V9"]
                            break;
                    elif(numOperando==1):
                        if(newData[numOperando+1]=="R0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="R1"):
                            tempResult+="0001"
                        elif(newData[numOperando+1]=="R2"):
                            tempResult+="0010"
                        elif(newData[numOperando+1]=="R3"):
                            tempResult+="0011"
                        elif(newData[numOperando+1]=="R4"):
                            tempResult+="0100"
                        elif(newData[numOperando+1]=="R5"):
                            tempResult+="0101"
                        elif(newData[numOperando+1]=="R6"):
                            tempResult+="0110"
                        elif(newData[numOperando+1]=="R7"):
                            tempResult+="0111"
                        elif(newData[numOperando+1]=="R8"):
                            tempResult+="1000"
                        elif(newData[numOperando+1]=="R9"):
                            tempResult+="1001"
                        else:
                            flag=False
                            result=["Error: Segundo operando debe ser un registro escalar.\nLos registros escalares van de R0 a R9"]
                            break;
                    else:
                        if(newData[numOperando+1]=="0"):
                            tempResult+="0000"
                        elif(newData[numOperando+1]=="1"):
                            tempResult+="0001"
                        else:
                            flag=False
                            result=["Error: El inmediato es solo 1 bit."]
                    numOperando+=1
                file.write(tempResult+"\r\n")
                newData=newData[4:]
            elif(newData[0] == "adde"):
                tempResult="00100100000000000000"
                numOperando=0
                while(numOperando<2):
                    if(newData[numOperando+1]=="R0"):
                        tempResult+="0000"
                    elif(newData[numOperando+1]=="R1"):
                        tempResult+="0001"
                    elif(newData[numOperando+1]=="R2"):
                        tempResult+="0010"
                    elif(newData[numOperando+1]=="R3"):
                        tempResult+="0011"
                    elif(newData[numOperando+1]=="R4"):
                        tempResult+="0100"
                    elif(newData[numOperando+1]=="R5"):
                        tempResult+="0101"
                    elif(newData[numOperando+1]=="R6"):
                        tempResult+="0110"
                    elif(newData[numOperando+1]=="R7"):
                        tempResult+="0111"
                    elif(newData[numOperando+1]=="R8"):
                        tempResult+="1000"
                    elif(newData[numOperando+1]=="R9"):
                        tempResult+="1001"
                    else:
                        flag=False
                        result=["Error: Los operandos deben ser un registros escalares.\nLos registros escalares van de R0 a R9"]
                        break;
                    numOperando+=1
                tempResult+="0000"
                file.write(tempResult+"\r\n")
                newData=newData[3:]                                
            if(result==[]):
                result=["Compilación exitosa"]
        file.close()
        return result
    
def charger():
    if (len(sys.argv) > 1):
        document = sys.argv[1]
    else:
        document = 'code.txt'
    return  translate(Semantic.connectToPar(document))
