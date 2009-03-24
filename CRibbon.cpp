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

#include "CRibbon.h"

/** Destructor
 */
CRibbon::~CRibbon() {
  s_ribbonseg *p, *tmp;
  tmp = p = mSegment->next;
  while(p != NULL) {
    p = p->next;
    delete tmp;
    tmp = p;
  }
  tmp = p = mSegment->prev;
  while(p != NULL) {
    p = p->prev;
    delete tmp;
    tmp = p;
  }
  delete mSegment;
}

/** Add element
 */
void CRibbon::addElement(unsigned char value) {
  s_ribbonseg *tmp = NULL;
  mApos++;
  if(mSegment->next == NULL) {
    tmp = createNewSegment(mSegment, NULL);
    mSegment->next = tmp;
  }
  mSegment = mSegment->next;
  mSegment->value = value;
}

/** Set current element
 */
void CRibbon::setElement(unsigned char value) {
  mSegment->value = value;
}

/** Get current element
 */
unsigned char CRibbon::getElement() {
  return mSegment->value;
}

/** Set current element to start
 */
void CRibbon::goStart() {
  mSegment = mStartseg;
  mApos = 0;
}

/** go right
 */
void CRibbon::goRight() {
  s_ribbonseg *tmp = NULL;
  mApos++;
  if(mSegment->next == NULL) {
    tmp = createNewSegment(mSegment, NULL);
    mSegment->next = tmp;
  }
  mSegment = mSegment->next;
}

/** go left
 */
void CRibbon::goLeft() {
  if(mSegment->prev == NULL) {
    s_ribbonseg *tmp = NULL;
    tmp = createNewSegment(NULL, mSegment);
    mSegment->prev = tmp;
  }
  mSegment = mSegment->prev;
}

/** Create new element.
 *
 */
s_ribbonseg *CRibbon::createNewSegment(s_ribbonseg *prev, s_ribbonseg *next) {
  s_ribbonseg *tmp = new s_ribbonseg;
  tmp->next = next;
  tmp->prev = prev;
  tmp->value = 0;
  return tmp;
}

/** Get position
 */
s_ribbonseg *CRibbon::getPosition() {
  return mSegment;
}

/** Set position
 */
void CRibbon::setPosition(s_ribbonseg *segment) {
  mSegment = segment;
}
