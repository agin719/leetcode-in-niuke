/*
 * 题目：candy
 *
 * 题目描述
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 * 题意：
 * 有n个小孩排成一列，每个小人有一个权值，现在要分糖给这些小孩，每个小孩最小要有一颗糖，
 * 而相邻的小孩，权值大的要比权值小的糖多，问最小的糖总数。
 *
 * 题解：
 * 1、每位小孩初始化为1颗糖
 * 2、先从前向后扫描，如果当前小孩的权值比前面那位大，则糖果为前面的+1
 * 3、再从后向前扫描，如果当前小孩的权值比后面那位大，并且糖果小于等于后面那位，则糖果为后面的+1
 */
class Solution {
  public:
    int candy(vector<int> &ratings) {
      vector<int> cc(ratings.size(), 1);
      for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i-1]) { 
          cc[i] = cc[i-1]+1;
        }
      }
      for (int i = ratings.size()-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && cc[i] <= cc[i+1]){
          cc[i] = cc[i+1]+1;
        }
      }
      int sum = 0;
      for (auto &it : cc) {
        sum += it;
      }
      return sum;

    }
};
