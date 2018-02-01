#include<iostream>
#include<stack>
using namespace std;
void insert(stack<int> s,int temp){
 if(s.size()==0){
  s.push(temp);
 }
 else{
  int a = s.top();
  s.pop();
  insert(s,a);
 }
}
void hold(stack<int> s){
 if(s.size()>0){
   int temp = s.top();
   s.pop();
   hold(s); 
   insert(s,temp);
  }
}
int main(){
 stack<int> a;
 a.push(1);
 a.push(2);
 a.push(3);
 hold(a);
 cout<<a.top();
 a.pop();
 cout<<a.top();
 a.pop();
 cout<<a.top();
 a.pop();
}

