#include <iostream>
#include <vector>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;  cin >> T;

  /* 1. 100번째 항까지 미리 계산 */
  vector<long long> dp(101);
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  for (int i = 6; i <= 100; ++i)
    dp[i] = dp[i - 1] + dp[i - 5];   // 점화식 ②

  /* 2. 테스트 케이스 처리 */
  while (T--) {
    int N;  cin >> N;
    cout << dp[N] << '\n';
  }
  return 0;
}

/*
1 / 0
1 / 0
1 / 0
2 / 1
2 / 0
3 / 1 (n - 5)
4 / 1 (n - 5)
5 / 1 (n - 5)
7 / 2 (n - 5)
9 / 2 (n - 5)
12 / 3 (n - 5)
16 / 4 (n - 5)
21 / 5 (n - 5)
...
*/