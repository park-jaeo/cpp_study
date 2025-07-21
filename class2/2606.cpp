// 2606.cpp
#include <iostream>
#include <vector>
#include "../my_lib/containers/vector_graph.hpp"
// #include "vector_graph.hpp"
using namespace std;

/*
N : 컴퓨터 수
M : 엣지 수
*/

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  UndirectedGraph graph(N + 1); // 1 index
  vector<bool> visited(N + 1); // 방문배열, 1 index

  // 엣지 추가
  for(int i = 0; i < M; ++i){
    int from, to;
    cin >> from >> to;
    graph.addEdge(from, to); // 1 index
  }

  cout << graph.BFS(1) << '\n';

  return 0;
}


