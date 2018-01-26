#include <string>
#include <stdio.h>
#include "../inc/toLowerCase.h"

using namespace std;

class Palindrome {
  public: static bool isPalindrome(string word) {
    int begCharCount = 0;
    int endCharCount = word.length() - 1;
    bool retVal = true;
    for (NULL; begCharCount < endCharCount; begCharCount++, endCharCount--) {
      if (word[begCharCount] != word[endCharCount]) {
        retVal = false;
        break;
      }
    }
    return retVal;
  }
};

int main() {
  string palindromeInQuestion = "Deleveled";
  
  printf(
    "Q: Is '%s' a palindrome?\nA: %s\n", 
    palindromeInQuestion.c_str(), 
    (Palindrome::isPalindrome(toLowerCase(palindromeInQuestion)) ? "Yes" : "No")
  );
}