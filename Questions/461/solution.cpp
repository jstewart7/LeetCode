/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 <= x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       |   |

The above arrows point to positions where the corresponding bits are different.

*/
class Solution {
public:
  int hammingDistance(int x, int y) {
    unsigned int xorBits = x ^ y;//This finds all the bits that are different

    //SWAR hamming weight algorithm
    unsigned int count = xorBits - ((xorBits >> 1) & 0x55555555);
    count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
    count = (((count + (count >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    return count;
  }
};
