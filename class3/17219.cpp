#include <iostream>
#include <unordered_map>
using namespace std;

/*
1. 저장된 사이트 주소의 수 : N
  1 <= N <= 100,000

2. 비밀번호를 찾으려는 사이트 주소의 수 : M
  1 <= M <= 100,000

입력자료
<사이트 주소> <비밀번호>

풀어야 하는 자료
<사이트 주소> -> <비밀번호>

key - value 구조
활용 자료 : map(dictionary)
사이트 주소 입력 -> 비밀번호 출력 기능 : 정렬 데이터가 의미 없음 -> unordered_map 사용
*/

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  unordered_map<string, string> sites;
  for(int i = 0; i < N; ++i){
    string s, p; // site, password
    cin >> s >> p;
    sites[s] = p;
  }

  // 사이트 이름에서 패스워드 찾기
  for(int i = 0; i < M; ++i){
    string s;
    cin >> s; // site
    cout << sites[s] << '\n';// O(1)
  }
  return 0;
}