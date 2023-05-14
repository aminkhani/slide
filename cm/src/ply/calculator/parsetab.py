
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'NUMBER PLUSS : EE : E PLUS NUMBERE : NUMBER'
    
_lr_action_items = {'NUMBER':([0,4,],[3,5,]),'$end':([1,2,3,5,],[0,-1,-3,-2,]),'PLUS':([2,3,5,],[4,-3,-2,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'S':([0,],[1,]),'E':([0,],[2,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> S","S'",1,None,None,None),
  ('S -> E','S',1,'p_s','140.plus.py',19),
  ('E -> E PLUS NUMBER','E',3,'p_e_e_a','140.plus.py',23),
  ('E -> NUMBER','E',1,'p_e_a','140.plus.py',28),
]
