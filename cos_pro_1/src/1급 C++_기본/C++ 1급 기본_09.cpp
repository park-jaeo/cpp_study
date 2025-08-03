#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> info, vector<vector<int>> game) {
	int result = 0;
	return result;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int N = 5;
	vector<vector<int>> info = { { 1 }, { 4 } };
	vector<vector<int>> game = { { 1,2 }, {3}, { 3, 4 } };

	int ret = solution(N, info, game);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
    
    
    int N2 = 7;
	vector<vector<int>> info2 = { { 3 }, { 1, 2, 3 }};
	vector<vector<int>> game2 = { {1}, {2}, {3}, {4}, {5}, {6}, {4, 5}, {3, 6} };

	int ret2 = solution(N2, info2, game2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
    
    
	return 0;
}
