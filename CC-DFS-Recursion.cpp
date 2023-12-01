#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recursionDFS(int node, vector<vector<int>> &connectedNodes, vector<bool> &visited, vector<int> &groupSize);
void getGroupSizes(vector<vector<int>> &connectedNodes, vector<bool> &visited, vector<int> &groupSize, int n);

int main()
{
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; ++i)
  {
    int n;
    cin >> n;

    vector<vector<int>> connectedNodes(n);
    vector<bool> visited(n, false);

    for (int j = 0; j < n; j++)
    {
      int nodeNumber;
      cin >> nodeNumber;

      int connectedNodeNum;
      cin >> connectedNodeNum;
      connectedNodes[j].resize(connectedNodeNum);

      for (int k = 0; k < connectedNodeNum; k++)
      {
        cin >> connectedNodes[j][k];
      }
    }

    vector<int> groupSize;
    getGroupSizes(connectedNodes, visited, groupSize, n);

    sort(groupSize.begin(), groupSize.end()); // 추가된 코드

    cout << groupSize.size() << ' ';
    for (int size : groupSize)
    {
      cout << size << ' ';
    }
    cout << endl;
  }

  return 0;
}

void recursionDFS(int node, vector<vector<int>> &connectedNodes, vector<bool> &visited, vector<int> &groupSize)
{
  visited[node - 1] = true;
  groupSize.back() += 1;
  for (int neighbor : connectedNodes[node - 1])
  {
    if (!visited[neighbor - 1])
    {
      recursionDFS(neighbor, connectedNodes, visited, groupSize);
    }
  }
}

void getGroupSizes(vector<vector<int>> &connectedNodes, vector<bool> &visited, vector<int> &groupSize, int n)
{
  while (find(visited.begin(), visited.end(), false) != visited.end())
  {
    for (int i = 1; i <= n; ++i)
    {
      if (!visited[i - 1])
      {
        groupSize.push_back(0);
        recursionDFS(i, connectedNodes, visited, groupSize);
        break;
      }
    }
  }
}
