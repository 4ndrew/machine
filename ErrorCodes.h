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
 * $Id: ErrorCodes.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _ERRORCODES_H_
#define _ERRORCODES_H_

//
// Errors
//
/** No error */
const int RERR_NOERR    = 0;
/** Error while file input/output operation */
const int RERR_FILEIO   = -1;
/** Input data format error */
const int RERR_BADDATA  = -2;
/** Overflow buffer */
const int RERR_OVERFLOW = -3;
/** Out of memory error */
const int RERR_OUTMEM   = -4;
/** Internal error */
const int RERR_INTERNAL = -5;

#endif /* _ERRORCODES_H_ */
