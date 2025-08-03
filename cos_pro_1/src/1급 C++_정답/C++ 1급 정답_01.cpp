#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> func_a(vector<vector<int>> arr) {
    vector<vector<int>> ret(arr.size(), vector<int> (arr[1].size()-2, 0));
    for (int i = 0; i < arr.size(); i++) {
        sort(arr[i].begin(), arr[i].end());
        for (int j = 1; j < arr[i].size() - 1; j++) {
            ret[i][j-1] = arr[i][j];
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
    sort(ret.begin(), ret.end());
    return ret[ret.size() - 1];
}

int solution(vector<vector<int>> scores) {
    vector<vector<int>> arr = func_a(scores);
    int answer = func_b(arr);
    return answer;
}