#include<stdlib.h>
int coverPoints(int* A, int n1, int* B, int n2) {
    int steps = 0;
    int i = 0;
    for(;i<n1-1;i++){
        if(A[i] == A[i+1] && B[i]!=B[i+1]){
            steps+=abs(B[i+1] - B[i]);
        }
        else if(A[i]!=A[i+1] && B[i]==B[i+1]){
            steps+=abs(A[i+1] - A[i]);
        }
        else if(A[i]!=A[i+1] && B[i]!=B[i+1]){
            int t1 = abs(A[i+1] - A[i]);
            int t2 = abs(B[i+1] - B[i]);
            if(t1>t2){
                steps+= t1;
            }
            else{
                steps+= t2;
            }
        }
        else{
            steps+=0;
        }
    }
    return abs(steps);
}