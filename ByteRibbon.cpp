#include "ByteRibbon.h"

/** Destructor
 */
ByteRibbon::~ByteRibbon() {
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
void ByteRibbon::addElement(unsigned char value) {
  s_ribbonseg *tmp = NULL;
  // Convert char to int.
  value -= 48;
  mApos++;
  mSpos++;
  if(mSpos > 7) {
    mSpos = 0;
    if(mSegment->next == NULL) {
      tmp = createNewSegment(mSegment, NULL);
      mSegment->next = tmp;
    }
    mSegment = mSegment->next;
  }
  if(value == 1) mSegment->value |= (1 << mSpos);
}

/** Set current element
 */
void ByteRibbon::setElement(unsigned char value) {
  value -= 48;
  if(value == 1) mSegment->value |= (1 << mSpos);
  else mSegment->value &= (0xff ^ (1 << mSpos));
}

/** Get current element
 */
unsigned char ByteRibbon::getElement() {
  return (((mSegment->value) >> mSpos)&1) + 48;
}

/** Set current element to start
 */
void ByteRibbon::goStart() {
  mSegment = mStartseg;
  mApos = 0;
  mSpos = 0;
}

/** go right
 */
void ByteRibbon::goRight() {
  s_ribbonseg *tmp = NULL;
  mApos++;
  mSpos++;
  if(mSpos > 7) {
    mSpos = 0;
    if(mSegment->next == NULL) {
      tmp = createNewSegment(mSegment, NULL);
      mSegment->next = tmp;
    }
    mSegment = mSegment->next;
  }
}

/** go left
 */
void ByteRibbon::goLeft() {
  s_ribbonseg *tmp = NULL;
  mApos--;
  mSpos--;
  if(mApos < 0) mApos = 7;
  if(mSpos < 0) {
    mSpos = 7;
    if(mSegment->prev == NULL) {
      tmp = createNewSegment(NULL, mSegment);
      mSegment->prev = tmp;
    }
    mSegment = mSegment->prev;
  }
}

/** Get position
 */
s_ribbonseg *ByteRibbon::getPosition() {
  return mSegment;
}

/** Set position
 */
void ByteRibbon::setPosition(s_ribbonseg *segment) {
  mSegment = segment;
}

/** Create new element.
 *
 */
s_ribbonseg *ByteRibbon::createNewSegment(s_ribbonseg *prev, s_ribbonseg *next) {
  s_ribbonseg *tmp = new s_ribbonseg;
  tmp->next = next;
  tmp->prev = prev;
  tmp->value = 0;
  return tmp;
}
