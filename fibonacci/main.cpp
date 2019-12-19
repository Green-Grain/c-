#include <iostream>
#include "FibonacciSequence.h"
using namespace std;

int main() {
  cout << "フィボナッチ数列を表示します。" << endl;
  cout << "何項目まで表示しますか？" << endl;
  cout << "n=";
  int64_t n = 0;
  cin >> n;
  FibonacciSequence fibonacci;
  fibonacci.GenerateFibonacciSequence(n);

  return 0;
}