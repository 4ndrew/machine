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
# $Id: test3.mt,v 1.1 2005/01/26 00:04:13 dron Exp $
#
# -------------
# f(x) = n(x)*2
# -------------
#
2
01
8
q00C q21R
q00L q31R
q81L q40R
# до первого нуля вперёд
q50R q41R
# до второго нуля вперёд
q61L q51R
# до первого нуля назад
q70L q61L
# до второго нуля назад
q31R q71L
q00R q81L