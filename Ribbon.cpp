#include "Ribbon.h"

int checkChar(const unsigned char ch, const unsigned char *alphabet) {
  for (unsigned int i = 0; i < strlen((char *) alphabet); i++) {
    if (ch == alphabet[i])
      return true;
  }
  return false;
}

/**
 */
int loadRibbon(Ribbon *ribbon, const char *fileName,
               const unsigned char *alphabet) {
  char buff = 0;
  ifstream input(fileName);

  if (input.fail()) {
    return RERR_FILEIO;
  }

  if (ribbon == NULL) {
    return RERR_OUTMEM;
  }
  
  while (!input.fail()) {
    input.read(&buff, 1);
    if (!input.fail()) {
      if (checkChar((unsigned char) buff, alphabet)) {
        ribbon->addElement((unsigned char) buff);
      } else {
        cerr << "loadRibbon() failed: unexpected input char sequence: `"
             << ios::hex << (int) buff << ios::dec
             << "'" << endl;
        return RERR_BADDATA;
      }
    }
  }
  input.close();
  return RERR_NOERR;
}

/** print Ribbon
 */
long printRibbon(Ribbon *ribbon) {
  unsigned char elem = 0;
  long counter = -1;

  while((elem = ribbon->getElement()) != ribbon->getStopChar()) {
    counter++;
    cout << elem;
    ribbon->goRight();
  }
  cout << endl;
  return counter;
}