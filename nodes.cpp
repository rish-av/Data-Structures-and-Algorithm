#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<int>* adj,int v,int n){
    int visited[n] = {0};
    vector<int> level;
    level.push_back(1);
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int size = q.size();
        int temp = 0;
        while(size--){
            int a = q.front();
            q.pop();
            visited[a] = 1;
            for(int i=0;i<adj[a].size();i++){
                if(!visited[adj[a][i]]){
                    q.push(adj[a][i]);
                    temp++;
                }
            }
        }
        level.push_back(temp);
    }
    return level;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> ans = BFS(adj,0,n);
    for(int i=0;i<ans.size()-1;i++){
        cout<<i<<"-->"<<ans[i]<<"\n"; 
    }
}
