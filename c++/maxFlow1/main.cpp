#include <bits/stdc++.h>

using namespace std;
vector<long long> G[205];

vector<int> visited;

vector<int> dfs(int node) {
    visited.push_back(node);
    if (node == 201) {
        vector<int> p;
        p.push_back(201);
        return p;
    } else
        for (int neighbor : G[node]) {
            bool isContained = false;
            for (int elem : visited)
                if (elem == neighbor)
                    isContained = true;
            if (!isContained) {
                vector<int> neighborPath = dfs(neighbor);
                if (!neighborPath.empty()) {
                    neighborPath.insert(neighborPath.begin(), node);
                    return neighborPath;
                }
            }
        }
    return vector<int>();
}

int maxFlow() {
    visited.clear();
    vector<int> path = dfs(0);
    if (path.empty())
        return 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int a = path[i];
        int b = path[i + 1];
        for (auto iter = G[a].begin(); iter != G[a].end(); iter++) {
            if (*iter == b) {
                G[a].erase(iter);
                break;
            }
        }
        G[b].push_back(a);
    }
    return maxFlow() + 1;
}

int main() {
    int n;
    cin >> n;
    long long matrix[n][n];
    set<long long> m;
    vector<long long> numbers;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            m.insert(matrix[i][j]);
        }

    for (long long num : m)
        numbers.push_back(num);

    sort(numbers.begin(), numbers.end());

    for (long long num : numbers) {
        visited.clear();
        G[0].clear();
        G[201].clear();
        for (int i = 1; i <= n; i++)
            G[0].push_back(i);
        for (int i = 1; i <= 2 * n; i++)
            G[i].clear();
        for (int i = n + 1; i <= 2 * n; i++)
            G[i].push_back(201);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j] <= num)
                    G[i + 1].push_back(n + j + 1);
        }
        if(maxFlow() == n){
            cout << num;
            break;
        }
    }
    return 0;

}
