#include<bits/stdc++.h>
using namespace std;
#define N 1300
typedef pair<int,int> pii;
int roadways[N][N];
int railways[N][N];
int rev1[N][N];
int rev2[N][N];
int* djk(int mat[][N],int n,int v){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({0,v-1});
    int* dist = (int*)malloc(sizeof(int)*n);
    bool visited[n];
    for(int i=0;i<n;i++){
        dist[i] = 1e9;
        visited[i] = false;
    }
    dist[v-1] = 0;
    while(!q.empty()){
        int e = q.top().second;
        int w = q.top().first;
        q.pop();
        for(int i=0;i<n;i++){
            if(mat[e][i]!=0 && !visited[e] && dist[i]>(dist[e] + mat[e][i])){
                dist[i] = dist[e] + mat[e][i];
                q.push({dist[i],i});
            }
        }
        visited[e] = true;
    }
    return dist;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>roadways[i][j];
            rev1[j][i] = roadways[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>railways[i][j];
            rev2[j][i] = railways[i][j];
        }
    }
    int u,v;
    cin>>u>>v;
    int* dist1 = djk(roadways,n,u);
    int* dist2 = djk(railways,n,u);
    int* dist3 = djk(rev1,n,v);
    int* dist4 = djk(rev2,n,v);
    int m = 30000;
    int temp = 0;
    for(int i=0;i<n;i++){
        if(i!=v-1 && i!=u-1){
            temp = min(dist1[i]+dist4[i],dist2[i]+dist3[i]);
            if(temp<m){
                m = temp;
            }
        }
    }
    cout<<m;
}