## Tuiring Machine
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.
#
# Author: Andrew A. Porohin (dron)
#  email: paa0101@mail.ru
#
# $Id: test4.mt,v 1.1 2005/01/26 00:04:13 dron Exp $
#
# f(x) = x^2
#

2
01
27 # кол-во операций

# просто копируем влево (n - 1) единичку.
# пропуск одной единички
q00C q21R # 1

################# стандартный цикл по копированию (влево)

## macros (now is not supported yet)
## на текущей позиции - начало копирования.
# macro copytoleft
# q(5)0L q(1)0L    # (X)
# q(2)0L q(1)1L    # (X+1)
# q(3)1R q(2)1L    # (X+2)
# q(4)0R q(3)1R    # (X+3)
# q(0)1R q(4)1R    # (X+4)
# endmacro


####### цикл (2)
q70L q30L    # (X)
q40L q31L    # (X+1)
q51R q41L    # (X+2)
q60R q51R    # (X+3)
q21R q61R    # (X+4)
####### конец цикла (2 - 6).

# статус:
# ------------------v-------
# 0 1 ... 1 0 1 ... 1 0
#     n - 1      n

# возврат до начала вх. данных, а потом на начало данных
q80L q71L
q90R q81L

# скопируем (n - 2) ещё влево
# пропуск одной единички
q00C q101R
####### цикл (10)
q150L   q110L
q120L   q111L
q131R   q121L
q140R   q131R
q101R   q141R
####### конец цикла (10 - 14).

# статус:
# ------------------v-----------------
# 0 1 ... 1 0 1 ... 1 0 1 ... 1 0
#    n - 2     n - 1       n

q160L q151L
q170R q161L

####### цикл (17)
q260R q180R       # заменяем на 0
q190R q181R       # доходим до копируемого

# копируем вправо
####### цикл (19)
q240L   q200R
q210R   q201R
q221L   q211R
q230L   q221L
q191R   q231L
####### конец цикла (19 - 23).

q250L q241L # доходим до первого нуля
# q260L q251L # доходим до второго нуля
q171R q251L # доходим до второго нуля и меняем его на 1
####### конец цикла (17-25)

# статус:
# ------------v-----------------------
# 0 1 ... 1 0 1 ... 1 0 1 ... 1 0
#    n - 2     n - 1      n^n

q00R q261R

