/** Tuiring Machine
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.
 *
 * Author: Andrew A. Porohin (dron)
 *  email: paa0101@mail.ru
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