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
		//nums[i]-nums[k]==(j-maxJ) 寻找j-maxJ的候选set
		map<int, vector<int>> deltaJ2k;
		for(int i=1; i<n ;i++){
			deltaJ2k[nums[i-1]].push_back(i-1);
			for(int j = 0; j <= 2*maxJ; j++){
				vector<int> &candidate = deltaJ2k[nums[i]-(j-maxJ)];
				if(candidate.size()>0){
					// 结果单增，所以选择最后一个
					dp[i][j] += dp[candidate[candidate.size()-1]][j];
					result = max(result,dp[i][j]);
				}
				
			}
		}
		return result;
    }
};

//O(n^2) 960ms 12%