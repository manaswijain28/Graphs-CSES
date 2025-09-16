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


    ll n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> matrix(n,vector<ll> (n,1e18));

    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;

        --a;
        --b;

        matrix[a][b] = min(matrix[a][b],w);
        matrix[b][a] = min(matrix[b][a],w);

    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                matrix[i][j] = 0;
            }
        }
    }


    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1e18){
                matrix[i][j] = -1;
            }
        }
    }

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        --x;
        --y;

        cout<<matrix[x][y]<<endl;
    }






    


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
