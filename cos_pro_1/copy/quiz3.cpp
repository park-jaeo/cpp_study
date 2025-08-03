#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
	if (a[1] != b[1]) return (a[1] > b[1]) ; // 요소1 : 내림차순 정렬함수 적용
	if (a[2] != b[2]) return (a[2] > b[2]) ; // 요소2 : 내림차순 정렬함수 적용
	return (a[3] > b[3]); // 요소3 : 내림차순 정렬함수 적용
}


vector<int> solution(vector<vector<int>> projects) {
	sort(projects.begin(), projects.end(), compare);

	vector<int> answer;
	for (int i = 0; i < projects.size(); i++)
		answer.push_back(projects[i][0]);
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
  // 1. 모둠 발표 순서를 정한다.
  // 비교 순서 : 프로젝트 설계 점수 -> 프로젝트 구현 점수 -> 모둠 번호

	vector<vector<int>> projects = { {5, 90, 90}, {1, 90, 70}, {3, 95, 70}, {2, 85, 85}, {4, 70, 90}};
	vector<int> ret = solution(projects);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {" << ret[0] << "," \
		<< ret[1] << "," << ret[2] << "," << ret[3] \
		<< "," << ret[4] << "}입니다." << endl;
	return 0;
}