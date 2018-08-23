#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int digits = 31;
	vector<int> bin(32);
	while(n>0){
		bin[digits] = !(n%2);
		digits--;
		n = n/2;
	}
	while(digits>=0){
		bin[digits] = 1;
		digits--;
	}
	for(int i=0;i<bin.size();i++){
		cout<<bin[i];
	}
	long num = 0;
    digits = 31;
    for(int i=0;i<32;i++){
        num+=pow(2,digits)*bin[i];
        digits--;
    }
    cout<<num;
}