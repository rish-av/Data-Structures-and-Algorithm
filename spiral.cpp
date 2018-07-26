#include<iostream>
#include<vector>
using namespace std;
int main(){
    int A = 80;
    vector<vector<int> > answer(A,vector<int> (A));
    for(int i=0;i<A;i++){
        answer[i] = vector<int> (A);
    }
    int top = 0;
    int bottom = A - 1;
    int left = 0;
    int right = A - 1;
    vector<int> nums(A);
    for(int i=0;i<A*A;i++){
        nums[i] = (i+1);
    }
    int trav=0;
    while(top<=bottom &&  left<=right){
        for(int i=left;i<=right;i++){
            answer[top][i] = nums[trav++];
        }
        top++;
        for(int i=top;i<=bottom;i++){
            answer[i][right] = nums[trav++];
        }
        right--;
        for(int i=right;i>=left;i--){
            answer[bottom][i] = nums[trav++];
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            answer[i][left] = nums[trav++];
        }
        left++;
    }
    for(int i=0;i<A;i++){
        for(int j=0;j<A;j++){
            cout<<answer[i][j]<<"\t";
        }
        cout<<"\n";
    }
}