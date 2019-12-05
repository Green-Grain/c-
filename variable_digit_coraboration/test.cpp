#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
using namespace std;

const char words[] = "abcdefghij";
const int wordNum  = (sizeof(words) / sizeof(words[0])) - 1;
typedef list<string> string_list;

/*!
 * @brief 文字組み合わせ
 * @param digitNth      [in]  何桁目
 * @param digitMax      [in]  最大桁数
 * @param p_result      [in/out]  組み合わせ後の文字列
 * @param p_resultList  [out] 組み合わせ後の文字列リスト
*/
void  combinateWord(int digitNth, int digitMax, char* p_result, string_list* p_resultList) {
  if (nullptr == p_result) return;
  if (nullptr == p_resultList) return;

  for (int wordIndex = 0; wordIndex < wordNum; wordIndex++) {
    int setIndex = digitMax - digitNth;
    p_result[setIndex] = words[wordIndex];
    if (1 < digitNth) {
      combinateWord(digitNth - 1, digitMax, p_result, p_resultList);
    }
    else {
      p_resultList->push_back(string(p_result));
    }
  }
}

int main() {
  int digit = 0;
  printf("桁数を入力して下さい：");
  scanf("%d", &digit);

  char* p_result = new char[digit];
  memset(p_result, 0, sizeof(char) * digit);
  string_list resultList;
  combinateWord(digit, digit, p_result, &resultList);
  ofstream outputFile("result.txt");
  string_list::iterator itr = resultList.begin();
  for( ; itr != resultList.end(); ++itr) {
    *itr = *itr + "\n";
    printf("%s", itr->c_str());
    outputFile << itr->c_str();
  }
  outputFile.close();

  return 0;
}
