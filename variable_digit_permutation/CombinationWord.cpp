#include  "CombinationWord.h"

bool  CombinationWord::Initialize(char* pCandidateChar, int candidateCharNum) {
  if (nullptr == pCandidateChar)  return false;

  m_pCandidateChar = new char[candidateCharNum];
  if (nullptr == m_pCandidateChar) return false;

  m_candidateCharNum = candidateCharNum;
  memset(m_pCandidateChar, 0, sizeof(char) * candidateCharNum);
  m_outputFile.open(OUTPUT_FILE_NAME);
  return true;
}

void  CombinationWord::GenerateCombination(int digitNth, int digitMax, char* p_result) {
  if (nullptr == p_result) return;

  for (int wordIndex = 0; wordIndex < m_candidateCharNum; wordIndex++) {
    int setIndex = digitMax - digitNth;
    p_result[setIndex] = m_pCandidateChar[wordIndex];
    if (1 < digitNth) {
      GenerateCombination(digitNth - 1, digitMax, p_result);
    }
    else {
      string result(p_result);
      result += "\n";
      printf("%s", result.c_str());
      if (true == m_isFileOutput) {
        m_outputFile << result.c_str();
      }
    }
  }
}