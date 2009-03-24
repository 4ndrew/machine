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
 */

#include "Ribbon.h"

int checkChar(const unsigned char ch, const unsigned char *alphabet) {
  for (unsigned int i = 0; i < strlen((char *) alphabet); i++) {
    if (ch == alphabet[i])
      return true;
  }
  return false;
}

/**
 */
int loadRibbon(Ribbon *ribbon, const char *fileName,
               const unsigned char *alphabet) {
  char buff = 0;
  ifstream input(fileName);

  if (input.fail()) {
    return RERR_FILEIO;
  }

  if (ribbon == NULL) {
    return RERR_OUTMEM;
  }
  
  while (!input.fail()) {
    input.read(&buff, 1);
    if (!input.fail()) {
      if (checkChar((unsigned char) buff, alphabet)) {
        ribbon->addElement((unsigned char) buff);
      } else {
        cerr << "loadRibbon() failed: unexpected input char sequence: `"
             << ios::hex << (int) buff << ios::dec
             << "'" << endl;
        return RERR_BADDATA;
      }
    }
  }
  input.close();
  return RERR_NOERR;
}

/** print Ribbon
 */
long printRibbon(Ribbon *ribbon) {
  unsigned char elem = 0;
  long counter = -1;

  while((elem = ribbon->getElement()) != ribbon->getStopChar()) {
    counter++;
    cout << elem;
    ribbon->goRight();
  }
  cout << endl;
  return counter;
}