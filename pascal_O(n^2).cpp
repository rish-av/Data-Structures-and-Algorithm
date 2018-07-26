vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > answer;
    for(int i=0;i<A;i++){
        vector<int> nums;
        nums.push_back(1);
        if(i==0){
            answer.push_back(nums);
        }
        else if(i==1){
            nums.push_back(1);
            answer.push_back(nums);
        }else{
            vector<int> prev = answer.back();
            int size = prev.size();
            for(int j=1;j<size;j++){
                if(j-1>=0){
                    int a = prev[j] + prev[j-1];
                    nums.push_back(a);
                }
            }
            nums.push_back(1);
            answer.push_back(nums);
            
        }
    }
    return answer;
}
