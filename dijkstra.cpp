#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define N 10000
vector<pii> adj[N];
int* djk(vector<pii>* adj,int n){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({0,0});
    int* dist = (int*)malloc(sizeof(int)*n);
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        dist[i] = 1e9;
    }
    dist[0] = 0;
    while(!q.empty()){
        int e = q.top().second;
        q.pop();
        for(int i=0;i<adj[e].size();i++){
            if(!visited[e] && dist[adj[e][i].first] > dist[e] + adj[e][i].second){
                dist[adj[e][i].first] = dist[e] + adj[e][i].second;
                q.push({dist[adj[e][i].first],adj[e][i].first});
            }
        }
        visited[e] = true;
    }
    return dist;
}
int main(){
    int n;
    long m;
    cin>>n>>m;
    for(long i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    int* a = djk(adj,n);
    for(int i=1;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}