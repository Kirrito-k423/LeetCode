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
		// 由于答案有明显上界 n 是二分答案


		function<int(int)> check = [&](int answer){
			long long gap = 0;
			for(int i=0; i<n; i++){
				int energy = usageLimits[i];
				int toFill = (i<answer)?(answer-i):0;
				if(energy>toFill){
					int reset = energy - toFill;
					if(gap>0){
						gap=max(0ll,gap-(long long)reset);
					}
				}else{
					gap+=toFill-energy;
				}
			}
			return gap == 0;
		};
		if(check(n)) return n;
		if(!check(0)) return 0;
		int left = 0, right = n;
		while(left < right-1){
			int mid = left + ((right-left)>>1);
			if(check(mid)){
				left = mid;
			}else{
				right = mid;
			}
		}

		return left;

    }
};
// int main(){
// 	Solution solution;
// 	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,1,2};
// 	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.maxIncreasingGroups(price)<< endl;
// }