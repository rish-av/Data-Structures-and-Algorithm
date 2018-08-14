#include <iostream>
using namespace std;
struct stack{
	int top;
	int* ele;
}typedef Stack; 
void kcoreDFS(int** adj,int n,int* deg,int v,Stack accepted,int k,int* visited){
	if(deg[v]<k){
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
			kcoreDFS(adj,n,deg,i,accepted,k,visited);
		}
	}

}
void kcores(int** adj,int n,int k){
	int deg[n] = {0};
	int visited[n] = {0};
	Stack s;
	s.top = -1;
	s.ele = (int*)malloc(sizeof(int));
	int min = 0;
	int mindeg = n+1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j]==1){
				deg[i]++;
			}
		}
		cout<<deg[i]<<" "<<endl; 
		if(deg[i]<mindeg){
			mindeg = deg[i];
			min = i;
		}
		cout<<"min : "<<min<<"\n";
	}
	kcoreDFS(adj,n,deg,min,s,k,visited);
}
int main(){
	int** adj = (int**)malloc(sizeof(int *)*5);
	for(int i=0;i<5;i++){
		adj[i] = (int*)malloc(sizeof(int)*5);
	}
	int mat[5][5] = {{0,0,0,1,0},{1,0,1,0,1},{1,0,0,0,1},{0,1,1,0,1},{0,0,0,1,0}};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			adj[i][j] = mat[i][j]; 
		}
	}
	kcores(adj,5,1);
	for(int i=0;i<5;i++){
		cout<<i<<"-->";
		for(int j=0;j<5;j++){
			if(adj[i][j]==1){
				cout<<j<<"->";
			}
		}
		cout<<"\n";
	}
}