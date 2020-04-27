#include <iostream>
using namespace std;

/*
errorCodeType readFile {
  initialize errorCode = 0;
  open the file;
  if (theFilesOpen) {
    determinze its size;
    if (gotFileLength) {
      allocate that much memory;
      if (gotEnoughMemory) {
        read the file into memory;
        if (readFailed) {
          errorCode = -1;
        }
      } else {
        errorCode = -2;
      }
    } else {
      errorCode = -3;
    }
  }
  close the file;
  if (theFILEDidntClose && errorCode == 0) {
    errorCode = -4;
  } else {
    errorCode = -5;
  }
  return errorCode;
}
*/