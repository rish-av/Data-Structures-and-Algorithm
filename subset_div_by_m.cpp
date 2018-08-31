#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<int> vec(n);
	    ll sum;
	    for(int i=0;i<n;i++){
	        cin>>vec[i];
	        sum+=vec[i];
	    }
	    ll rem = sum%(long long)m;
	    cout<<rem;
	    bool dp[n+1][rem+1];
	    for(int i=0;i<=n;i++){
	        for(int j = 0;j<=rem;j++){
	            if(i==0 && j!=0) dp[i][j] = false;
	            if(j==0) dp[i][j] = true;
	        }
	    }
	    for(int i=1;i<n;i++){
	        for(int j =1;j<=rem;j++){
	            if(j<vec[i-1])
	                dp[i][j] = dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-vec[i-1]];
	        }
	    }
	    int flag=0;
	    for(int i=0;i<=n;i++){
	        if(dp[i][rem]){
	            flag = 1;
	            break;
	        }
	    }
	    if(!flag)
	        cout<<"0"<<"\n";
	    else
	        cout<<"1"<<"\n";
	}
}