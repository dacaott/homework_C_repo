#include "compareBinary.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  int lenA, lenB;

  scanf("%d", &lenA);
  bool a[lenA];
  for (int i = 0; i < lenA; i++) {
    int bit;
    scanf("%d", &bit);
    a[i] = bit ? true : false;
  }

  scanf("%d", &lenB);
  bool b[lenB];
  for (int i = 0; i < lenB; i++) {
    int bit;
    scanf("%d", &bit);
    b[i] = bit ? true : false;
  }

  int result = compareBinary(a, lenA, b, lenB);

  if (result > 0) {
    printf("A > B\n");
  } else if (result < 0) {
    printf("A < B\n");
  } else {
    printf("A == B\n");
  }

  return 0;
}