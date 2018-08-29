#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int temp = n;
		int flagi =0;
		int flagw = 0;
		while(n--){
			string s1,s2;
			cin>>s1>>s2;
			int count=0;
			if(s1=="correct"){
				for(int i=0;i<m;i++){
					if(s2[i]!='1'){
						flagi =1;
					}
				}
			}else{
				for(int i=0;i<m;i++){
					if(s2[i]=='1')
						count++;
				}
				if(count==m)
					flagw = 1;
			}
		}
		if(flagi){
			cout<<"INVALID"<<"\n";
		}else if(flagw){
			cout<<"WEAK"<<"\n";
		}else{
			cout<<"FINE"<<"\n";
		}

	}
}