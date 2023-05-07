#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        //贪心， 都变成最大的一条路径值，，如果儿子相等在父亲节点加
        int result = 0;
        function<int(int )> dfs = [&result, &n, &cost,&dfs](int root) {//返回子树深度
            if(2*root > n) return cost[root-1];
            int right = dfs(2*root);
            int left = dfs(2*root+1);
            int maxValue = max(left, right);
            int minValue = min(right, left);
            result += maxValue - minValue;
            return maxValue + cost[root-1];
        };
        dfs(1);
        return result;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	vector<int> price ={1,5,2,2,3,3,1};
	cout << solution.minIncrements(7, price)<< endl;
}