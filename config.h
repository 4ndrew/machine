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
 * $Id: config.h,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

// Standart C Input/Output
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#  define u_char unsigned char
#  define u_long unsigned long
#  define u_int unsigned int
#else
#  define _HAS_VSNPRINTF_
#  include <unistd.h>
#endif

long get_filesize(FILE *);

#endif