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
    vector<vector<pair<ll,ll>>> adj2(n+1);


    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj2[b].push_back({a,w});

    }

    vector<ll> dist1(n+1,1e18);
    vector<ll> dist2(n+1,1e18);


    dijkstra(n,adj,dist1,1);
    dijkstra(n,adj2,dist2,n);


    vector<int> visited(n+1,0);

    ll mn = LLONG_MAX;

    for(int i=1;i<n;i++){
        for(auto it : adj[i]){
            ll u = i;
            ll v = it.first;
            ll wt = it.second;

            ll ans = dist1[u]+dist2[v]+wt/2;

            mn = min(mn,ans);




        }
    }


    cout<<mn<<endl;
    

    


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
     solve();


 }
}
