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
    bool checkArray(vector<int>& nums, int k) {
        // 从头处理
		queue<pair<int, int>> endDown;
		int n = nums.size();
		int sumDown = 0;
		for (int i=0; i<n; i++) {
			if(endDown.front().first == i) {
				int del = endDown.front().second;
				sumDown -= del;
				endDown.pop();
			}
			if(nums[i] > sumDown){
				endDown.push(make_pair(i+k,nums[i]-sumDown));
				sumDown = nums[i];
			}
			if(nums[i] < sumDown)	return false;
		}
		if(endDown.front().first == n) {
			int del = endDown.front().second;
			sumDown -= del;
			endDown.pop();
		}
		if(endDown.size()==0) return true;
		else return false;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }