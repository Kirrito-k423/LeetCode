	#include <bits/stdc++.h> 
	// stdc++.h 几乎包含所有常用头文件
	using namespace std;
	typedef pair<int,int>PII;
	const int MOD = 1e9 + 7;
	const int INF = 2e9;
	// #define x first
	// #define y second
	typedef long long ll;
	const int N=1E5+10,M=210;


	class Solution {
	public:
		int maximumBeauty(vector<int>& nums, int k) {
			//排序后变滑动窗口
			sort(nums.begin(), nums.end());
			int result = 0;;
			int tmp_length = 0;
			int left = 0, right = 0;
			int n = nums.size();
			const int gap = 2*k;
			for( ;left < n && right<n; left++) {
				while(right<n && nums[right]-nums[left] <= gap){
					result = max(result,right-left+1);
					right++;
				}
			}
			return result;
		}
	};
	// int main(){
	// 	Solution solution;
	// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	// 	vector<int> price ={2,2,10,6};
	// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
	// }