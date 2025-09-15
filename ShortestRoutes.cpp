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


    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> adj(n+1);

    for(ll i=1;i<=m;i++){
        ll x,y,w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
    }

    vector<ll> dist(n+1,LLONG_MAX);
    dist[1] = 0;

    dijkstra(n,adj,dist,1);
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";


    }
    cout<<endl;




    
    


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
