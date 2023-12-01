#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>>& connectedNodes, vector<bool>& visited, deque<int>& queue, vector<int>& groupSize, int& groupidx);

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        int n;
        cin >> n;

        vector<vector<int>> connectedNodes(n);
        vector<bool> visited(n, false);

        for (int j = 0; j < n; j++) {
            int nodeNumber;
            cin >> nodeNumber;
            
            int connectedNodeNum;
            cin >> connectedNodeNum;
            connectedNodes[j].resize(connectedNodeNum);

            for (int k = 0; k < connectedNodeNum; k++) {
                cin >> connectedNodes[j][k];
            }
        }

        deque<int> queue;
        int groupidx = -1;
        vector<int> groupSize;

        bfs(connectedNodes, visited, queue, groupSize, groupidx);

        cout << groupSize.size() << ' ';
        for (int size : groupSize) {
            cout << size << ' ';
        }
        cout << endl;
    }

    return 0;
}

void bfs(vector<vector<int>>& connectedNodes, vector<bool>& visited, deque<int>& queue, vector<int>& groupSize, int& groupidx) {
  while (find(visited.begin(), visited.end(), false) != visited.end()) {
    for (int i = 0; i < connectedNodes.size(); i++) {
      if (!visited[i]) {
        queue.push_back(i);
        visited[i] = true;
        break;
      }
    }

    groupidx += 1;
    groupSize.push_back(0);

    while (!queue.empty()) {
      int nodeNumber = queue.front();
      queue.pop_front();

      groupSize[groupidx] += 1;

      for (int node : connectedNodes[nodeNumber]) {
        if (!visited[node - 1]) {
          queue.push_back(node - 1);
          visited[node - 1] = true;
        }
      }
    }
  }

  sort(groupSize.begin(), groupSize.end());
}
