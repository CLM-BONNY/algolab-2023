#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge;
int prim(int start, vector<vector<Edge>> &graph);

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int n;
        cin >> n;

        vector<vector<Edge>> graph(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int node, m;
            cin >> node >> m;

            for (int j = 0; j < m; j++)
            {
                int neighbor, weight;
                cin >> neighbor >> weight;

                graph[node].emplace_back(neighbor, weight);
            }
        }

        cout << prim(1, graph) << "\n";
    }

    return 0;
}

struct Edge
{
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

int prim(int start, vector<vector<Edge>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(graph.size(), false);

    int totalWeight = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        totalWeight += weight;

        for (const Edge &edge : graph[node])
        {
            int neighbor = edge.to;
            int edgeWeight = edge.weight;
            if (!visited[neighbor])
            {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    return totalWeight;
}
