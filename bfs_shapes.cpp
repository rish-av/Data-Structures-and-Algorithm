#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void utility(int v,vector<int> adj[],int visited[]){
	visited[v] = 1;
	cout<<v<<" ";
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(!visited[*i])
			utility(*i,adj,visited);
	}
}
void dfs(int v,vector<int> adj[]){
	int size = adj[0].size();
	int visited[size] = {0};
	utility(v,adj,visited);
}
void DFSutil(int s,int v,int** tc,vector<int>* &adj){
	tc[s][v] = 1;
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(!tc[s][*i])
			(s,*i,tc);
	}
}
void transitive_closure(vector<int>* adj){
	int size = adj[0].size();
	int tc[size][size] = {0};
	for(int i=0;i<size;i++){
		DFSutil(i,i,tc,adj);
	}
}
bool isValid(int i , int j ,int m ,int n)
{
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}
int findXs(){
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char ch[n][m];
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                ch[i][j] = s[j];
            }
        }
        int visited[n][m]={0};
        int shapes = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && ch[i][j]=='X'){
                    shapes++;
                    stack<pair<int,int> > s;
                    s.push(make_pair(i,j));
                    while(!s.empty()){
                      pair<int,int> p = s.top();
                      s.pop();
                      int a = p.first;
                      int b = p.second;
                      visited[a][b] = 1;
                      if(isValid(a-1,b,m,n) && ch[a-1][b]=='X' && !visited[a-1][b]){
                           s.push(make_pair(a-1,b));
                       }
                      if(isValid(a,b-1,m,n) && ch[a][b-1]=='X' && !visited[a][b-1]){
                           s.push(make_pair(a,b-1));
                       }
                      if(isValid(a,b+1,m,n) && ch[a][b+1]=='X' && !visited[a][b+1]){
                           s.push(make_pair(a,b+1));
                       }
                      if(isValid(a+1,b,m,n) && ch[a+1][b]=='X' && !visited[a+1][b]){
                           s.push(make_pair(a+1,b));
                       }
                    }
                }
            }
        }
        cout<<shapes<<"\n";
    }
}
struct stack{
	int top;
	int* ele;
}typedef Stack; 
void kcoreDFS(int** adj,int n,int* deg,int v,Stack accepted,int k){
	if(deg[v]>k){
		accepted.ele[accepted.++top] = v;
	}else{
		for(int i=0;i<n;i++){
			if(adj[v][i]==1){
				deg[i]--;
			}
			adj[i][v] = 0;
		}
	}
	visited[v] = 1;
	for(int i=0;i<n;i++){
		if(adj[v][i]==1 && !visited[i]){
			kcoreDFS(adj,n,deg,i,accepted,k);
		}
	}

}
void kcores(int** adj,int n){
	int deg[n];
	int visited[n] = {0};
	Stack s;
	s.top = -1;
	s.ele = (int*)malloc(sizeof(int));
	int min = n+1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j]==1){
				deg[i]++;
			}
		}
		if(deg[i]<min){
			min = deg[i];
		}
	}
	kcoreDFS(adj,n,deg,min,s,3);
}
int main() {
	int adj[5][5] = {{1,0,0,1,0},{1,1,1,0,1},{1,0,1,0,1},{0,1,1,1,1},{0,0,0,1,0}};
	kcores(adj,5);
}
