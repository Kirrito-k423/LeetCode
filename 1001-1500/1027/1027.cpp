#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;



// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
		int maxJ = *max_element(nums.begin(),nums.end()) - 
					*min_element(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>(1002,1));
		int result = 0;
		for(int i=1; i<n ;i++){
			for(int j = 0; j <= 2*maxJ; j++){
				int tmp = 0;
				for(int k = i-1; k >= 0  ; k--){
					if(nums[i]-nums[k]==(j-maxJ)){
						tmp = max(tmp,dp[k][j]);
						break;
					}
				}
				dp[i][j] += tmp;
				result = max(result,dp[i][j]);
			}
		}
		return result;
    }
};