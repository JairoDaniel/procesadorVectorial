import parser
import sys


def code(pdata):
    newData = codeComment(pdata).split()
    tempData  = []
    result = []
    if(("Syntax" in pdata) == True):
        return [pdata]
    else:
        return codeAux(newData, tempData, result)

def codeAux(data, tempData, result):
    if(data==[]):
        return result
    elif((data[0]=="addv") or (data[0]=="subv") or (data[0]=="xorv") or (data[0]=="sclv") or (data[0]=="scrv")
         or (data[0]=="ldvu") or (data[0]=="ldvl") or (data[0]=="stvu") or (data[0]=="stvl")):
        result+=[data[0]]+[data[1]]+[data[2]]+[data[3]]
        return codeAux(data[4:], tempData, result)
    elif(data[0]=="adde"):
        result+=[data[0]]+[data[1]]+[data[2]]
        return codeAux(data[3:], tempData, result)
    elif(data[0]=="For"):
        tmp = codeFor(data, tempData, result)
        return codeAux(tmp[0], tempData, (result+tmp[1]))
    else:
        return codeAux(data[1:], tempData, result)

def codeFor(data, tempData, result):
    cont=1
    count=1
    tdata = data[1:]
    while(cont!=0):
        if((tdata[0]) == "For"):
            cont+=1
            count+=1
            tdata = tdata[1:]
        elif((tdata[0]) == ";"):
            cont-=1
            tdata = tdata[1:]
            count+=1
        else:
            tdata = tdata[1:]
            count+=1
    tempResult = codeForAux(data[:count][2:-1],int(data[1]),tempData, result)
    return [data[count:]]+[tempResult]

def codeForAux(data, times, tempData, result):
    i=0
    tempResult=[]
    while(i<times):
        tempResult += codeAux(data,tempData, [])
        i+=1
    return tempResult

def codeComment(data):
    temp=""
    while(len(data)>1):
        if(data[0]=="#"):
            while(data[0]!= '\n'):
                data=data[1:]
        else:
            temp+=data[0]
            data = data[1:]
    return temp


def connectToPar(doc):
    return code(parser.connectToLex(doc))

    


