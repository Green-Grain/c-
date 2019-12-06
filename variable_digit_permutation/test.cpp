#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
using namespace std;

const char words[] = "abcdefghij";
const int  wordNum  = (sizeof(words) / sizeof(words[0])) - 1;
bool       g_isFileOutput = false;

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
      if (true == g_isFileOutput) {
        outputFile << result.c_str();
      }
    }
  }
}

int main() {
  int digit = 0;
  printf("\"%s\"から順列(重複あり)を作成します。\n", words);
  printf("桁数を入力して下さい(7桁まで)\n");
  printf(">");
  scanf("%d", &digit);
  if ((0 >= digit) || (7 < digit)) {
    printf("%d桁は未サポートです。終了します。\n", digit);
    return -1;
  }

  char inputChar = 0;
  printf("ファイルに出力しますか？(y/n)>");
  scanf(" %c", &inputChar);
  if ('y' == inputChar || 'Y' == inputChar) {
    g_isFileOutput = true;
  }

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
