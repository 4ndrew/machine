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
 * $Id: Ribbon.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _RIBBON_H_
#define _RIBBON_H_

#include <iostream>
#include <fstream>

#include "ErrorCodes.h"

using namespace std;

/** Ribbon segment */
struct s_ribbonseg {
  /** Value */
  unsigned char value;
  /** next, preview */
  s_ribbonseg *next, *prev;
};

/** Abstract ribbon class.
 *
 * @author Andrew A. Porohin
 */
class Ribbon {
  protected:
    /** Ribbon release description */
    char classDesc[127];
  public:
    /** Add element to the ribbon
     */
    virtual void addElement(unsigned char) = 0;
    /** Get curent element of the ribbon
     *
     * @return Current element.
     */
    virtual unsigned char getElement() = 0;
    /** Set current element of the ribbon
     */
    virtual void setElement(unsigned char) = 0;
    /** Reset current element to start
     */
    virtual void goStart() = 0;
    /** Set current element to right
     */
    virtual void goLeft() = 0;
    /** Set curent element to left
     */
    virtual void goRight() = 0;
    /** Return stop character
     */
    virtual unsigned char getStopChar() = 0;
};

/** */
int loadRibbon(Ribbon *, const char *, const unsigned char *);
/** */
long printRibbon(Ribbon *);

#endif /* _RIBBON_H_ */
