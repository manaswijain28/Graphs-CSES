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


    queue<int> q;
    q.push(1);

    vector<int> visited(n+1,0);

    visited[1] = 1;

    vector<int> parent(n+1,-1);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(visited[it] == 0){
                visited[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }

    int node = n;

    if(parent[node] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans;


    while(node != 1){
        ans.push_back(node);
        node = parent[node];

    }

    ans.push_back(1);
    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }






}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
