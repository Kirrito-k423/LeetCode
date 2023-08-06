#include <bits/stdc++.h>

using namespace std;
const int NX = 200000;
long long sum_array[NX];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		for(int i=0; i<n; i++){
			cin >> sum_array[i];
		}

		// force max
		long long result = INT_MIN;
		long long dp[n][2];
		memset(dp, 0, sizeof(dp));//?
		dp[0][0] = sum_array[0];
		dp[0][1] = x;
		for(int i=1; i<n; i++){
			dp[i][0] = max(dp[i-1][0], sum_array[i]);
			dp[i][1] = max( max(dp[i-1][0] + x, (long long)x),
						max(dp[i-1][1] + sum_array[i], sum_array[i]) );
			result = max(result, dp[i][0]+dp[i][1]);
		}
		cout << result << endl;
	}
}