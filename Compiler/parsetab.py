
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'ADDE ADDV FINAL FOR LDVL LDVU NUMBER SCLV SCRV STVL STVU SUBV VARIABLE XORVprogram : declaration_listdeclaration_list : declaration_list declaration\n                        | declarationdeclaration : statement_liststatement_list : statement_list statement\n                        | emptystatement : expression_stmt\n                    | iteration_stmt\n                    | statement_listiteration_stmt : FOR NUMBER statement_list FINALexpression_stmt : expression\n                        | FINALexpression : ADDV VARIABLE VARIABLE VARIABLE\n                    | SUBV VARIABLE VARIABLE VARIABLE\n                    | XORV VARIABLE VARIABLE VARIABLE\n                    | SCLV VARIABLE VARIABLE VARIABLE\n                    | SCRV VARIABLE VARIABLE VARIABLE\n                    | LDVU VARIABLE VARIABLE NUMBER\n                    | LDVL VARIABLE VARIABLE NUMBER\n                    | STVU VARIABLE VARIABLE NUMBER\n                    | STVL VARIABLE VARIABLE NUMBER\n                    | ADDE VARIABLE VARIABLEempty : '
    
_lr_action_items = {'STVU':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,8,-2,-7,-5,-8,-12,-11,8,-23,-22,8,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'SUBV':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,9,-2,-7,-5,-8,-12,-11,9,-23,-22,9,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'LDVU':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,11,-2,-7,-5,-8,-12,-11,11,-23,-22,11,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'VARIABLE':([8,9,11,13,14,15,18,19,20,21,24,25,26,27,28,29,30,31,32,33,36,39,40,41,42,],[24,25,26,27,28,29,30,31,32,33,35,36,37,38,39,40,41,42,43,44,47,50,51,52,53,]),'ADDE':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,21,-2,-7,-5,-8,-12,-11,21,-23,-22,21,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'ADDV':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,15,-2,-7,-5,-8,-12,-11,15,-23,-22,15,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'FINAL':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,16,-2,-7,-5,-8,-12,-11,16,-23,-22,55,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'SCLV':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,18,-2,-7,-5,-8,-12,-11,18,-23,-22,18,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'XORV':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,19,-2,-7,-5,-8,-12,-11,19,-23,-22,19,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'$end':([0,1,2,3,4,5,6,7,10,12,16,17,23,44,46,47,48,49,50,51,52,53,54,55,],[-23,-1,-6,0,-3,-4,-2,-7,-5,-8,-12,-11,-9,-22,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'NUMBER':([22,35,37,38,43,],[34,46,48,49,54,]),'LDVL':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,20,-2,-7,-5,-8,-12,-11,20,-23,-22,20,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'STVL':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,13,-2,-7,-5,-8,-12,-11,13,-23,-22,13,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'FOR':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,22,-2,-7,-5,-8,-12,-11,22,-23,-22,22,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),'SCRV':([0,1,2,4,5,6,7,10,12,16,17,23,34,44,45,46,47,48,49,50,51,52,53,54,55,],[-23,-23,-6,-3,14,-2,-7,-5,-8,-12,-11,14,-23,-22,14,-20,-14,-18,-21,-17,-13,-16,-15,-19,-10,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'expression_stmt':([5,23,45,],[7,7,7,]),'declaration_list':([0,],[1,]),'statement':([5,23,45,],[10,10,10,]),'empty':([0,1,5,23,34,45,],[2,2,2,2,2,2,]),'expression':([5,23,45,],[17,17,17,]),'iteration_stmt':([5,23,45,],[12,12,12,]),'program':([0,],[3,]),'declaration':([0,1,],[4,6,]),'statement_list':([0,1,5,23,34,45,],[5,5,23,23,45,23,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> program","S'",1,None,None,None),
  ('program -> declaration_list','program',1,'p_program','parser.py',12),
  ('declaration_list -> declaration_list declaration','declaration_list',2,'p_declaration_list','parser.py',16),
  ('declaration_list -> declaration','declaration_list',1,'p_declaration_list','parser.py',17),
  ('declaration -> statement_list','declaration',1,'p_declaration','parser.py',21),
  ('statement_list -> statement_list statement','statement_list',2,'p_statement_list','parser.py',25),
  ('statement_list -> empty','statement_list',1,'p_statement_list','parser.py',26),
  ('statement -> expression_stmt','statement',1,'p_statement','parser.py',30),
  ('statement -> iteration_stmt','statement',1,'p_statement','parser.py',31),
  ('statement -> statement_list','statement',1,'p_statement','parser.py',32),
  ('iteration_stmt -> FOR NUMBER statement_list FINAL','iteration_stmt',4,'p_iteration_stmt','parser.py',36),
  ('expression_stmt -> expression','expression_stmt',1,'p_expression_stmt','parser.py',40),
  ('expression_stmt -> FINAL','expression_stmt',1,'p_expression_stmt','parser.py',41),
  ('expression -> ADDV VARIABLE VARIABLE VARIABLE','expression',4,'p_expression','parser.py',45),
  ('expression -> SUBV VARIABLE VARIABLE VARIABLE','expression',4,'p_expression','parser.py',46),
  ('expression -> XORV VARIABLE VARIABLE VARIABLE','expression',4,'p_expression','parser.py',47),
  ('expression -> SCLV VARIABLE VARIABLE VARIABLE','expression',4,'p_expression','parser.py',48),
  ('expression -> SCRV VARIABLE VARIABLE VARIABLE','expression',4,'p_expression','parser.py',49),
  ('expression -> LDVU VARIABLE VARIABLE NUMBER','expression',4,'p_expression','parser.py',50),
  ('expression -> LDVL VARIABLE VARIABLE NUMBER','expression',4,'p_expression','parser.py',51),
  ('expression -> STVU VARIABLE VARIABLE NUMBER','expression',4,'p_expression','parser.py',52),
  ('expression -> STVL VARIABLE VARIABLE NUMBER','expression',4,'p_expression','parser.py',53),
  ('expression -> ADDE VARIABLE VARIABLE','expression',3,'p_expression','parser.py',54),
  ('empty -> <empty>','empty',0,'p_empty','parser.py',58),
]
