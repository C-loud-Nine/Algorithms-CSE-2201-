#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 15;
const int INF = 1000000000;

int w[MAX_N][MAX_N];
int n;
int mem[MAX_N][1 << MAX_N];

int tsp(int i, int mask) {
    if (mask == (1 << n) - 1) {
        if (w[i][0] != INF) {
            return w[i][0]; // Return to the starting vertex to complete the cycle.
        }
        return INF; // No solution, as it's not possible to return to the starting vertex.
    }

    if (mem[i][mask] != -1) {
        return mem[i][mask];
    }

    int ans = INF;
    for (int j = 0; j < n; j++) {
        if (w[i][j] != INF && !(mask & (1 << j))) {
            int result = tsp(j, mask | (1 << j)) + w[i][j];
            ans = min(ans, result);
        }
    }

    return mem[i][mask] = ans;
}

int main() {
    int m;
    cin >> n >> m;

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            w[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        w[u][v] = cost;
    }

    // Initialize the memoization table
    memset(mem, -1, sizeof(mem));

    int minCost = tsp(0, 1); // Start from vertex 0 and mark it as visited in the mask.

    if (minCost == INF) {
        cout << -1 << endl; // No solution.
    } else {
        cout << minCost << endl;
    }

    return 0;
}
