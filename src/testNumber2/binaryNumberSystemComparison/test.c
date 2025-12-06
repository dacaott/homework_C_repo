#include "compareBinary.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  bool a1[] = {1, 0, 1};
  bool b1[] = {1, 0, 0};

  bool a2[] = {1, 1, 0};
  bool b2[] = {1, 1, 0};

  bool a3[] = {1, 0, 0};
  bool b3[] = {1, 0, 1};

  printf("Test 1: %d\n", compareBinary(a1, 3, b1, 3)); // 1
  printf("Test 2: %d\n", compareBinary(a2, 3, b2, 3)); // 0
  printf("Test 3: %d\n", compareBinary(a3, 3, b3, 3)); // -1

  return 0;
}
