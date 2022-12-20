#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int, int>
class Graph {
   private:
  vector<pair<int, edge> > m; 
  vector<pair<int, edge> > k;  
  int *parent;
  int n;  
   public:
  Graph(int n);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;
  m.clear();
  k.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  m.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}
void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(m.begin(), m.end());  
  for (i = 0; i < m.size(); i++) {
    uRep = find_set(m[i].second.first);
    vRep = find_set(m[i].second.second);
    if (uRep != vRep) {
      k.push_back(m[i]);  
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < k.size(); i++) {
    cout << k[i].second.first << " - " << k[i].second.second << " : " << k[i].first;
    cout << endl;
  }
}
int main()
{
     Graph m(6);
  m.AddWeightedEdge(0, 1, 4);
  m.AddWeightedEdge(0, 2, 4);
  m.AddWeightedEdge(1, 2, 2);
  m.AddWeightedEdge(1, 0, 4);
  m.AddWeightedEdge(2, 0, 4);
  m.AddWeightedEdge(2, 1, 2);
  m.AddWeightedEdge(2, 3, 3);
  m.AddWeightedEdge(2, 5, 2);
  m.AddWeightedEdge(2, 4, 4);
  m.AddWeightedEdge(3, 2, 3);
  m.AddWeightedEdge(3, 4, 3);
  m.AddWeightedEdge(4, 2, 4);
  m.AddWeightedEdge(4, 3, 3);
  m.AddWeightedEdge(5, 2, 2);
  m.AddWeightedEdge(5, 4, 3);
  m.kruskal();
  m.print();
return 0 ;
}