#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int>parent;
vector<long long>dis;
int flag=0;

void dijkstra(int source) {
    
    dis[source] = 0;
    using pii = pair<long long, long long>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    
    q.push({0, source});

    while (!q.empty()) {
        int node = q.top().second;
        int len = q.top().first;
        q.pop();
        
        for (auto edge : adj[node]) {
            int to = edge.first;
            int weight = edge.second;

            if (dis[node] + weight < dis[to]) {
                dis[to] = dis[node] + weight;
                parent[to] = node;
                q.push({dis[to], to});
            }
        }
    }
}


 
void printpath(int source, int end){

    if (source == end) {
        cout << source;
        return ;
    }
    if(parent[end]==-1){ flag = 1; cout<<-1; return;}
    printpath( source, parent[end]);
    if(flag!=1){cout << " " << end;}
    
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dis.assign(n+1, 1e11+9);
    parent.assign(n+1, -1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
        parent[y]=x;
    }

    dijkstra(1);
    int destination=n;

    printpath(1,destination);

    return 0;
}