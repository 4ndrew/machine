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
 * $Id: Ribbon.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _RIBBON_H_
#define _RIBBON_H_

#include <iostream.h>
#include <fstream.h>

#include "ErrorCodes.h"

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
