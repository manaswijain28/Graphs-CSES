#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n,m;
    cin>>n>>m;
 
    pair<int,int> a;
    pair<int,int> b;
 
    vector<vector<char>> adj(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j] == 'A'){
                a = {i,j};
            }else if(adj[i][j] == 'B'){
                b = {i,j};
            }
        }
    }
 
    int time = 0;
    queue<pair<int,int>> q;
    q.push(a);
    vector<vector<int>> visited(n,vector<int> (m,0));
    visited[a.first][a.second] = 1;
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
 
 
 
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
 
    bool hai = false;
    
 
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
 
        for(int i=0;i<4;i++){
            int x = dx[i]+p.first;
            int y = dy[i]+p.second;
 
            if(x>=0 && y>=0 && x<n && y<m){
                if((adj[x][y] == '.') && (visited[x][y] == 0)){
                    parent[x][y] = p;
                    visited[x][y] = 1;
                    q.push({x,y});
                }else if(adj[x][y] == 'B' && (visited[x][y] == 0)){
                    parent[x][y] = p;
                    visited[x][y] = 1;
                    q.push({x,y});
                    cout<<"YES"<<endl;
                    hai = true;
                    break;
                }
            }
        }
 
        if(hai){
            break;
        }
    }
 
    if(!hai){
        cout<<"NO"<<endl;
        return 0;
    }
 
    vector<char> traversal;
    pair<int,int> curr = b;
    while(curr != a){
        pair<int,int> par = parent[curr.first][curr.second];
 
        pair<int,int> diff = {curr.first - par.first, curr.second - par.second};
 
        if(diff == make_pair(1,0)) traversal.push_back('D');
        else if(diff == make_pair(-1,0)) traversal.push_back('U');
        else if(diff == make_pair(0,1)) traversal.push_back('R');
        else if(diff == make_pair(0,-1)) traversal.push_back('L');
 
        curr = par;
    }
 
    cout<<traversal.size()<<endl;
    reverse(traversal.begin(),traversal.end());
    for(auto &it: traversal){
        cout<<it;
    }
 
 
    
 
 
 
 
 
 
    return 0;
}
