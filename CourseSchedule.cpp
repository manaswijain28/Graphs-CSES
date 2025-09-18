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

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }


    vector<int> topo_sort;
    vector<int> indegree(n+1);

    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }


    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    if(q.size() == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        topo_sort.push_back(u);

        for(auto it : adj[u]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(topo_sort.size() != n) {
        cout << "IMPOSSIBLE"<<endl;
    } else {
        for(auto it : topo_sort) cout << it << " ";
            cout << endl;
    }    



}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
     solve();


 }
}
