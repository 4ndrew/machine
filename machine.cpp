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
 * $Id: machine.cpp,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#include <iostream.h>

#include <stdio.h>
#include <stdarg.h>

#include "CMachine.h"
#include "Ribbon.h"
#include "ByteRibbon.h"
#include "CRibbon.h"
#include "ErrorCodes.h"
#include "version.h"

/* Abnormal termination (handled exceptions) */
void err(int, char *, ...);
/* Program use mini-help */
void use();

int main(int argc, char **argv) {
  Ribbon *ribbon = NULL;
  CMachine *machine = NULL;
  int errcode = 0;
  
  cout << "Tuiring Machine " << version
       << " (c) 2002-2004 by Andrew A. Porohin" << endl;
  if(argc > 1) {
    machine = loadMachine(argv[1], errcode);
    
    if(machine == NULL) {
      cout << "LoadMachine failed. errcode = " << errcode << endl;
      return -1;
    }
    
    cout << "Machine successfully loaded." << endl;
    printMachine(machine, 0);
    
    if (argc > 2) {
      cout << "'" << machine->getAlphabet() << "'" << endl;
      if (strcmp((char *) machine->getAlphabet(), "01") == 0) {
        cout << "Create ByteRibbon." << endl;
        ribbon = new ByteRibbon();
      } else {
        cout << "Create CRibbon." << endl;
        ribbon = new CRibbon();
      }
      
      errcode = loadRibbon(ribbon, argv[2], machine->getAlphabet());
      if(errcode != RERR_NOERR) {
        cout << "LoadRibbon failed. errcode = " << errcode << endl;
        return -2;
      }
      /* print start position */
      ribbon->goStart();
      cout << "Input:" << endl
           << "..total - 1: "
           << printRibbon(ribbon) << endl;
      ribbon->goStart();
      
      if ((errcode = machine->run(ribbon)) == ERR_MACHINE_NOERR) {
        cout << "Result:" << endl
             << "..total - 1: " << printRibbon(ribbon) << endl;
      } else {
        cerr << "Error start machine, errcode = " << errcode << endl;
      }
    }
    
    /* cleanup */
    delete ribbon;
    delete machine;
  } else {
    use();
  }
  
  return 0;
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
    cerr << buff << endl;
  }
  delete [] buff;
  if(errcode != 0) exit(errcode);
}

void use() {
  cout << "machine <filename.mt> [<input filename>]" << endl
       << "  filename.mt    - file with machine declaration" << endl
       << "  input filename - file with input data" << endl;
}
