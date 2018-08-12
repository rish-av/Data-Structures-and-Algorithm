#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		v[i] = i+1;
	}
	int t=1;
	while(t!=m){
		next_permutation(v.begin(),v.end());
		t++;
	}
	cout<<v[k-1];
}