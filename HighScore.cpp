#include <bits/stdc++.h>
using namespace std;
#define ll long long



// bfs using a priority queue



void dijkstra(ll n,vector<vector<pair<ll,ll>>> &adj,vector<ll> &dist,ll src){

    //min heap of pairs
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<>> pq;

    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        ll currDist = pq.top().first;
        ll u = pq.top().second;

        pq.pop();

        if(currDist > dist[u]){
            continue;
        }

        for(auto &it : adj[u]){
            ll v = it.first;
            ll wt = it.second;

            if(dist[v] > dist[u]+wt){
                dist[v] = dist[u]+wt;
                pq.push({dist[v],v});
            }
        }

    }

    //O((n+m)*logn)
}



void solve(){


    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    vector<vector<int>> adj(n+1); //reachable hai ya nahi

    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(b);

        w *= -1;

        edges.push_back({a,b,w});
    }

    vector<ll> dist(n+1,1e18);
    dist[1] = 0;

    for(int i=1;i<=(n-1);i++){
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e18 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }

    // nth relaxation to check negative cycle

    vector<int> affected;

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e18 && dist[u]+wt < dist[v]){
            affected.push_back(v);
        }

    }

    vector<int> vis(n+1,0);

    queue<int> q;

    for(int it : affected){
        if(vis[it] == 0){
            vis[it] = 1;
            q.push(it);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto it : adj[u]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    if(vis[n]){
        cout<<-1<<endl;
    }else if(dist[n] == 1e18){
        cout<<-1<<endl;
    }else{
        cout<<dist[n]*(-1)<<endl;
    }




    

    //t.c : v*e










    


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
     solve();


 }
}
