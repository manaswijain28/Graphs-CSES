#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){


    int n,m;
    cin>>n>>m;

    vector<vector<char>> grid(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }


    queue<vector<int>> q;
    int c1,c2,x,y;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'M'){
                q.push({i,j,0});
            }

            if(grid[i][j] == 'A'){
                c1 = i;
                c2 = j;
            }
        }
    }


    x = c1;
    y = c2;


    int dist_mon[n+1][m+1];
    int dist_me[n+1][m+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist_mon[i][j] = -1;
            dist_me[i][j] = -1;
        }
    }

    int dx[4] = { 0, 0, -1, 1 }; 
    int dy[4] = { -1, 1, 0, 0 };


    while(!q.empty()){
        auto curr = q.front();

        q.pop();

        int p1 = curr[0];
        int p2 = curr[1];
        int steps = curr[2];


        if (dist_mon[p1][p2] != -1) continue;
        dist_mon[p1][p2] = steps;


        for(int i=0;i<4;i++){
            int cx = p1+dx[i];
            int cy = p2+dy[i];

            if(cx>=0 && cy>=0 && cx<n && cy<m){
                if(grid[cx][cy] != '#' && dist_mon[cx][cy] == -1){
                    q.push({cx,cy,steps+1});
                }
            }
        }
    }


    while(!q.empty()){
        q.pop();
    }


    q.push({x,y,0,0});


    bool done = false;


    int direction[n+1][m+1];
    memset(direction, 0, sizeof(direction));


    string ans = "";

    while(!q.empty()){

        auto curr = q.front();
        q.pop();

        int p1 = curr[0];
        int p2 = curr[1];

        int steps = curr[2];
        int dir = curr[3];

        if(p1 == (n-1) || p2 == (m-1) || p1 == 0 || p2 == 0){
            direction[p1][p2] = dir;

            while(p1 != c1 || p2 != c2){
                if(direction[p1][p2] == 0){
                    ans += 'L';
                    p2++;
                }else if(direction[p1][p2] == 1){
                    ans += 'R';
                    p2--;
                }else if(direction[p1][p2] == 2){
                    ans += 'U';
                    p1++;
                }else{
                    ans += 'D';
                    p1--;
                }
            }

            reverse(ans.begin(),ans.end());

            done = true;
            break;
        }


        dist_me[p1][p2] = steps;
        direction[p1][p2] = dir;

        for(int i=0;i<4;i++){
            int cx = p1+dx[i];
            int cy = p2+dy[i];

            if(cx>=0 && cy>=0 && cx<n && cy<m){
                if(grid[cx][cy] != '#' && dist_me[cx][cy] == -1 && (dist_mon[cx][cy] == -1 || dist_mon[cx][cy] > steps+1)){

                    q.push({cx,cy,steps+1,i});
                }
            }
        }
    }

    if(done){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else{
        cout<<"NO"<<endl;
    }











    
    


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
       solve();


   }
}
