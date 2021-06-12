#include <bits/stdc++.h>

using namespace std;
vector<long long> G[405];

vector<int> visited;

vector<int> dfs(int node) {
    visited.push_back(node);
    if (node == 400) {
        vector<int> p;
        p.push_back(400);
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
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i <=n ; i++){
        int num;
        cin >> num;
        if(num == 0){
            G[0].push_back(i);
        }
        else{
            G[i].push_back(400);
        }
    }
    for(int i = 0 ; i<m ;i++){
        int v1,v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    cout << maxFlow();
}
