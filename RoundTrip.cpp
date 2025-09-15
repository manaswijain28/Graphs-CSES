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


    bool hai = false;

    vector<int> visited(n+1,0);
    vector<int> ans;

    vector<int> parent(n+1,0);


    function<bool(int)> dfs = [&](int node)->bool{
        visited[node] = 1;

        for(auto it : adj[node]){
            if(visited[it] == 0){
                ans.push_back(it);
                // cout<<it<<endl;
                parent[it] = node;
                if(dfs(it) == true){
                    return true;
                }
                ans.pop_back();
            }

            else if(visited[it] && it != parent[node]){


                ans.push_back(it);
                hai = true;
                return true;

            }
        }

        return false;


        
    };

    for(int i=1;i<=n;i++){

        if(visited[i] == 0 && !hai){
            ans.push_back(i);
            // cout<<i<<endl;
            dfs(i);
        }
    }


    if(!hai){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> fin;
    int num = ans[ans.size()-1];
    fin.push_back(num);
    for(int i=ans.size()-2;i>=0;i--){
        if(ans[i] == num){
            fin.push_back(num);
            break;
        }else{
            fin.push_back(ans[i]);
        }
    }

    cout<<fin.size()<<endl;
    for(int i=0;i<fin.size();i++){
        cout<<fin[i]<<" ";
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
