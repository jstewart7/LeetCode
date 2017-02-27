/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
 */

class Solution {
public:
    int getSum(int a, int b) {
      int sumwithoutcarries = 0;
      int carries = 0;
      int shifted = 0;
      int temp = 0;
      int current = 0;
      do {
        carries = a & b;
        //negative case isn't working, maybe check to see if the negative value is larger then shift in the opposite direction
        shifted = carries << 1;
        sumwithoutcarries = a ^ b;
        temp = sumwithoutcarries ^ shifted;
        current = current ^ temp;
      } while (carries != 0);
      return current;
    }
};
