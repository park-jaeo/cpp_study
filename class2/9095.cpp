#include <iostream>
#include <cmath>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int arr[11]; // dp
  // base case
  arr[0] = 1; // 1
  arr[1] = 2; // 2
  arr[2] = 4; // 3
  for(int i = 3; i < 11; ++i){
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }

  int T;
  cin >> T;
  for(int i = 0; i < T; ++i){
    int N;
    cin >> N;
    cout << arr[N - 1] << '\n';
  }

  return 0;
}