#include <iostream>
#include <vector>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> dp;
  dp.push_back(0); // 1-index
  dp.push_back(1); // dp[1]
  dp.push_back(2); // dp[2]

  for(int i = 3; i <= 1000; ++i){
      dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
  }
  cout << dp[N] << endl;
  return 0;
}
