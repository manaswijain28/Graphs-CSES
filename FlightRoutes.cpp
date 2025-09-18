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

    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,ll>>> adj(n+1);

    for(int i=1;i<=m;i++){
        int u,v;
        ll wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});

    }

    vector<vector<ll>> dist(n+1);

    priority_queue<pair<ll,int>,vector<pair<ll,int>> ,greater<>> pq;


    pq.push({0,1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int u = it.second;

        if(dist[u].size()>=k){
            continue;

        }

        dist[u].push_back(d);

        for(auto i : adj[u]){
            int v = i.first;
            ll wt = i.second;

            pq.push({d+wt,v});
        }
    }

    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
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
