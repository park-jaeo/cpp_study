#ifndef ADJACENT_NODE_GRAPH_HPP
#define ADJACENT_NODE_GRAPH_HPP

#include <iostream>
#include <vector>

// 노드 클래스 정의
class Node{
public:
  int data;
  std::vector<Node*> neighbors; // 인접 노드 포인터 리스트 저장
  bool visited;
  Node(int value);
  void addNeighbor(Node* neighbor); // 이웃 노드 추가 기능
};

// 그래프 클래스 정의
class Graph{
private:
  std::vector<Node*> nodes;
public:
  void addNode(int data);  // 노드 추가
  void addEdge(int from, int to);  // 양방향 간선 추가
  int relateCount(int value); // 연관된 노드 수 리턴
  void printGraph();  // 그래프 출력
  ~Graph(); // 메모리 해제
};

#endif