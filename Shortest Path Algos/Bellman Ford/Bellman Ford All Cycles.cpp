#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

bool Bellman(int s, vector<int>& negativePath, vector<bool>& visited) {
    vector<int> d(n, INF);
    d[s] = 0;
    vector<int> p(n, -1);
    int x;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        return false; // No negative cycle
    } else {
        int y = x;
        for (int i = 0; i < n; ++i) {
            y = p[y];
        }

        negativePath.clear();
        for (int i = y;; i = p[i]) {
            negativePath.push_back(i);
            visited[i] = true;  // Mark the vertex as visited
            if (i == y && negativePath.size() > 1) {
                break;
            }
        }
        reverse(negativePath.begin(), negativePath.end());

        return true; // Negative cycle found
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.a >> e.b >> e.cost;
        edges.push_back(e);
    }

    int s;
    cin >> s;

    vector<int> negativePath;
    vector<bool> visited(n, false); // Initialize all vertices as not visited

    bool foundNegativeCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && Bellman(i, negativePath, visited)) {
            foundNegativeCycle = true;
            cout << "Negative cycle path: ";
            for (int j = 0; j < negativePath.size(); j++) {
                cout << negativePath[j] << ' ';
            }
            cout << endl;
        }
    }

    if (!foundNegativeCycle) {
        cout << "No negative cycle" << endl;
    }

    return 0;
}
