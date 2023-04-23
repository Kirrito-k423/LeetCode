#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;


class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
		//-50 <= nums[i] <= 50 
		// 记录次数
		int n = nums.size();
		int count[102];
		memset(count, 0, sizeof(count));
		//先读取k个元素
		int i=0;
		for(; i<k; i++) {
			count[nums[i]+50]++;
		}
		vector<int> result;
		function<int()> findMinXth = [&](){
			int restX = x;
			int result = 0;
			for(int j=0; j<102; j++){
				if(restX <= count[j])

					return (j-50)<0?(j-50):0;
				else
					restX -= count[j];
			}
			return result;
		};
		for(; i<n; i++) {
			result.push_back(findMinXth());
			count[nums[i]+50]++;
			count[nums[i-k]+50]--;
		}
		result.push_back(findMinXth());
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