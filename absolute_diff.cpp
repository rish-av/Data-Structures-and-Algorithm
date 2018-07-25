int Solution::maxArr(vector<int> &A) {
    int max1 =A[0] ,min1=A[0],max2=A[0],min2=A[0];
    int t1,t2;
    for(int i=0;i<A.size();i++){
        t1 = A[i]+i;
        t2 = A[i]-i;
        if(t1>max1){
            max1 = t1;
        }
        else if(t1<min1){
            min1 = t1;
        }
        if(t2>max2){
            max2 = t2;
        }
        else if(t2<min2){
            min2 = t2;
        }
    }
    int ans1 = max1-min1;
    int ans2 = max2-min2;
    if(ans1>ans2){
        return ans1;
    }
    return ans2;
}
//maximize f = |A[i] - A[j]| + |i-j|