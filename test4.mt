# Copyright (c) 2004-2009, Andrew Porokhin <andrew.porokhin@gmail.com>
# All rights reserved.
# 
# This code is part of the Turing machine project.
#  
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
# 
# $Id: test4.mt,v 1.1 2005/01/26 00:04:13 dron Exp $
#
# f(x) = x^2
#

2
01
27 # ���-�� ��������

# ������ �������� ����� (n - 1) ��������.
# ������� ����� ��������
q00C q21R # 1

################# ����������� ���� �� ����������� (�����)

## macros (now is not supported yet)
## �� ������� ������� - ������ �����������.
# macro copytoleft
# q(5)0L q(1)0L    # (X)
# q(2)0L q(1)1L    # (X+1)
# q(3)1R q(2)1L    # (X+2)
# q(4)0R q(3)1R    # (X+3)
# q(0)1R q(4)1R    # (X+4)
# endmacro


####### ���� (2)
q70L q30L    # (X)
q40L q31L    # (X+1)
q51R q41L    # (X+2)
q60R q51R    # (X+3)
q21R q61R    # (X+4)
####### ����� ����� (2 - 6).

# ������:
# ------------------v-------
# 0 1 ... 1 0 1 ... 1 0
#     n - 1      n

# ������� �� ������ ��. ������, � ����� �� ������ ������
q80L q71L
q90R q81L

# ��������� (n - 2) �ݣ �����
# ������� ����� ��������
q00C q101R
####### ���� (10)
q150L   q110L
q120L   q111L
q131R   q121L
q140R   q131R
q101R   q141R
####### ����� ����� (10 - 14).

# ������:
# ------------------v-----------------
# 0 1 ... 1 0 1 ... 1 0 1 ... 1 0
#    n - 2     n - 1       n

q160L q151L
q170R q161L

####### ���� (17)
q260R q180R       # �������� �� 0
q190R q181R       # ������� �� �����������

# �������� ������
####### ���� (19)
q240L   q200R
q210R   q201R
q221L   q211R
q230L   q221L
q191R   q231L
####### ����� ����� (19 - 23).

q250L q241L # ������� �� ������� ����
# q260L q251L # ������� �� ������� ����
q171R q251L # ������� �� ������� ���� � ������ ��� �� 1
####### ����� ����� (17-25)

# ������:
# ------------v-----------------------
# 0 1 ... 1 0 1 ... 1 0 1 ... 1 0
#    n - 2     n - 1      n^n

q00R q261R

