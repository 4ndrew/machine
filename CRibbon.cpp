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
