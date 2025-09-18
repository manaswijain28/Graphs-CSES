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

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }


    
    vector<bool> visited(n+1,false);
    vector<bool> inStack(n+1,false);
    vector<int> parent(n+1,-1);
    vector<int> cycle;


    function<bool(int)> checkCycle = [&](int node)->bool{
        visited[node] = true;
        inStack[node] = true;

        for(auto it : adj[node]){
            if(!visited[it]){
                parent[it] = node;
                if(checkCycle(it)){
                    return true;
                }
                
            }
            else if(inStack[it]){

                cycle.push_back(it);
                for(int x = node;x!=it;x=parent[x]){
                    cycle.push_back(x);
                }
                cycle.push_back(it); // close the cycle
                reverse(cycle.begin(), cycle.end());
                return true;
            }
        }

        inStack[node] = false;
        return false;
    };

    bool hai = false;

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            if(checkCycle(i)) {
                hai = true;
                break;
            }
        }
    }
    if(hai){
        cout<<cycle.size()<<endl;
        for(auto it : cycle){
            cout<<it<<" ";
        }
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }






}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
