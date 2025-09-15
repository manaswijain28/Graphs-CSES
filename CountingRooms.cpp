#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
void solve(){
 
 
    int n,m;
    cin>>n>>m;
 
    int ct = 0;
 
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
 
    vector<vector<char>> grid(n,vector<char> (m)); 
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
 
    vector<vector<int>> visited(n,vector<int> (m,0));
 
 
    function<void(int,int)> dfs = [&](int x,int y)->void{
        visited[x][y] = 1;
 
        for(int i=0;i<4;i++){
            int a = x+dx[i];
            int b = y+dy[i];
 
            if(a>=0 && b>=0 && a<n && b<m){
                if(visited[a][b] == 0 && grid[a][b] == '.'){
                    dfs(a,b);
                }
            }
        }
    };
 
 
 
 
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c = grid[i][j];
 
            if(visited[i][j] == 0 && c == '.'){
                ct++;
                dfs(i,j);
            }
        }
    }
 
    cout<<ct<<endl;
 
 
 
 
}
 
int main(){
    int t=1;
    // cin>>t;
    while(t--){
     solve();
 
 
 }
