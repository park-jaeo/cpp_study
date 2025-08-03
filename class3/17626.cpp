// 17626
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> dp(N + 1, INT_MAX);

  // base case;
  dp[0] = 0;

  // 1 ~ n의 모든 수에 대해 최소 제곱수 개수 계산
  for(int i = 0; i <= N; ++i){
    // i보다 작거나 같은 모든 제곱수에 대해서 확인
    for(int j = 1; j * j <= i; ++j){
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[N] << endl;

  return 0;
}

/*
전략
n 범위 : 1 <= n <= 50000으로 적음, DP로 해결
*/