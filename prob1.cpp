#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string top;
		string bottom;
		cin>>top;
		cin>>bottom;
		int b1=0,b2=0,b3=0,o1=0,o2=0,o3=0;
		if(top[0]=='b'||bottom[0]=='b')
			b1=1;
		if(top[1]=='b'||bottom[1]=='b')
			b2=1;
		if(top[2]=='b'||bottom[2]=='b')
			b3=1;
		if(top[0]=='o'||bottom[0]=='o')
			o1=1;
		if(top[1]=='o'||bottom[1]=='o')
			o2=1;
		if(top[2]=='o'||bottom[2]=='o')
			o3=1;
		if((b1==1 && b2==1 && o3==1) || (b1==1 && o2==1 && b3==1) || (o1==1 && b2==1 && b3==1)){
			cout<<"yes"<<"\n";
		}else{
			cout<<"no"<<"\n";
		}
	}
}