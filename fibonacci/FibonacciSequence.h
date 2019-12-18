#ifndef __FIBONACCI_SEQUENCE_H__
#define __FIBONACCI_SEQUENCE_H__

#include <cstdint>

class FibonacciSequence {
private:

public:
  FibonacciSequence() {};
  virtual ~FibonacciSequence() {};

  /*!
   *  @brief  フィボナッチ数列を生成
   *  @param  nth   [in]  n項目
  */
  void  GenerateFibonacciSequence(int64_t nth);

protected:
  /*!
   *  @brief  n項目の値を画面出力
   *  @param  nth   [in]  n項目
   *  @param  value [in]  n項目の値
  */
  void  _Print(int64_t nth, int64_t value);

private:
  FibonacciSequence& operator=(const FibonacciSequence&);

};
#endif
