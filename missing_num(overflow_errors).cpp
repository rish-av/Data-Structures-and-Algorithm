vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0;
    long long real_sumsquares = 0;
    long long n = A.size();
    long long ideal = (n*(n+1))/2;
    for(long long i=0;i<n;i++){
        sum+=(long long)A[i];
        real_sumsquares+=(long long)A[i]*A[i];
    }
    long long a,b;
    long long diff = ideal - sum;
    long long sum_squares = (n*(n+1)*(2*n+1))/6;
    long long sqdiff = sum_squares - real_sumsquares;
    long long sumab = sqdiff/diff;
    a = (sumab + diff)/2;
    b = (sumab - diff)/2;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(A[i]==a){
            flag = 1;
        }
    }
    vector<int> answer;
    if(flag==1){
        answer.push_back((int)a);
        answer.push_back((int)b);
    }else{
        answer.push_back((int)b);
        answer.push_back((int)a);
    }
    return answer;
}
