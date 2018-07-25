#include<iostream>
using namespace std;
int max_spam(int *arr,int n)
{
    int count=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==0)
       arr[i]=1;
       else
       count++,arr[i]=-1;
   }
   if(count==n)
   return n;
   int ind_x=0,ind_y=0,max_sum=-1,max_so_far=0,s_x=0,s_y=0;
   for(int i=0;i<n;i++)
   {
       max_so_far=max(arr[i],arr[i]+max_so_far);
       if(max_so_far==arr[i])
       s_x=i;
       if(max_so_far>max_sum)
       {
           max_sum=max_so_far;
           ind_x=s_x;
           ind_y=i;
       }
       
   }
  
   return (count+max_sum);
   
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<max_spam(arr,n)<<endl;
    }
}