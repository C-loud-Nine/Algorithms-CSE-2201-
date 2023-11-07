#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
    int u, v, w;
};

vector<edge>g;
int n;
int par[110];
vector<int>v[105];
int cnt;
bool vis[105];
bool comp(edge a, edge b){
    return a.w<b.w;
}

int find(int u){
    if(u==par[u]) return u;
    return par[u] = find(par[u]);
}

ll mst(){
    ll cost = 0;
    sort(g.begin(),g.end(),comp);


    for(int i = 0; i<g.size(); ++i){
        int p = find(g[i].u);
        int q = find(g[i].v);
        if(p!=q){
            cost+=g[i].w;
            par[q] = p;
        }
    }
    return cost;
}

void clear(){
   // g.clear();
    for(int i = 0; i<104; ++i){
       // vis[i] = 0;
        par[i] = i;
    }
    //vis.clear();
    //cnt = 0;
}

int main(){
        clear();
        g.push_back({0,1,2});
        g.push_back({0,3,6});
        g.push_back({1,0,2});
        g.push_back({0,1,2});
        g.push_back({1,2,3});
        g.push_back({1,4,5});
        g.push_back({2,1,3});
        g.push_back({2,4,7});
        g.push_back({3,0,6});
        g.push_back({3,1,8});
        g.push_back({4,1,5});
        g.push_back({4,2,7});
        g.push_back({1,3,8});
        cout << mst() << endl;
}