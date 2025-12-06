#include "compareBinary.h"

int compareBinary(const bool *a, int lenA, const bool *b, int lenB) {
  if (lenA > lenB)
    return 1;
  if (lenA < lenB)
    return -1;

  for (int i = 0; i < lenA; i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i] ? 1 : -1;
    }
  }
  return 0;
}
