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
