/*
 * 题目：
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note: 
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * 题解：
 * 一个整数数组，每个元素都出现了两个，只有一个元素出现一次，找到这个只出现一次的元素。时间复杂度为O(n)，空间复杂度为O(1)
 * 采用异或，因为两个相同的数异或等于0,
 */

class Solution {
  public:
    int singleNumber(int A[], int n) {
      int ans = 0;
      for (int i = 0; i < n; i++)
        ans ^= A[i];
      return ans;
    }
};
