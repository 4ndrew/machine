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
# $Id: test1.mt,v 1.1 2005/01/26 00:04:13 dron Exp $
#
# -------------------------
# Простая машина Тьюринга.
# f(x) = 0
# -------------------------

# Размер 
2

# Алфавит
01

# Количество операций q[1-n]
3

# Операции над лентой
q01C q21R # то, да сё
q30L q20R
q30L q01C
