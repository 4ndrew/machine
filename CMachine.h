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
 * $Id: CMachine.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _CMACHINE_H_
#define _CMACHINE_H_

#include <iostream.h>
#include <fstream.h>
#include <string.h>

#include <stdlib.h>

#include "Ribbon.h"
#include "ErrorCodes.h"

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
