#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int maxNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++, value /= 10)
		numbers.push_back(value % 10);
	sort(numbers.begin(), numbers.end(), greater<int>()); // default = 오름차순 정렬
	int maxNum = 0;
	for (int i = 0; i < 4; i++)
		maxNum = maxNum * 10 + numbers[i];
	return maxNum;
}

int minNumber(int value) {
	vector<int> numbers;
	for (int i = 0; i < 4; i++, value /= 10)
		numbers.push_back(value % 10);
	sort(numbers.begin(), numbers.end());
	int minNum = 0;
	for (int i = 0; i < 4; i++)
		minNum = minNum * 10 + numbers[i];
	return minNum;
}

int solution(int num) {
  // 4자리 자연수를 조합해서 만든 가장 큰 수와 가장 작은 수의 차이 값을 구하려 함
	int answer;
	int maxiNum = maxNumber(num);
	int minNum = minNumber(num);
	answer = maxiNum - minNum;
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int num1 = 5924;
	int ret1 = solution(num1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int num2 = 3904;
	int ret2 = solution(num2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
	return 0;
}