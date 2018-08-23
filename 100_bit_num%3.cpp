#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int odd=0;
	    int even=0;
	    for(int i=s.length()-1;i>=0;i--){
	        if(s[i]=='1' & i%2==0){
	            odd++;
	        }else if(s[i]=='1' && i%2!=0){
	            even++;
	        }
	    }
	    int flag = 0;
	    if((odd+even*2)%3 == 0){
	        cout<<"1"<<"\n";
	        flag = 1;
	    }
	    if(flag==0)
	        cout<<"0"<<"\n";
	}
}