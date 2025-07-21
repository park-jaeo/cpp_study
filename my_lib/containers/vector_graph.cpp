// vector_graph.cpp
#include <iostream>
#include <vector>
#include <queue> // BFS
#include "vector_graph.hpp"
using namespace std;

UndirectedGraph::UndirectedGraph(int vertices){
  numVertices = vertices; // 정점 숫자
  adjList.resize(vertices);
}

void UndirectedGraph::addEdge(int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

void UndirectedGraph::displayGraph(){
  for(int i = 0; i < numVertices; ++i){
    cout << "노드 :" << i << ": ";
    for(int neighbor : adjList[i]){
      cout << neighbor << " -> ";
    }
    cout << "NULL" << endl;
  }
}

vector<int> UndirectedGraph::getNeighbors(int vertex){
  return adjList[vertex];
}

bool UndirectedGraph::hasEdge(int u, int v){
  for(int neighbor : adjList[u]){
    if(neighbor == v) return true;
  }
  return false;
}

int UndirectedGraph::BFS(int startVertex){
  std::vector<bool> visited(numVertices, false); // 방문 배열 생성, false로 초기화
  std::queue<int> q; // 탐색할 정점 큐
  int count = 0; // startVertex에 연결된 모든 정점 검색

  visited[startVertex] = true;
  q.push(startVertex);

  while(!q.empty()){
    // 큐에서 정점 하나 꺼냄
    int u = q.front();
    q.pop();
    for(int v : adjList[u]){
      // 방문 처리 후 카운트
      if(!visited[v]){
        visited[v] = true;
        q.push(v);
        ++count;
      }
    }
  }
  return count;
}