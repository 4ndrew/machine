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
 * $Id: config.cpp,v 1.1 2005/01/26 00:04:13 dron Exp $
 */

#include "config.h"

long get_filesize(FILE *fd) {
  long res = 0;
  long spos = ftell(fd);
  fseek(fd, 0L, SEEK_END);
  res = ftell(fd);
  fseek(fd, spos, SEEK_SET);
  return res;
}