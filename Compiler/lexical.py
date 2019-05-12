#!/usr/bin/env python3
import ply.lex as lex

#Palabras reservadas del lenguaje
reserved = {
    'addv' : 'ADDV',
    'subv' : 'SUBV',
    'xorv' : 'XORV',
    'scrv' : 'SCRV',
    'sclv' : 'SCLV',
    'ldvu' : 'LDVU',
    'ldvl' : 'LDVL',
    'stvu' : 'STVU',
    'stvl' : 'STVL',
    'For' : 'FOR',
    'adde' : 'ADDE'
    }


#Tokens del lenguaje
tokens = ['VARIABLE', 'NUMBER', 'FINAL'] + list(reserved.values())
t_FINAL = r'\;'


def t_VARIABLE(t):
    r'[R,V][0-9]'
    t.type = reserved.get(t.value,'VARIABLE')    # Check for reserved words
    return t

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

def t_ADDV(t):
    r'addv'
    return t

def t_SUBV(t):
    r'subv'
    return t

def t_XORV(t):
    r'xorv'
    return t

def t_SCRV(t):
    r'scrv'
    return t

def t_SCLV(t):
    r'sclv'
    return t

def t_LDVU(t):
    r'ldvu'
    return t

def t_LDVL(t):
    r'ldvl'
    return t

def t_STVU(t):
    r'stvu'
    return t

def t_STVL(t):
    r'stvl'
    return t

def t_FOR(t):
    r'For'
    return t

def t_ADDE(t):
    r'adde'
    return t

#Extrae el numero de linea
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

#Ignora espacios y tabs
t_ignore  = ' \t'

#Manejador de errores
def t_error(t):
    print ("Lexical error: " + str(t.value[0]))
    t.lexer.skip(1)

#Comentarios
def t_Comments(t):
    r'\#.*?\n'
    t.lexer.lineno += 1

lexer = lex.lex()
