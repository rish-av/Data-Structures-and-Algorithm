#include <iostream>
using namespace std;
#include<vector>
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int front = nums[0];
        int back = nums[nums.size()-1];
        int i = 1;
        int j = nums.size() - 2;
        while(i<j){
            if(front<back){
                front+=nums[i++];
            }
            else if(back<front){
                back+=nums[j--];
            }
            else{
                back+=nums[j--];
                front+= nums[i++];
            }
        }
        if(i==j && back==front && nums.size()>1){
            cout<<i+1<<"\n";
        }else if(nums.size() == 1){
            cout<<"1"<<"\n";
        }else{
            cout<<"-1"<<"\n";
        }
    }
}