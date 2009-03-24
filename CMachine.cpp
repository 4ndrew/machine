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

#include "CMachine.h"

/** Get count of commands items in machine.
 *
 * @return Count of items
 */
long CMachine::getCount() {
  return mCount;
}

/** Get count of allocated objects
 *
 * @return Count of allocated objects
 */
long CMachine::getAllocated() {
  return mAllocated;
}

/** get Alphabet
 *
 * @return Array with alphabet
 */
unsigned char *CMachine::getAlphabet() {
  return mAlphabet;
}

/** Get Alphabet size
 *
 * @return Size of alphabet.
 */
unsigned char CMachine::getAlphabetSize() {
  return mAlSize;
}

/** Add operator to machine.
 *
 * @param oper Array of operators of one step.
 * @return true - if operator successfully added, false - if getCount <=
 * getAllocated (overflow).
 */
int CMachine::addOperator(s_mtstep *oper) {
  if (mCount < mAllocated) {
    mOpers[mCount] = new s_mtstep[mAlSize];
    for (unsigned int i = 0; i < mAlSize; i++)
      mOpers[mCount][i] = oper[i];
    mCount++;
    return true;
  } else {
    return false;
  }
}

/**
 */
unsigned char CMachine::getCharIndex(unsigned char ch) {
  for (int i = 0; i < getAlphabetSize(); i++)
    if (mAlphabet[i] == ch) {
      return i;
    }
  return 0;
}

/** Get operator by index.
 *
 * @param index Index of operator.
 * @param term Alphabet character
 * @return Operator or NULL, if index out of bounds.
 */
s_mtstep *CMachine::getOperator(unsigned int index, unsigned char term) {
  if (mCount > index) {
    return &mOpers[index][getCharIndex(term)];
  } else {
    return NULL;
  }
}

/** Run Tuiring Machine.
 *
 * @param ribbon Ribbon of the machine.
 */
int CMachine::run(Ribbon *ribbon) {
  long currop = 0;   // current number of machine operator
  s_mtstep *oper;    // current machine step
  
  if (mCount == 0)
    return ERR_MACHINE_NULL;
  
  // goto Start of ribbon
  ribbon->goStart();
  
  // begin (let's rock!)
  while (currop >= 0) {
    oper = getOperator(currop, ribbon->getElement());
    if (oper != NULL) {
      /*
      cerr << "start: value=" << ribbon->getElement() 
           << " setto=" << oper->newValue
           << " curr=" << currop
           << " next=" << oper->next - 1
           << endl;
      */

      ribbon->setElement(oper->newValue);

      /*
      cerr << "stop: value=" << ribbon->getElement() 
           << " setto=" << oper->newValue
           << " curr=" << currop
           << " next=" << oper->next - 1
           << endl;
      */
      
      switch (oper->flags & FGOTO_FLAGS) {
       case FGOTO_R: ribbon->goRight(); break;
       case FGOTO_L: ribbon->goLeft(); break;
      }
      currop = oper->next - 1;
    } else {
      return ERR_MACHINE_MOVE;
    }
  }
  return ERR_MACHINE_NOERR;
}


//
// Util Functions for CMachine class
//

/** Removed comment from line.
 */
void cutComment(char *buff, int len) {
  for(int i=0; i<len; i++)
    if(buff[i] == '#' || buff[i] == 13 || buff[i] == 10) {
      buff[i] = '\0';
      break;
    }
}

//
//
//
/* start parsing */
const unsigned int STATE_BEGIN      = 0;
/* alphabet size set */
const unsigned int STATE_ALP_SIZE   = 1;
/* alphabet set */
const unsigned int STATE_ALP_SET    = 2;
/* operators count set */
const unsigned int STATE_OPER_COUNT = 3;

/** load machine from file.
 */
