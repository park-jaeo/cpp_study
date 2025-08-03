#include <iostream>
#include <vector>
using namespace std;

string solution(int money, vector<vector<int>> cost, vector<string> name) {
    string answer ="";
    long max_distance = 0;
    // 가장 긴 거리를 갈 수 있는 차량 : "D", 50km를 1000원에 갈 수 있음

    for (int i = 0; i < cost.size(); i++) {
        int oil = money / cost[i][1]; // 몇L를 주유 가능한지
        long distance = oil * cost[i][0]; //갈 수 있는 거리
        if (distance > max_distance) {
            max_distance = distance;
            answer = name[i];
        }
    }

    return answer;
}

int main() {
    int money = 100000;
    vector<vector<int>> cost = { {50, 5000}, {20, 1000}, {20, 5000}, {50, 1000} };
    vector<string> name = { "A", "B", "C", "D" };

    // 차량의 이름 배열 name, 차량 운행 금액 money, <차량의 연비, 유류비> cost
    // 운행가능한 거리가 가장 긴 차량의 이름을 return하도록 solution함수 작성
    string ret = solution(money, cost, name);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
    return 0;
}