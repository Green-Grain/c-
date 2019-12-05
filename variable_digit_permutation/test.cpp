#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
using namespace std;

const char words[] = "abcdefghij";
const int wordNum  = (sizeof(words) / sizeof(words[0])) - 1;

/*!
 * @brief 文字組み合わせ
 * @param digitNth    [in]  何桁目
 * @param digitMax    [in]  最大桁数
 * @param p_result    [in/out]  組み合わせ後の文字列
 * @param outputFile  [out] 出力先ファイル
*/
void  combinateWord(int digitNth, int digitMax, char* p_result, ofstream& outputFile) {
  if (nullptr == p_result) return;

  for (int wordIndex = 0; wordIndex < wordNum; wordIndex++) {
    int setIndex = digitMax - digitNth;
    p_result[setIndex] = words[wordIndex];
    if (1 < digitNth) {
      combinateWord(digitNth - 1, digitMax, p_result, outputFile);
    }
    else {
      string result(p_result);
      result += "\n";
      printf("%s", result.c_str());
      outputFile << result.c_str();
    }
  }
}

int main() {
  int digit = 0;
  printf("桁数を入力して下さい(7桁まで推奨。8桁以上は処理負荷が高いです)\n");
  printf(">");
  scanf("%d", &digit);

  char* p_result = new char[digit];
  if (nullptr == p_result)  return -1;
  memset(p_result, 0, sizeof(char) * digit);
  ofstream outputFile("result.txt");
  combinateWord(digit, digit, p_result, outputFile);
  outputFile.close();
  if (nullptr != p_result) {
    delete[] p_result;
    p_result = nullptr;
  } 

  return 0;
}
