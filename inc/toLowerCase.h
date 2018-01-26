#ifndef TOLOWERCASE_H
#define TOLOWERCASE_H

#include <cstring>

using namespace std;

string toLowerCase (const string _word) {
  string _wordCopy = _word;
  for (int _chr = 0; _chr < sizeof(_word); _chr++) {
    int _chrNum = (int)_word[_chr];
    if ((_chrNum < 91) && (_chrNum > 64)) {
      _wordCopy[_chr] = (char)(_chrNum + 32);
    } else {
      _wordCopy[_chr] = _word[_chr];
    }
  }
  return _wordCopy;
}

#endif