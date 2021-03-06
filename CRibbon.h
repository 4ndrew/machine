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
 * $Id: CRibbon.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */
#ifndef _CRIBBON_H_
#define _CRIBBON_H_

#include "Ribbon.h"

/** Stop char */
const unsigned char CRibbonStopChar = '\0';

/** Ribbon class with constant byte aplhabet
 *
 */
class CRibbon :public Ribbon {
 private:
  /* ribbon segment */
  s_ribbonseg *mSegment, *mStartseg;
  /* absolute and segment position */
  long mApos, mSpos;

  /** int. set position */
  void setPosition(s_ribbonseg *);
  /** int. get position */
  s_ribbonseg *getPosition();
  /** create new segment */
  s_ribbonseg *createNewSegment(s_ribbonseg *, s_ribbonseg *);
 public:
  CRibbon() {
    mSegment = createNewSegment(NULL, NULL);
    mStartseg = mSegment;
    mApos = -1;
    mSpos = -1;
  }
  virtual ~CRibbon();
  /** add element */
  virtual void addElement(unsigned char);
  /** get current element */
  virtual unsigned char getElement();
  /** set current element */
  virtual void setElement(unsigned char);
  /** goto start */
  virtual void goStart();
  /** goto right */
  virtual void goRight();
  /** goto left */
  virtual void goLeft();
  /** */
  virtual unsigned char getStopChar() {
    return CRibbonStopChar;
  }
};

#endif /* _CRIBBON_H_ */
