#include <bits/stdc++.h>
using namespace std;
#define N 1000
int adj[N][N];
bool visited[N][N];
int dir[8][2] = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
long long factorial[N];
int n,m;
long long  count;
long long sum;
bool isValid(int a,int b){
    if(a<n && a>=0 && b<m && b>0)
        return true;
    return false;
}
void dfs(int x ,int y){
    visited[x][y] = true;
    count++;
    int a,b;
    for(int i=0;i<8;i++){
        int a = x + dir[i][0];
        int b = y + dir[i][1];
        if(!visited[a][b] && isValid(a,b) && adj[a][b]==1){
            dfs(a,b);
        }
    }
}
int main(){
    int t;
    cin>>t;
    factorial[0] = 1;
    for(long long i=1;i<N;i++){
        factorial[i] = i*factorial[i-1]; 
    }
    while(t--){
        long q;
        cin>>n>>m>>q;
        sum = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                adj[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for(long i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            adj[a-1][b-1] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && adj[i][j]){
                    count = 0;
                    dfs(i,j);
                    sum = (sum*factorial[count])%1e7;
                }
            }
        }
        cout<<sum;
    }
}