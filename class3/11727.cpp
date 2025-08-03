// 11727 (DP)
#include <iostream>
#include <vector>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  vector<int> dp = {1, 3, 5};
  int N;
  cin >> N;
  for(int i = 3; i < N; ++i){ // 0-index
    dp.push_back((dp[i - 2] * 2 + dp[i - 1]) % 10007);
  }
  cout << dp[N - 1] % 10007 << '\n'; // 0-index
}
/*
2 x 1 : 1개 경우
2 x 2 : 3개 경우
2 x 3 : 5개 경우
2 x 4 : 11개
2 x 5 : 21개

a(n) = 2 * a(n - 2) + a(n - 1);
*/