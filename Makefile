## Tuiring Machine
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.
#
# Makefile for gmake or make or nmake(msvc) 
#
# Author: Andrew A. Porohin (dron)
#  email: paa0101@mail.ru
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
