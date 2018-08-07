#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long temp = n;
		long long i = 0;
		while(temp!=0){
			i++;
			temp = n/(long long)pow(2,i);
		}
		long long num = n%(long long)pow(2,(i-1));
		if(num!=0){
			long long temp2 = num;
			long long y = 0;
			while(temp2!=0){
				y++;
				temp2 = num/(long long)pow(2,y);
			}
			long long rem1 = (long long)pow(2,y) - num;
			long long rem2 = num%(long long)pow(2,(y-1));
			if(rem1>=rem2){
				cout<<rem2<<"\n";	
			}else{
				cout<<rem1<<"\n";
			}
		}else if(n==1){
			cout<<"2"<<"\n";
		}else{
			cout<<"1"<<"\n";
		}
		
	}
}