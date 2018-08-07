#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b,n;
		cin>>a>>b>>n;
		long long power = pow(a,n) + pow(b,n);
		int diff = abs(a-b);
		int hcf;
		for(int i=1;i<=diff;i++){
			if(power%i==0 && diff%i==0){
				hcf = i;
			}
		}
		if(diff==0){
			cout<<power<<"\n";
		}
		else{
			cout<<hcf<<"\n";
		}
	}
}