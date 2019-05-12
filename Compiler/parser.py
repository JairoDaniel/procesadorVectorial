import ply.yacc as yacc
from lexical import tokens
import lexical
import sys

global flag
flag = 0
global msgError
msgError=""

def p_program(p):
    'program : declaration_list'
    pass

def p_declaration_list(p):
    '''declaration_list : declaration_list declaration
                        | declaration'''
    pass

def p_declaration(p):
    '''declaration : statement_list'''
    pass

def p_statement_list(p):
    '''statement_list : statement_list statement
                        | empty'''
    pass

def p_statement(p):
    '''statement : expression_stmt
                    | iteration_stmt
                    | statement_list'''
    pass

def p_iteration_stmt(p):
    'iteration_stmt : FOR NUMBER statement_list FINAL'
    pass

def p_expression_stmt(p):
    '''expression_stmt : expression
                        | FINAL'''
    pass

def p_expression(p):
    '''expression : ADDV VARIABLE VARIABLE VARIABLE
                    | SUBV VARIABLE VARIABLE VARIABLE
                    | XORV VARIABLE VARIABLE VARIABLE
                    | SCLV VARIABLE VARIABLE VARIABLE
                    | SCRV VARIABLE VARIABLE VARIABLE
                    | LDVU VARIABLE VARIABLE NUMBER
                    | LDVL VARIABLE VARIABLE NUMBER
                    | STVU VARIABLE VARIABLE NUMBER
                    | STVL VARIABLE VARIABLE NUMBER
                    | ADDE VARIABLE VARIABLE'''
    pass

def p_empty(p):
    'empty : '
    pass

# Error rule for syntax errors
def p_error(p):
    global flag
    msgError=("Syntax error in: '%s'" % p.value)
    flag = 1

# Build the parser
parser = yacc.yacc()


def connectToLex(code):
    func = open(code, 'r')
    data = func.read()
    parser.parse(data, tracking=True)
    if (flag is 1):
        return msgError
    else:
        return data
	
