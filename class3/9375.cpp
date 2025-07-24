#include <iostream>
#include <vector>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  cin >> T;
  for(int i = 0; i < T; ++i){
    vector<pair<string, int>> name_kind;
    int n;
    cin >> n;

    for(int j = 0; j < n; ++j){
      string name, kind;
      cin >> name >> kind;
      bool kind_found = false;
      for(auto& nk : name_kind){
        if(nk.first == kind){
          kind_found = true;
          ++nk.second;
          break;
        }
      }
      if(!kind_found){
        name_kind.push_back({kind, 1});
      }
    }

    int nkcase = 1;
    int not_aware = 0;
    for(auto& nk : name_kind){
      nkcase *= (nk.second + 1); // +1 : 입지 않는 경우 추가
    }
    cout << nkcase - 1 << '\n'; // -1 : 아무것도 입지 않는 경우의 수는 없음
  }
}