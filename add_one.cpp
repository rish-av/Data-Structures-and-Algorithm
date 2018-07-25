vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> answer;
    if(A.back()!=9){
        answer.push_back(A.back()+1);
        A.pop_back();
        while(!A.empty()){
            answer.push_back(A.back());
            A.pop_back();
        }
    }
    else{
        while(A.back()==9){
            answer.push_back(0);
            A.pop_back();
        }
        if(!A.empty()){
            answer.push_back(A.back()+1);
            A.pop_back();
            while(!A.empty()){
                answer.push_back(A.back());
                A.pop_back();
            }
        }
        else{
            answer.push_back(1);
        }
    }
    reverse(answer.begin(),answer.end());
    while(answer.front()==0){
        answer.erase(answer.begin());
    }
    return answer;
}
