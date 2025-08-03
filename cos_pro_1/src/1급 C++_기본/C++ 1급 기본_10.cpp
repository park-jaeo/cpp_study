#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> household) {
	vector<int> answer = {0};
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
int main() {
	vector<vector<int>> household = { {1, 1, 2, 60}, {2, 1, 2, 85},	{3, 0, 0, 70}, {4, 0, 0, 70}, {5, 1, 3 , 90} };
	vector<int> ret = solution(household);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << ret[0] << ", " \
		<< ret[1] << ", " << ret[2] << ", " << ret[3] \
		<< ", " << ret[4] << "}입니다." << endl;
	return 0;
}
