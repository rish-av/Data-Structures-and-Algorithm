#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll z1,z2;
		cin>>n>z1>>z2;
		z1 = abs(z1);
		z2 = abs(z2);
		vector<ll> A(n);
		for(int i=0;i<n;i++){
			cin>>A[i];
			A[i] = abs(A[i]);
		}
		ll turn1 = 0;
		ll turn2 = 0;
		int flag2 = 0;
		int flag1 = 0;
		while(!flag1){
			z1-=closest(z1,A);
			turn1++;
			if(z1<0){
				flag1 = 1;
			}
			if(z1==0){
				break;
			}
		}
		while(!flag2){
			z2-=closest(z2,A);
			turn2++;
			if(z2<0){
				flag2 =1;
			}
			if(z2==0){
				break;
			}
		}
		if(flag1 && flag2)
			cout<<"0";
		else if(flag1 && !flag2){
			if(turn2%2==0){
				cout<<"2";
			}else{
				cout<<"1";
			}
		}else if(!flag1 && flag2){
			if(turn1%2==0){
				cout<<"2";
			}else{
				cout<<"1";
			}
		}else if(!flag1 && !flag2){
			if(turn1>=turn2){
				if(turn2%2==0)
					cout<<"2";
				else
					cout<<"1";
			}
			else{
				if(turn1%2==0)
					cout<<"2";
				else
					cout<<"1";
			}
		}
	}
}