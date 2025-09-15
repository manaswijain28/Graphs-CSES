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


    vector<vector<int>> components;

    vector<int> visited(n+1,0);


    function<void(int)> func = [&](int src)->void{
        vector<int> compo;

        function<void(int)> dfs = [&](int node)->void{
            compo.push_back(node);
            visited[node] = 1;

            for(auto it : adj[node]){
                if(visited[it] == 0){
                    dfs(it);
                }

            }

        };

        dfs(src);
        if(compo.size()){
            components.push_back(compo);
        }

    };

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            func(i);
        }
    }

    if(components.size() == 0){
        cout<<0<<endl;
        return;
    }

    cout<<components.size()-1<<endl;
    for(int i=1;i<components.size();i++){
        cout<<components[i][0]<<" "<<components[i-1][0]<<endl;
    }











}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
