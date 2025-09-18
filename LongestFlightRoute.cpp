 #include <bits/stdc++.h>
using namespace std;
#define ll long long



// // bfs using a priority queue



// void dijkstra(ll n,vector<vector<pair<ll,ll>>> &adj,vector<ll> &dist,ll src){

//     //min heap of pairs
//     priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<>> pq;

//     dist[src] = 0;
//     pq.push({0,src});
//     while(!pq.empty()){
//         ll currDist = pq.top().first;
//         ll u = pq.top().second;

//         pq.pop();

//         if(currDist > dist[u]){
//             continue;
//         }

//         for(auto &it : adj[u]){
//             ll v = it.first;
//             ll wt = it.second;

//             if(dist[v] > dist[u]+wt){
//                 dist[v] = dist[u]+wt;
//                 pq.push({dist[v],v});
//             }
//         }

//     }

//     //O((n+m)*logn)
// }


void solve(){


    int n,m;
    cin>>n>>m;


    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for(auto it : adj[u]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }

        }
    }


    vector<int> dist(n+1,-1e9);
    vector<int> parent(n+1,-1);

    dist[1] = 0;

    for(auto u : topo){
        for(auto v : adj[u]){
            if(dist[v] < dist[u]+1){
                dist[v] = dist[u]+1;
                parent[v] = u; 
            }
        }
    }

    if(dist[n]<0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> path;

        int curr = n;
        while(curr != -1){
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(),path.end());

        cout<<path.size()<<endl;
        for(auto i : path){
            cout<<i<<" ";
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
