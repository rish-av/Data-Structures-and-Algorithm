#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> &v){
	vector<int> lis(v.size());
	for(int i=0;i<lis.size();i++){
		lis[i] = 1;
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<i;j++){
			if(v[i]>v[j] &&  lis[i]<lis[j]+1)
				lis[i] = lis[j]+1;
		}
	}
	int max = lis[0];
	for(int i=0;i<v.size();i++){
		if(lis[i]>max)
			max = lis[i];
	}
	return max;
}
//----------------------------------------------------------------------------------------------------------------------//
int max_sum_triangle(vector<vector<int> > &tri){
	int h = tri.size()-1;
	vector<int> max(h);
	for(int j=h-1;j>=0;j--){
		for(int i=0;i<=j;i++){
			if(tri[j+1][i]>tri[j+1][i+1])
				tri[j][i]+=tri[j+1][i];
			else
				tri[j][i]+=tri[j+1][i+1];
		}
	}
	return tri[0][0];
}
//----------------------------------------------------------------------------------------------------------------------//
int main(){
	vector<vector<int> > t{  {1, 0, 0},
                      {4, 8, 0},
                      {1, 5, 3} };
	vector<int> v{1,2,5,6,7,4};
	int max = max_sum_triangle(t);
	int a = lis(v);
	cout<<max;
}