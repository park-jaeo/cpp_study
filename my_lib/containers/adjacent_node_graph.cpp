/*
노드
  이웃 노드 추가

그래프
  양방향 간선
  그래프 출력
  메모리 해제
*/
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
  int data;
  vector<Node*> neighbors;
  bool visited;

  Node(int value) : data(value), visited(false) {}

  void addNeighbor(Node* neighbor){
    neighbors.push_back(neighbor);
  }
};

class Graph{
private:
  vector<Node*> nodes;

public:
  // 노드 추가
  void addNode(int data){
    nodes.push_back(new Node(data));
  }

  // 양방향 간선 추가
  void addEdge(int from, int to){
    Node* fromNode = nullptr;
    Node* toNode = nullptr;

    // 노드 찾기
    for(Node* node : nodes){
      if(node->data == from) { fromNode = node; }
      if(node->data == to  ) { toNode = node; }
    }

    // 양방향 연결
    if(fromNode && toNode){
      fromNode->addNeighbor(toNode); // 인접 노드 저장 메소드 호출
      toNode->addNeighbor(fromNode);
    }
  }

  // 그래프 출력
  void printGraph(){
    for(Node* node : nodes){
      cout << node->data << ": ";
      for(Node* neighbor : node->neighbors){
        cout << neighbor->data << " ";
      }
      cout << endl;
    }
  }

  // 연관된 노드 수 리턴
  int relateCount(int value){
    // Range-based for문으로 모든 노드 순회
    for(const auto& node : nodes){
      std::cout << "Node " << node->data << " neighbors: ";

      //
    }
  }

  // 메모리 해제
  ~Graph(){
    for(Node* node : nodes){
      delete node;
    }
  }
};