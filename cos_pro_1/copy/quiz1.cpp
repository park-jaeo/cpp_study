#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
빈칸 채우기

최고 점수와 최소 점수를 제외한 점수들의 평균을 평가 점수로 사용함
평가위원들의 점수가 담긴 2차원 배열 scores가 solution함수의 매개변수로 주어짐

오디션 프로그램에서 가장 높은 평가 점수를 return하도록 solution 함수를 작성하려 함


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> func_a(vector<vector<int>> arr) {
    // 최고 점수와 최소 점수를 제외한 점수 배열 ret을 정의한다.
    vector<vector<int>> ret(arr.size(), vector<int> (arr[1].size() - 2, 0)); // 크기 -2로 초기화, value 0으로 초기화
    for (int i = 0; i < arr.size(); i++) {
        sort(arr[i].begin(), arr[i].end());
        for (int j = 1; j < arr[i].size() - 1; j++) {
            ret[i][j - 1] = arr[i][j];
        }
    }
    return ret;
}

int func_b(vector<vector<int>> arr) {
    vector<int> ret(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            ret[i] += arr[i][j];
        }
        ret[i] = (int)(ret[i] / arr[i].size());
    }
    sort(ret.begin(), ret.end()); // sort defalut : 오름차순 -> 가장 높은 평가점수는 뒤에 위치함
    return ret[ret.size() - 1];
}

int solution(vector<vector<int>> scores) {
    vector<vector<int>> arr = func_a(scores);
    int answer = func_b(arr);
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<vector<int>> scores = { {85, 92, 95, 90}, {91, 76, 85, 50} };
    int ret = solution(scores);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;

}