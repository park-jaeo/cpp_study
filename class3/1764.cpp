#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> // 문자열은 정렬 안함 -> unordered_set
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  unordered_set<string> A; // 듣지 못한 사람 set 선언
  A.reserve(N); // 데이터 크기 : N -> 리해시 최소화 가능
  for(int i = 0; i < N; ++i){
    string s;
    cin >> s;
    A.insert(move(s)); // move를 이용해 연산 최소화
  }

  vector<string> result;
  // 결과 저장
  for(int i = 0; i < M; ++i){
    string s; // 조건 B 임시문자열
    cin >> s;
    if(A.find(s) != A.end()){
      result.push_back(move(s));
    }
  }
  
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for(const auto& name : result){
    cout << name << '\n';
  }

  return 0;
}