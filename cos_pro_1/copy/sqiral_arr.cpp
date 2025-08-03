// 문제5 : 소용돌이 수 구현
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n){
  vector<vector<int>> spiral(n, vector<int>(n, 0));
  int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
  int num = 1; // 채울 문자
  while(num <= n * n){// num의 범위 : [1 , n * n]
    // 오른쪽으로 채우는 경우 -> 1개 행을 채움
    // -> 열 증가 처리
    for(int i = colStart; i < colEnd; ++i){
      spiral[rowStart][i] = num++;
    }
    rowStart++;

    // 아래로 채우기
    for(int i = rowStart; i < rowEnd; ++i){
      spiral[i][colEnd] = num++;
    }
    colEnd--;

    // 왼쪽으로 채우기
    for(int i = colEnd; i >= colStart; --i){
      spiral[rowEnd][i] = num++;
    }
    rowEnd--;

    // 위로 체우기
    for(int i = rowEnd; i >= rowStart; --i){
      spiral[i][colStart] = num++;
    }
    colStart++;
  }
  int answer = 0;
  for(int i = 0; i < n; ++i){
    answer += spiral[i][i];
  }
  return answer;
}

int main() {
    int n1 = 3;
    int ret1 = solution(n1);
     
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    int n2 = 2;
    int ret2 = solution(n2);

    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}