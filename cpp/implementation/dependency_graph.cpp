#include <bits/stdc++.h>
using namespace std;

int min_changes(vector<int>& arr) {
    map<int, int> first_occ, last_occ, freq;

    for (int i = 0; i < (int)arr.size(); i++) {
        int v = arr[i];
        if (!first_occ.count(v)) first_occ[v] = i;
        last_occ[v] = i;
        freq[v]++;
    }

    vector<int> values;
    for (auto& [v, _] : first_occ) values.push_back(v);
    int k = values.size();

    // Grafo de conflictos
    vector<vector<int>> adj(k);
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int a = values[i], b = values[j];
            bool conflict = first_occ[a] < last_occ[b] && first_occ[b] < last_occ[a];
            if (conflict) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // BFS por componentes conexas
    vector<bool> visited(k, false);
    int total_cost = 0;

    for (int start = 0; start < k; start++) {
        if (visited[start]) continue;

        vector<int> component;
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            component.push_back(node);
            for (int nb : adj[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }

        int total = 0, best = 0;
        for (int idx : component) {
            total += freq[values[idx]];
            best = max(best, freq[values[idx]]);
        }
        total_cost += total - best;
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    cout << min_changes(arr) << "\n";
    return 0;
}