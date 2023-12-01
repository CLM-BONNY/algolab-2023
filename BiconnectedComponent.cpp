#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int dfs(const vector<set<int>> &network, int curNode, set<int> &visitedNodes, int targetNode);
bool isArticulationPoint(const vector<set<int>> &network, int startNode, int targetNode, int n);
vector<int> getArticulationPoints(const vector<set<int>> &network, int n);
void dfsBCC(const vector<set<int>> &network, int curVertex, int parent, vector<int> &pathStack,
            vector<int> &mindict, vector<int> &dict, set<int> &visitedNodes, vector<set<int>> &components);
vector<set<int>> getBCCs(const vector<set<int>> &network, const vector<int> &points);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;

    vector<set<int>> network(n + 1);

    for (int j = 0; j < n; j++)
    {
      int curVertex, m;
      cin >> curVertex >> m;
      for (int k = 0; k < m; k++)
      {
        int adjacent;
        cin >> adjacent;
        network[curVertex].insert(adjacent);
      }
    }

    vector<int> points = getArticulationPoints(network, n);
    vector<set<int>> bccs = getBCCs(network, points);
    int bccCount = bccs.size() - 1;
    bccCount = max(bccCount, 1);

    cout << bccCount << endl;
    cout << points.size();

    for (int point : points)
    {
      cout << " " << point;
    }
    cout << endl;
  }

  return 0;
}

int dfs(const vector<set<int>> &network, int curNode, set<int> &visitedNodes, int targetNode)
{
  visitedNodes.insert(curNode);
  int count = 1;

  for (int vertex : network[curNode])
  {
    if (vertex != targetNode && visitedNodes.find(vertex) == visitedNodes.end())
    {
      count += dfs(network, vertex, visitedNodes, targetNode);
    }
  }

  return count;
}

bool isArticulationPoint(const vector<set<int>> &network, int startNode, int targetNode, int n)
{
  if (startNode == targetNode)
  {
    return false;
  }
  set<int> visitedNodes;
  return dfs(network, startNode, visitedNodes, targetNode) == n - 1;
}

vector<int> getArticulationPoints(const vector<set<int>> &network, int n)
{
  vector<int> points;
  for (int node = 1; node <= n; ++node)
  {
    if (!isArticulationPoint(network, node != 1 ? 1 : 2, node, n))
    {
      points.push_back(node);
    }
  }
  return points;
}

void dfsBCC(const vector<set<int>> &network, int curVertex, int parent, vector<int> &pathStack,
            vector<int> &mindict, vector<int> &dict, set<int> &visitedNodes, vector<set<int>> &components)
{
  int childCount = 0;
  dict[curVertex] = mindict[curVertex] = pathStack.size() + 1;
  visitedNodes.insert(curVertex);
  pathStack.push_back(curVertex);

  for (int adVertex : network[curVertex])
  {
    if (visitedNodes.find(adVertex) == visitedNodes.end())
    {
      childCount++;
      dfsBCC(network, adVertex, curVertex, pathStack, mindict, dict, visitedNodes, components);
      mindict[curVertex] = min(mindict[curVertex], mindict[adVertex]);

      if (mindict[adVertex] >= dict[curVertex])
      {
        set<int> component;
        while (pathStack.back() != adVertex)
        {
          component.insert(pathStack.back());
          pathStack.pop_back();
        }
        component.insert(pathStack.back());
        pathStack.pop_back();
        components.push_back(component);
      }
    }
    else if (adVertex != parent && dict[adVertex] < mindict[curVertex])
    {
      mindict[curVertex] = dict[adVertex];
    }
  }

  if (parent == -1 && childCount > 1)
  {
    set<int> component;
    while (!pathStack.empty())
    {
      component.insert(pathStack.back());
      pathStack.pop_back();
    }
    components.push_back(component);
  }
}

vector<set<int>> getBCCs(const vector<set<int>> &network, const vector<int> &points)
{
  vector<set<int>> components;
  set<int> visitedNodes;

  for (int point : points)
  {
    if (visitedNodes.find(point) == visitedNodes.end())
    {
      vector<int> pathStack, mindict(network.size()), dict(network.size());
      dfsBCC(network, point, -1, pathStack, mindict, dict, visitedNodes, components);
    }
  }

  return components;
}
