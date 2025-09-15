#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;


        adj[a].push_back(b);
        adj[b].push_back(a);

    }


    int col[2] = {0,0};
    vector<int> color(n+1,0);
    vector<int> visited(n+1,0);

    bool isBipartite = true;


    function<void(int,int)> dfs = [&](int node,int c)->void{
        color[node] = c;
        col[c]++;
        visited[node] = 1;

        for(auto it : adj[node]){
            if(visited[it] == 0){
                dfs(it,c^1);
            }else if(color[it] == color[node]){
                isBipartite = false;
                return;

            }
        }
    };

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i,0);
        }
    }

    if(!isBipartite){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            color[i] = 2;
        }
        cout<<color[i]<<" ";
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
