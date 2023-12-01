#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dfs(int nodeNumber, const vector<vector<int>> &connectedNodes, vector<bool> &visited);
vector<int> getGroupSizes(const vector<vector<int>> &connectedNodes, vector<bool> &visited, int n);

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

        vector<int> groupSizes = getGroupSizes(connectedNodes, visited, n);

        cout << groupSizes.size() << ' ';
        for (int size : groupSizes)
        {
            cout << size << ' ';
        }

        cout << endl;
    }

    return 0;
}

int dfs(int nodeNumber, const vector<vector<int>> &connectedNodes, vector<bool> &visited)
{
    stack<int> s;
    int groupSize = 0;

    s.push(nodeNumber);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (visited[node - 1])
        {
            continue;
        }

        groupSize++;
        visited[node - 1] = true;

        for (int connectedNode : connectedNodes[node - 1])
        {
            s.push(connectedNode);
        }
    }

    return groupSize;
}

vector<int> getGroupSizes(const vector<vector<int>> &connectedNodes, vector<bool> &visited, int n)
{
    vector<int> groupSizes;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int groupSize = dfs(i + 1, connectedNodes, visited);
            groupSizes.push_back(groupSize);
        }
    }

    sort(groupSizes.begin(), groupSizes.end());

    return groupSizes;
}
