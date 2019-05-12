#!/usr/bin/python3
import tkinter
from tkinter import *
global TOutput
import translate

###########################################################################
## define main window configuration.
###########################################################################

root = Tk()
root.resizable(width=False, height=False)
root.minsize(600,615)
root.title("Compilador del procesador vectorial")
frame = Frame(root)
frame.pack()
root.configure(background="indianred")
frame.configure(background="indianred")

iLabel=Label(frame,text="")
iLabel.pack()
iLabel.configure(background="indianred")

#define the input text window
Tinput = Text(frame, height=30, width=60)
Tinput.pack()
Tinput.insert(END, "")


###########################################################################
## define getCode function to get the instructions
###########################################################################

def getCode():
    global TOutput
    data = Tinput.get(1.0, END)
    fileCode=open('code.txt','w')
    fileCode.close()
    fileCode=open('code.txt','a')
    fileCode.write(data)
    fileCode.close()
    output = translate.charger()
    TOutput.delete("1.0", END)
    TOutput.insert(END, output[0])
    TOutput.configure(state='normal')
    
###########################################################################

iLabel=Label(frame,text="  ")
iLabel.pack()
iLabel.configure(background="indianred")


iLabel=Label(frame,text="  ")
iLabel.pack()
iLabel.configure(background="indianred")

iLabel=Label(frame,text="  ")
iLabel.pack()
iLabel.configure(background="indianred")

#define run button
runButton = Button(frame, text ="RUN", fg="green", command=getCode)
runButton.place(x=200,y=450)


TOutput = Text(frame, height=7, width=50)
TOutput.pack()

root.mainloop()
