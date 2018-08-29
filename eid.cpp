#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll min = 300000000;
		for(ll i=0;i<n-1;i++){
			if(v[i+1]-v[i]<min)
				min = v[i+1] - v[i];
		}
		cout<<min<<"\n";
	}
}