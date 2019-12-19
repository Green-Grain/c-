#include "FibonacciSequence.h"
#include <stdio.h>

void  FibonacciSequence::GenerateFibonacciSequence(int64_t nth) {
  int64_t tmp[3] = {0, 1, 0};
  if (0 > nth) {
    printf("入力値(%lld)が不正です。\n", nth);
    return;
  }
  if (0 == nth) {
    _Print(nth, tmp[nth]);
    return;
  }
  for (int index = 0; index < 2; index++) {
    _Print(index, tmp[index]);
  }
  for (int index = 2; index <= nth; index++) {
    tmp[2] = tmp[0] + tmp[1];
    _Print(index, tmp[2]);
    tmp[0] = tmp[1];
    tmp[1] = tmp[2]; 
  }
}

void  FibonacciSequence::_Print(int64_t nth, int64_t value) {
  printf("n[%lld] %lld\n", nth, value);
}
