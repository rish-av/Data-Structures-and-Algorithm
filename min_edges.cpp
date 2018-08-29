#include<bits/stdc++.h> 
using namespace std; 
int main(){
	long n;
	cin>>n;
	vector<long> adj[n];
	for(long i=0;i<n-1;i++){
		long a,b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
	}
	queue<long> q;
	q.push(0);
	bool visited[n];
	int level = 1;
	long count=0;
	while(!q.empty()){
		int size = q.size();
		//cout<<size<<"\n";
		if(level>2 && level%2==0){
			count+=size;
		}
		while(size--){
			int a = q.front();
			visited[a] = true;
			q.pop();
			for(int i=0;i<adj[a].size();i++){
				if(!visited[adj[a][i]])
					q.push(adj[a][i]);
			}
		}
		level++;
	}
	cout<<count;
}