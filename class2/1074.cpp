#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

// 10 512 512
// 

// 포함되지 않는 경우 : 이동 및 결과값에 더해주기
// 포함되는 경우 : 재귀 탐색
void solve(int y, int x, int size){
  // 목표 지점을 찾으면 출력 후 종료
  if(y == r && x == c){
    cout << result << '\n';
    return;
  }

  // 현재 정사각형 내에 (row, column 제한조건) 목표지점이 포함되는 경우에 탐색
  if(r >= y && r < y + size && c >= x && c < x + size){
    int half = size / 2;
    solve(y       , x       , half);
    solve(y       , x + half, half);
    solve(y + half, x       , half);
    solve(y + half, x + half, half);
  }
  else{
    // 다음 정사각형을 탐색하는 경우 결과값에 더해준다
    result += size * size;
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> N >> r >> c;
  solve(0,0, pow(2, N));
  return 0;
}

