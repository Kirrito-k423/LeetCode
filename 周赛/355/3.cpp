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
    int maxIncreasingGroups(vector<int>& usageLimits) {
		// can borrow elements from the next group
		int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end(), std::greater<int>());
		int result = 0;
		auto it = lower_bound(usageLimits.begin(), usageLimits.end(), n, [](const int element, int value) {
			return element >= value;
		});
		int i = distance(usageLimits.begin(), it);
		int limit = INT_MAX;
		for (; i < n; i++,limit--)
		{
			limit = min(limit,usageLimits[i]);
			if(limit<=0) break;
			else{
				result = i;
			}	
		}
		assert(result > n);
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