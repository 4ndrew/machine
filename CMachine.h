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
 * $Id: CMachine.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _CMACHINE_H_
#define _CMACHINE_H_

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>

#include "Ribbon.h"
#include "ErrorCodes.h"

using namespace std;

/** Machine step structure.
 */
struct s_mtstep {
  /** Next mtstep, "0" - exit, "-1" - exception */
  long next;
  /** New value to set */
  unsigned char newValue;
  /** flag bits:
   *  -+-------+-------+-------+
   *  0| 1 - R | 0 - L | 1 - C
   *  1| 0 /   | 1 /   | 1 /
   *  -+-------+-------+-------+
   *  2| set current to ...
   *  -+-------+-------+-------+
   */
  unsigned char flags;
};

//
// Flags
//

/** goto right */
const unsigned char FGOTO_R          = 1;
/** goto left */
const unsigned char FGOTO_L          = 2;
/** stay center */
const unsigned char FGOTO_C          = FGOTO_L | FGOTO_R;
/** full mask for move detection */
const unsigned char FGOTO_FLAGS      = FGOTO_L | FGOTO_R | FGOTO_C;

/** Class Tuiring Machine. Support different alphabet and ribbons.
 *
 */
class CMachine {
  /** Count of operators */
  unsigned long mCount;
  /** Allocated operators array */
  unsigned long mAllocated;
  /** Operators double-array of commands */
  s_mtstep **mOpers;
  /** Alphabet array */
  unsigned char *mAlphabet;
  /** Alphabet size */
  unsigned char mAlSize;
  /** */
  // Storage<StackData> *debugStack;
 public:
  /** Constructor
   *
   * @param num Number of operators
   * @param alphabet Alphabet array
   * @param alLen Alphabet length
   */
  CMachine(int num, unsigned char alphabet[], unsigned char alLen) {
    mOpers = new s_mtstep* [num];
    mAlphabet = alphabet;
    mAllocated = num;
    mAlSize = alLen;
    mCount = 0;
  }
  
  /** Destructor
   */
  ~CMachine() {
    for (unsigned int i = 0; i < mCount; i++)
      delete [] mOpers[i];
    delete [] mOpers;
  }
  /** Get aplhabet */
  unsigned char *getAlphabet();  
  /** Get aplhabet size */
  unsigned char getAlphabetSize();
  /** Get char index in alphabet */
  unsigned char getCharIndex(unsigned char ch);
  /** Get count */
  long getCount();
  /** Get Allocated */
  long getAllocated();
  /** Add operator */
  int addOperator(s_mtstep *);
  /** Get operator by Index */
  s_mtstep *getOperator(unsigned int, unsigned char);
  /** Start machine */
  int run(Ribbon *);
};

//
// Run status flags
//
/** No errors */
const int ERR_MACHINE_NOERR = 0;
/** Machine operator is empty */
const int ERR_MACHINE_NULL  = 1;
/** Machine out of memory */
const int ERR_MACHINE_MEM   = 2;
/** Illegal move detected (out of bounds) */
const int ERR_MACHINE_MOVE  = 3;
/** Machine infinite loop detected (not supported yet) */
const int ERR_MACHINE_LOOP  = 4;

//
// Utility functions for work with CMachine class.
// 

#define READ_BUFF 255

/** load machine from file */ 
CMachine *loadMachine(const char *, int &);
/** print machine to console */
void printMachine(CMachine *, long);

#endif /* _CMACHINE_H */
