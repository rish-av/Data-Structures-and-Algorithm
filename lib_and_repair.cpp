#include <bits/stdc++.h>
using namespace std;
#define N 100005
void dfs(int i,vector<int> mat[],bool *visited,long &vcount){
    visited[i] = true;
    vcount++;
    vector<int>::iterator j;
    for(j=mat[i].begin();j!=mat[i].end();j++){
        if(!visited[*j]){
            dfs(*j,mat,visited,vcount);
        }
    }
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<int> adj[n];
    for(int i=0;i<cities.size();i++){
        adj[cities[i][0]-1].push_back(cities[i][1] -1);
        adj[cities[i][1]-1].push_back(cities[i][0] -1);
    }
    bool visited[n];
    for(long i=0;i<n;i++){
        visited[i] = false;
    }
    long cost = 0;
    for(long i=0;i<n;i++){
        if(!visited[i]){
            long vcount = 0;
            dfs(i,adj,visited,vcount);
            long cost1=c_lib + c_road*(vcount-1);
            long cost2=c_lib*(vcount);
            cout<<vcount<<" ";
            cost+=min(cost1,cost2);
            //cout<<cost;
        }
    }
    return cost;
}
int main(){
    vector<vector<int> > cities = {{8,2},{2,9}};
    int n = 9;
    int c1 = 91;
    int c2 = 84;
    long a = roadsAndLibraries(n,c1,c2,cities);
    cout<<a;
}