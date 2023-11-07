#include<bits/stdc++.h>
#define INF           1000000000
using namespace std;
typedef pair< int,pair<int,int> > piii;
typedef vector< piii > viii;
bool visited[1010];
int dist[1010];
queue<int> cycle;
vector<int> node;
int n,e;
bool bellmanford(viii& edge)
{
    memset(dist,INF,sizeof dist);
    dist[n] = 0;
    int u, v, cost;

    bool update = true;
    for(int i=1; i<=n && update; i++)
    {
        update = false;
        for(int j=0; j<=e; j++)
        {
            u = edge[j].first; v = edge[j].second.first; cost = edge[j].second.second;
            if(dist[v]>dist[u]+cost)
            {
                dist[v] = dist[u] + cost;
                update = true;
            }
        }
    }
    for(int j=0; j<=e; j++)
    {
        u = edge[j].first; v = edge[j].second.first; cost = edge[j].second.second;
        if(dist[v]>dist[u]+cost)
        {
            dist[v] = dist[u] + cost;
            cycle.push(v);
            cycle.push(u);
        }
    }
}
void bfs(vector<int>adj[])
{
    memset(visited,false,sizeof visited);
    while(!cycle.empty())
    {
        int u=cycle.front();
        cycle.pop();
        if(!visited[u])
            node.push_back(u);
        visited[u]=true;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
                cycle.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        int u,v,w;
        viii edge;
        vector<int>adj[n+1];
        for(int i=0; i<e; i++)
        {
            cin>>u>>v>>w;
            edge.push_back(make_pair(v, make_pair(u,w)));
            adj[v].push_back(u);
        }
        for(int i=0; i<n; i++)
        {
            edge.push_back(make_pair(n, make_pair(i,0)));
            adj[n].push_back(i);
        }
        bellmanford(edge);
        bfs(adj);
        sort(node.begin(),node.end());

        cout<<"Case "<<test<<":";
        if(node.empty())
            cout<<" impossible\n";
        else
        {
            for(int i=0; i<node.size(); i++)
                cout<<' '<<node[i];
            cout<<endl;
        }
        node.clear();
        test++;
    }
}