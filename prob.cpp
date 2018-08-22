#include<bits/stdc++.h>
using namespace std;
long long root(long long x,vector<long long> &data){
    while(x!=data[x]){
        x = data[x];
    }
    return x;
}
void union1(long long x,long long y,vector<long long> &data){
    long long r1 = root(x,data);
    long long r2 = root(y,data);
    data[r2] = r1;
}
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<pair<long long,pair<long long,long long> > > edges;
    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        edges.push_back(make_pair(c,make_pair(a,b)));
    }
    vector<long long> vec(n);
    for(long long i=0;i<n;i++){
        vec[i] = i;
    }
    sort(edges.begin(),edges.end());
    vector<long long> weights;
    int mincost = 0;
    for(long long i=0;i<m;i++){
        long long w = edges[i].first;
        long long x = edges[i].second.first;
        long long y = edges[i].second.second;
        if(root(x,vec)!=root(y,vec)){
            mincost+=w;
            weights.push_back(w);
            union1(x,y,vec);
        }
    }
    sort(weights.begin(),weights.end());
    long long ops = 0;
    if(mincost<=k){
        cout<<"-1";
    }
    else{
        for(long long i=0;i<weights.size();i++){
            mincost -= weights[i];
            ops++;
            if(micost<=k)
                break;
        }
        cout<<ops;
    }
    
}