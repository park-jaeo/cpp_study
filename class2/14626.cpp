// 14626
#include <iostream>
using namespace std;


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  string spolied_isbn;
  getline(cin, spolied_isbn);
  int normal_num = 0;
  int starnum_weight = 1;
  int starnum;
  // a + 3b + ... + k + 3l + m = 0 (mod 10)
  for(int i = 0; i < spolied_isbn.length(); ++i){
    int weight;
    if(i % 2 == 0){
      weight = 1;
    }
    else{
      weight = 3;
    }

    if(isdigit(spolied_isbn[i])){
      normal_num += (spolied_isbn[i] - '0') * weight;
    }
    else if(spolied_isbn[i] == '*'){
      starnum_weight = weight;
    }
  }
  int total_sum_mod = normal_num % 10;

  int missing_number;

  if(starnum_weight == 1){ 
    // 가중치가 1인 경우
    missing_number = (10 - total_sum_mod) % 10;
  } else {
    // 가중치 3인 경우, 3의 역원은 7이다
    missing_number = ( (10 - total_sum_mod) * 7 ) % 10;
  }

  cout << missing_number << '\n';

  return 0;
}