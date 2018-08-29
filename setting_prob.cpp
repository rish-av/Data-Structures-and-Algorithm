#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000006],ans,sum=0;
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>2*a[i-1]) sum=1;
		else sum++;
		ans=max(ans,sum);
	}
	cout<<ans;
}