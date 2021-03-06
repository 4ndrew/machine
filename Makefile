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
# $Id: Makefile,v 1.1 2005/01/26 00:04:13 dron Exp $
# 

######################### FreeBSD
CC=                 g++
RM=                 rm -f
ECHO=               echo
CFLAGS=             -Wall -W
# CFLAGS=             -Wall -ggdb -DDEBUG
LFLAGS=             
MACHINE_EXE=        machine
MACRO_EXE=          macro
OBJ=                .o
######################### Win32
#CC=                 cl
#CFLAGS=             /DWIN32
#EXENAME=            machine.exe
#OBJ=                .obj

#######################################################
OBJS_MACHINE=config$(OBJ) \
             CMachine$(OBJ) \
             Ribbon$(OBJ) \
             ByteRibbon$(OBJ) \
             CRibbon$(OBJ)\
             machine$(OBJ)

OBJS_MACRO=config$(OBJ) \
           parse$(OBJ) \
           mt$(OBJ) \
           macro$(OBJ)

all: $(MACHINE_EXE)
#$(MACRO_EXE)

rebuild: clean all

$(MACHINE_EXE): $(OBJS_MACHINE)
	@$(ECHO) Linking $(MACHINE_EXE)
	@$(CC) $(LFLAGS) $(OBJS_MACHINE) -o $(MACHINE_EXE)
    
$(MACRO_EXE): $(OBJS_MACRO)
	@$(ECHO) Linking $(MACRO_EXE)
	@$(CC) $(LFLAGS) $(OBJS_MACRO) -o $(MACRO_EXE)

.cpp$(OBJ):
	@$(ECHO) Compiling $<
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(ECHO) Cleaning...
	@$(RM) $(OBJS_MACHINE)
	@$(RM) $(MACHINE_EXE)
	@$(RM) $(OBJS_MACRO)
	@$(RM) $(MACRO_EXE)
