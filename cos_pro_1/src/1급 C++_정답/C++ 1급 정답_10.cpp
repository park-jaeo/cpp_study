#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
	if (a[1] != b[1]) return b[1] < a[1];
	if (a[2] != b[2]) return b[2] < a[2];
	if (a[3] != b[3]) return b[3] < a[3];
	return a[0] < b[0];
}

vector<int> solution(vector<vector<int>> household) {
	sort(household.begin(), household.end(), compare);

	vector<int> answer;
	for (int i = 0; i < household.size(); i++)
		answer.push_back(household[i][0]);
	return answer;
}