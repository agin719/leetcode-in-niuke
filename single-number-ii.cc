/*
 * 未完成
 */
#include <iostream>
using namespace std;
class Solution {
  public:
    int singleNumber(int A[], int n) {
      int sum1 = 0;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum1 ^= A[i];
        sum += A[i];
      }
      cout << sum1 <<","<< sum << endl;
      return ((sum1*3-sum)/2);
    }
};

int main(){
  int a[] = {2, 2, 3, 2};
  Solution sol;
  cout << sol.singleNumber(a, 4) << endl;
  return 0;
}
  
