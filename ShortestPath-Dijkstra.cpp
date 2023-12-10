#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge;
void readGraph(vector<vector<Edge>> &graph);
void dijkstra(const vector<vector<Edge>> &graph, vector<int> &dist, vector<int> &parent);
int calculateResult(const vector<vector<Edge>> &graph, const vector<int> &parent);

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int n;
        cin >> n;

        vector<vector<Edge>> graph(n + 1);

        for (int j = 1; j <= n; j++)
        {
            int u, m;
            cin >> u >> m;
            while (m--)
            {
                int v, w;
                cin >> v >> w;
                graph[u].emplace_back(v, w);
            }
        }

        vector<int> dist(graph.size(), INT_MAX), parent(graph.size(), -1);
        dijkstra(graph, dist, parent);

        int res = calculateResult(graph, parent);

        cout << res << endl;
    }

    return 0;
}

struct Edge
{
  int v, w;
  Edge(int _v, int _w) : v(_v), w(_w) {}
};

void dijkstra(const vector<vector<Edge>> &graph, vector<int> &dist, vector<int> &parent)
{
  int n = graph.size() - 1;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    for (const auto &edge : graph[u])
    {
      int v = edge.v, w = edge.w;
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }
}

int calculateResult(const vector<vector<Edge>> &graph, const vector<int> &parent)
{
  int res = 0;
  int n = graph.size() - 1;

  for (int i = 2; i <= n; i++)
  {
    for (const auto &edge : graph[parent[i]])
    {
      if (edge.v == i)
      {
        res += edge.w;
        break;
      }
    }
  }

  return res;
}
