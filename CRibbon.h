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
