#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
//状态dp
ll max(ll x,ll y)
{
    if(x>=y)    return x;
    return y;
}
int main()
{
    int t;
    cin>>t;
    vector<ll> ans(t);
    for(int i=0;i<t;i++)
    {
        int n,v;
        cin>>n>>v;
        vector<int> nums(n);
        for(int j=0;j<n;j++)
        {
            cin>>nums[j];
        }
        vector<vector<ll>> dp(n,vector<ll>(2));
        dp[0][0]=nums[0];
        dp[0][1]=v;
        ll maxv=max(dp[0][0],dp[0][1]);
        for(int j=1;j<n;j++)
        {
            dp[j][0]=max(dp[j-1][0]+nums[j],nums[j]);
            dp[j][1]=max(max(dp[j-1][0]+v,v),max(dp[j-1][1]+nums[j],nums[j]));
            maxv=max(maxv,max(dp[j][0],dp[j][1]));
        }
        ans[i]=maxv;
    }
    for(auto num:ans)   cout<<num<<endl;
    return 0;
}
