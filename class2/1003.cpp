#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
각 테스트 케이스 N에 대해서, 0이 출력되는 횟수, 1이 출력되는 횟수 출력

유니폼 초기화 (Uniform Initialization)은 C++11부터 도입된 기능이다.
중괄호 { } 를 사용하여, pair<int, int> 등 모든 타입의 객체를 일관된 방식으로 초기화할 수 있다.
*/

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  // 피보나치 0,1 누적 배열 선언 (누적 0개수, 누적 1개수)
  vector<pair<int, int>> zero_one;
  zero_one.push_back({1,0});
  zero_one.push_back({0,1}); // 초기 0,1값 추가

  // 데이터 범위 : <= 40
  for(int i = 2; i <= 40; ++i){
    zero_one.push_back(
      {
        zero_one[i - 1].first  + zero_one[i - 2].first,
        zero_one[i - 1].second + zero_one[i - 2].second
      }
    );
  }

  int T;
  cin >> T;
  for(int i = 0; i < T; ++i){
    int zc = 0, oc = 0; // zero_count, one_count
    int N;
    cin >> N;
    cout << zero_one[N].first << " " << zero_one[N].second << '\n';
  }
  return 0;
}


