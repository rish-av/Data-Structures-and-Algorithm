#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll add(ll a,ll b)
{
    return ((a*(a-1))-(b*(b-1)))/2;
}

int main() {
    int n,k,t,a,x,d;
    cin>>t;
    
    while(t--)
    {
        cin>>n>>k>>x>>d;
        vector <int> v;
        int flag = 0;
        ll sum=0;
        for(int i=0;i<k;i++)
        {
            cin>>a;
            sum+=a;
            v.push_back(a);
        }
        if(n==k)
            cout<<sum<<endl;
        else
        {
            sort(v.begin(),v.end());
            for(int i=0;i<k;i++)
            {
                if(abs(v[0]+x-v[k])<=d)
                {
                    flag = 1;
                }
            }
        if(!flag){
            if(v[k-1]!=v[0]+x)
            {
            v.push_back(v[0]+x);
            sum+=v[0]+x;
            k++;
            }
            
            int rem=n-k;
            
            for(int i=k-1;i>0;i--)
            {
                int diff=min(rem,v[i]-v[i-1]-1);
                sum+=add(v[i],v[i]-diff);
                rem-=diff;
            }
            cout<<sum<<endl;
        }
        else
        {
            cout<<"-1";
        }
    }
}
    return 0;
}