#include<bits/stdc++.h>
using namespace std;
#define N 100005
long idx[N];
long size[N];
void init(){
    for(long i=0;i<N;i++){
        idx[i] = i;
        size[i] = 1;
    }
}
long root(long x){
    while(x!=idx[x]){
        x = idx[x];
    }
    return x;
}
void union1(long x,long y){
    long r1 = root(x);
    long r2 = root(y);
    if(size[r1]>=size[r2]){
        idx[r2] = r1;
        size[r1]+=size[r2];
    }else{
        idx[r1] = r2;
        size[r2]+=size[r1];
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        long n,m;
        cin>>n>>m;
        long p[n];
        long q[n];
        for(long i=0;i<n;i++)
            cin>>p[i];
        for(long i=0;i<n;i++)
            cin>>q[i];
        while(m--){
            long x,y;
            cin>>x>>y;
            union1(p[x-1],p[y-1]);
        }
        int flag=0;
        for(long i=0 ;i<n;i++){
            if(p[i]!=q[i] && root(p[i])!=root(q[i])){
                flag = 1;
                cout<<"NO"<<"\n";
                break;   
            }
        }
        if(flag==0)
            cout<<"YES"<<"\n";
    }
}