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
    vector<vector<ll>> edges;
    for(int i=1;i<=m;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;

        adj[x].push_back({y,wt});
        edges.push_back({x,y,wt});

    }

    vector<ll> dist(n+1,0);
    vector<ll> parent(n+1,0);

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    for(int i=1;i<=(n-1);i++){
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
                parent[v] = u;
            }
        }
    }

    int need = -1;


    for(auto it : edges){
        ll u = it[0];
        ll v = it[1];
        ll wt = it[2];

        if(dist[u]+wt < dist[v]){
            need = v;
            break;
        }

    }

    if(need == -1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for (int i = 0; i < n; i++) {
            need = parent[need];
        }


        if(need == parent[need]){
            cout<<need<<" "<<need<<endl;
            return;
        }

        vector<int> cycle;

        int curr = need;
        while (true) {
            cycle.push_back(curr);
            curr = parent[curr];
            if (curr == need && cycle.size() > 1) break;
        }


        cycle.push_back(need);

        reverse(cycle.begin(),cycle.end());
        for(auto it : cycle){
            cout<<it<<" ";
        }
        cout<<endl;
    }





}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
     solve();


 }
}
