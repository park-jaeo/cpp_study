#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  cin >> T;
  for(int i = 0; i < T; ++i){
    string p;
    int n;
    vector<int> arr;

    // 1. 입력
    cin >> p >> n;

    /* -------- 배열 파싱 -------- */
    string array_str;  cin >> array_str;               // 예: [1,2,3]
    istringstream iss_1(array_str);
    string tok;  char ch;
    while (iss_1.get(ch)) {
        if (isdigit(ch) || ch == '-') tok += ch;
        else if (!tok.empty()) { arr.push_back(stoi(tok)); tok.clear(); }
    }
    if (!tok.empty()) arr.push_back(stoi(tok));

    /* -------- 명령 처리 -------- */
    auto left = arr.begin();
    auto right = arr.end();          // [left, right) 가 현재 구간
    bool rev = false, is_error = false;

    for (char c : p) {
        if (c == 'R') { rev = !rev; continue; }

        // 'D'
        if (left == right) { is_error = true; break; }
        rev ? --right : ++left;
    }
    if (is_error) { cout << "error\n"; continue; }



    /* -------- 결과 출력 -------- */
    cout << '[';
    if (!rev) {
        for (auto it = left; it != right; ++it) {
            cout << *it;
            if (it + 1 != right) cout << ',';
        }
    } else {
        for (auto it = right; it != left; ) {
            --it;                    // it 가 실제 원소를 가리키도록 먼저 감소
            cout << *it;
            if (it != left) cout << ',';
        }
    }
    cout << "]\n";
  }
}