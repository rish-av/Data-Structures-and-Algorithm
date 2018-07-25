#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v{1,-2,3,4,6,-8,-9};
	int l=0,l1=0,r=0;
	int max=0,curr=0;
	for(int i=0;i<v.size();i++){
		curr = curr + v[i];
		if(curr<0){
			l1 = i+1;
			curr = 0;
		}
		if(curr>max && curr>0){
			r = i;
			max = curr;
			l = l1;
		}
	}
	cout<<l<<"\t"<<r<<"\t"<<max;
}