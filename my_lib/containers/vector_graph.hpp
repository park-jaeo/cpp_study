// vector_graph.hpp
#ifndef VECTOR_GRAPH_HPP
#define VECTOR_GRAPH_HPP

#include <vector>

// 벡터 인접 리스트 그래프 구현
class UndirectedGraph{
private:
  int numVertices;
  std::vector<std::vector<int>> adjList; // 현재 정점 - 연결된 정점 벡터
public:
  UndirectedGraph(int vertices);
  void addEdge(int u, int v); // 간선 추가
  void displayGraph();  // 그래프 출력
  std::vector<int> getNeighbors(int vertex); // 특정 노드의 인접 노드 반환
  bool hasEdge(int u, int v); // 간선 존재여부 확인

  // BFS
  int BFS(int startVertex);
};

#endif