#include <iostream>
#include <vector>
using namespace std;

/*
계단을 밟으면 그 계단에 쓰여있는 점수 획득
1. 계단 수 : +1 또는 +2
2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. (시작점은 포함하지 않는다)
3. 마지막 도착 계단은 반드시 밟아야 한다.


sudo code:
for i <- 3 .. N:
  dp[i] = max(dp[i - 2] + T[i],
              dp[i - 3] + T[i - 1] + T[i])

*/

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  cin >> T;
  vector<int> S(T + 1, 0); // 점수 배열
  
  // 1. 점수 배열에 값 저장
  for(int i = 1; i <= T; ++i){
    cin >> S[i];
  }

  // 2. 누적 점수 배열 선언
  vector<int> dp(T + 1, 0); // 누적 점수 배열
  // 2-1. 초기조건1 : 누적점수배열 첫 계단은 반드시 밟음
  dp[1] = S[1];

  // 2-2. 초기조건2 : 누적점수배열 두 번째 계단은 반드시 밟음
  if(T >= 2){
    dp[2] = S[1] + S[2];
  }

  // Case A : dp[i - 2] + S[i]
    /*
    의미 : i - 2번째 계단에서 2칸을 뛰어넘어 i 번째 계단으로 도달
    연속성 : i - 1번째 계단을 밟지 않으므로 연속 3계단 불가능
    */
  // Case B : dp[i - 3] + S[i - 1] + S[i]
    /*
    의미 : i - 3번째에서 i - 1번째, i - 1번째에서 i번째로 이동
    연속성 : 연속 3계단 불가능
    */
  for(int i = 3; i <= T; ++i){
    dp[i] = max(dp[i - 2] + S[i],
                dp[i - 3] + S[i - 1] + S[i]);
  }
  cout << dp[T] << '\n';
  return 0;
}