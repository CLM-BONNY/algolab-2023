#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge;
bool compare(const Edge &a, const Edge &b);
int findParent(int node, vector<int> &parent);
void unionParent(int node1, int node2, vector<int> &parent);
int kruskalAlgorithm(vector<Edge> &edges, int n);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++)
  {
    int n;
    cin >> n;

    vector<Edge> edges;
    for (int i = 1; i <= n; i++)
    {
      int node, m;
      cin >> node >> m;

      for (int j = 0; j < m; j++)
      {
        int neighbor, weight;
        cin >> neighbor >> weight;

        edges.emplace_back(node, neighbor, weight);
      }
    }

    int totalWeight = kruskalAlgorithm(edges, n);
    cout << totalWeight << endl;
  }

  return 0;
}

struct Edge
{
  int node1, node2, weight;
  Edge(int _node1, int _node2, int _weight) : node1(_node1), node2(_node2), weight(_weight) {}
};

bool compare(const Edge &a, const Edge &b)
{
  return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent)
{
  if (parent[node] == node)
  {
    return node;
  }
  else
  {
    return parent[node] = findParent(parent[node], parent);
  }
}

void unionParent(int node1, int node2, vector<int> &parent)
{
  node1 = findParent(node1, parent);
  node2 = findParent(node2, parent);

  if (node1 < node2)
  {
    parent[node2] = node1;
  }
  else
  {
    parent[node1] = node2;
  }
}

int kruskalAlgorithm(vector<Edge> &edges, int n)
{
  sort(edges.begin(), edges.end(), compare);
  int totalWeight = 0;
  vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }
  for (const Edge &edge : edges)
  {
    if (findParent(edge.node1, parent) != findParent(edge.node2, parent))
    {
      totalWeight += edge.weight;
      unionParent(edge.node1, edge.node2, parent);
    }
  }
  return totalWeight;
}
