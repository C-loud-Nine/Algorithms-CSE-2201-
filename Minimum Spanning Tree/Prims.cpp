#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[10000];
int n, m, pre = -1;

int prim(int src) {
    vector<bool> vis(n + 1, false);
    vector<int> par(n + 1, -1);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    int cnt = 0, ans = 0;

    while (cnt != n) {
        int node = pq.top().second, w = pq.top().first;
        pq.pop();

        if (!vis[node]) {
            cnt++;
            ans += w;
            vis[node] = true;
            
            // Skip printing the parent of the source node
            if (node != src) {
                cout << par[node] << ' ' << node << ' ' << w << endl;
            }

            for (auto nei : adj[node]) {
                if (!vis[nei.second]) {
                    par[nei.second] = node;
                    pq.push(nei);
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cout << prim(1) << endl;

    return 0;
}
