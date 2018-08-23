#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	for(int i=2;i<n;i++){
		if(nums[i]<nums[i]+nums[i-2]){
			nums[i] = nums[i] + nums[i-2];
		}
	}
	int max = nums[0];
	for(int i=0;i<n;i++){
		if(max<nums[i]){
			max = nums[i];
		}
	}
	cout<<max;
}