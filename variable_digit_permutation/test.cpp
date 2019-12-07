#include <stdio.h>
#include <iostream>
#include "CombinationWord.h"
using namespace std;

const char words[] = "abcdefghij";
const int  wordNum  = (sizeof(words) / sizeof(words[0])) - 1;

int main() {
  int digit = 0;
  printf("\"%s\"から順列(重複あり)を作成します。\n", words);
  printf("桁数を入力して下さい(7桁まで)\n");
  printf(">");
  // scanf("%d", &digit);
  cin >> digit;
  if ((0 >= digit) || (7 < digit)) {
    printf("%d桁は未サポートです。終了します。\n", digit);
    return -1;
  }

  char inputChar = 0;
  bool isFileOutput = false;
  printf("ファイルに出力しますか？(y/n)>");
  scanf(" %c", &inputChar);
  if ('y' == inputChar || 'Y' == inputChar) {
    isFileOutput = true;
  }

  CombinationWord combination;
  combination.Initialize(words, wordNum, isFileOutput);

  char* p_work = new char[digit];
  if (nullptr == p_work)  return -1;
  combination.GenerateCombination(digit, digit, p_work);
  if (nullptr != p_work) {
    delete[] p_work;
    p_work = nullptr;
  }

  return 0;
}
