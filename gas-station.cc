/*
 * 题目：
 * There are N gas stations along a circular route, where the amount of gas at station i isgas[i].
 *
 * You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note: 
 * The solution is guaranteed to be unique.
 *
 * 题解：
 * 题目大意就是有n个加油站围成一圈，每个加油站有油gas[i], 从第i个到第i+1个油站需要油cost[i]，车子可以装无限的油，问在哪个加油站出发可以环行一圈。
 * 将每个加油站gas[i]-cost[i]=left[i]，得到这个加油站到下一站后剩下的油，负数表示不够油，思路就是从这个环形left中找到最大的子序列就好。起点就是这个子序列的开始点,因为从可以累积油最大的序列出发必定可以保证剩油最多。
 */
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      int size = gas.size();
      vector<int> left;
      for (int i = 0; i < size; i++) {
        int left_gas = gas[i] - cost[i];
        left.push_back(left_gas);
      }
      int max_begin = 0;
      int begin = 0;
      int max_left = 0;
      int cur = 0;
      bool is_second = false;
      for (int i = 0; i < size; ) {
        cur += left[i];
        if (cur > max_left) {
          max_left = cur;
          max_begin = begin;
        } 
        if (++i == size && !is_second) {
          i = 0;
          is_second = true;
        }
        if (cur < 0) {
          cur = 0;
          begin = i;
        }
      }
      int i = max_begin;
      int sum = 0;
      for (int time = 0; time < size; time++) {
        sum += gas[i] - cost[i];
        if (sum < 0) 
          return -1;
        if (++i == size) 
          i = 0;
      }
      return max_begin;
    }
};
