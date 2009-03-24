/*
 * Copyright (c) 2004-2009, Andrew Porokhin <andrew.porokhin@gmail.com>
 * All rights reserved.
 *
 * This code is part of the Turing machine project.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: macro.cpp,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#include <stdio.h>
#include <stdarg.h>

#include "parse.h"
#include "config.h"
#include "mt.h"

/* Abnormal termination (handled exceptions) */
void err(int, char *, ...);
/* Program use mini-help */
void use();

int main(int argc, char **argv) {
  CMachine *machine = NULL;
  int errcode = 0;
  long dX;
  
  printf("Macro for Tuiring Machine v1.1 (c) 2002 by Andrew A. Porohin\n");
  if(argc > 1) {
    machine = loadMachine(argv[1], errcode);
    
    if(machine == NULL) {
      printf("LoadMachine failed. errcode = %d\n", errcode);
      return -1;
    }
    
    if(argc > 2) {
      dX = atoi(argv[2]);
      printMachine(machine, dX);
    }
    else printMachine(machine);
    
    /* cleanup */
    delete machine;
  }
  else use();
}

void err(int errcode, char *msg, ...) {
  va_list ap;
  char *buff = new char[255];
  if(msg != NULL && buff != NULL){
    va_start(ap, msg);
#ifdef _HAS_VSNPRINTF_
    vsnprintf(buff, 255, msg, ap);
#else
    vsprintf(buff, msg, ap);
#endif
    va_end(ap);
    fprintf(stderr, "%s\n", buff);
  }
  delete [] buff;
  if(errcode != 0) exit(errcode);
}

void use() {
  printf("macro <filename.mt> [X]\n");
  printf("  filename.mt    - file with machine declaration\n");
  printf("  X              - offset\n");
}