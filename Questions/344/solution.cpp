/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */
class Solution {
public:
  string reverseString(string s) {
    int length = s.length();
    string result (length, 'x');
    for(int i=0; i<length; i++)
      {
        result[length-1 - i] = s[i];
      }
    return result;
  }
};