CMachine *loadMachine(const char *fileName, int &errcode) {
  unsigned char alphabetSize = 0;     // alphabet size
  unsigned char *alphabet;
  unsigned char prev = 0,             // prev number
                term = 0,             // term
                summ = 0;             // summ
  unsigned long state = STATE_BEGIN;  // input data counter
  unsigned char counter = 0;          // operator counter [0-1]
  char buff[READ_BUFF];               // read buffer
  s_mtstep *oper;                     // operator
  CMachine *machine = NULL;           // machine
  ifstream input(fileName, ios::in);  // input file
  
  if(input.fail()) {
    errcode = RERR_FILEIO;
    return NULL;
  }
  
  while (!input.fail()) {
    input.getline(buff, READ_BUFF, '\n');
    cutComment(buff, READ_BUFF);
    if (strlen(buff) > 0) {
      if (state == STATE_BEGIN) {
        alphabetSize = atoi(buff);
        if (alphabetSize == 0) {
          errcode = RERR_BADDATA;
          return NULL;
        }
        state++;
      } else if (state == STATE_ALP_SIZE) {
        alphabet = new unsigned char[strlen(buff) + 1];
        strcpy((char *) alphabet, (char *) buff);
        state++;
      } else if (state == STATE_ALP_SET) {
        long size = atoi(buff);
        machine = new CMachine(size, alphabet, alphabetSize);
        cout << "Created machine with size=" << size
             << " alphabet=" << alphabet
             << " alphabetSize=" << (int) alphabetSize << endl;
        if (machine == NULL) {
          errcode = RERR_OUTMEM;
          return NULL;
        }
        state++;
      }
      else if(state >= STATE_OPER_COUNT) {
        counter = 0;
        oper = new s_mtstep[alphabetSize];
        for(unsigned int i = 0; i < strlen(buff); i++) {
          oper[counter].flags = 0;
          switch(buff[i]) {
          case ' ': case 'q': break;
          case 'R': case 'L': case 'C':
            if(buff[i] == 'R') oper[counter].flags |= FGOTO_R;
            else if(buff[i] == 'L') oper[counter].flags |= FGOTO_L;
            else oper[counter].flags |= FGOTO_C;

            /*
            cout << "NewValue=" << prev
                 << "Next=" << (int) summ << endl;
            */
            
            oper[counter].next = summ;
            oper[counter].newValue = prev;
            counter++;
            prev = 0;
            summ = 0;
            break;
          case '0': case '1': case '2': case '3': case '4':
          case '5': case '6': case '7': case '8': case '9':
            summ *= 10;
            summ += prev;
            term = buff[i];
            prev = term - 48;
            break;
          default:
            cerr << "bad symbol: " << buff[i] << endl;
            errcode = RERR_BADDATA;
            delete machine;
            return NULL;
          }
        } /* for */
        if(counter == 0) {
          errcode = RERR_BADDATA;
          delete machine;
          return NULL;
        }
        
        if (!machine->addOperator(oper)) {
          cerr << "AddOperator failed." << endl;
          input.close();
          delete machine;
          errcode = RERR_INTERNAL;
          return NULL;
        }
      } /* if cnt > STATE_OPER_COUNT */
    } /* if strlen(buff) > 0 */
  } /* while */
  input.close();
  errcode = RERR_NOERR;
  return machine;
}

/** Print machine
 */
void printMachine(CMachine *machine, long delta) {
  char tmp = 'U';
  unsigned char *alphabet;
  s_mtstep *tmpoper;
  
  if(machine != NULL) {
    alphabet = machine->getAlphabet();
    for (int c = 0; c < machine->getAlphabetSize(); c++)
      cout << alphabet[c] << "\t";
    cout << endl;
    for (int i = 0; i < machine->getCount(); i++) {
      for (int j = 0; j < machine->getAlphabetSize(); j++) {
        if((tmpoper = machine->getOperator(i, j + 48)) == NULL) {
          cerr << "Cannot get operator # " << i << endl; return;
        }
        switch(tmpoper->flags & FGOTO_FLAGS) {
         case FGOTO_R: tmp = 'R'; break;
         case FGOTO_L: tmp = 'L'; break;
         case FGOTO_C: tmp = 'C'; break;
        }
        cout << 'q'
             << (tmpoper->next + delta)
             << tmpoper->newValue
             << tmp
             << '\t';
      }
      cout << endl;
    }
  } else {
    cerr << "Machine null." << endl;
  }
}
