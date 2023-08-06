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
	void bfs(int p, int q, vector<vector<int>> & dict){
		int n = dict.size();
		vector<int> line(n);
		for(int i=0; i<n; i++) line[i] = abs(q-i);
		for(int i=0; i<n; i++){
			int part1 = abs(p-i);
			for(int j=0; j<n; j++){
				int target = line[j] + part1;
				dict[i][j]=min(dict[i][j],target);
			}
		}
	}

	bool findPath(vector<vector<int>> & dict, int limit){
		int dirs[4][2]  = {1,0,-1,0,0,1,0,-1}; 
		int n = dict.size();
		vector<vector<bool>> tmp(n, vector<bool>(n, true));
		queue<pair<int,int>> search_node;
		search_node.push({0,0});
		auto check = [&](int x, int y){
			return x >= 0 && y >= 0 && x < n && y < n && tmp[x][y] && dict[x][y]>=limit;
		};
		while(!search_node.empty()){
			auto cur = search_node.front();
			search_node.pop();
			auto &x= cur.first;
			auto &y= cur.second;
			for(auto &[addx, addy]: dirs){
				int nextx = x + addx;
				int nexty = y + addy;
				if(check(nextx,nexty)){
					if(nextx == n-1 && nexty == n-1) return true;
					tmp[nextx][nexty]=false;
					search_node.push({nextx,nexty});
				}
			}
		}
		return false;

	}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grid[i][j]==1){
					// spreading
					bfs(i,j,dist);
				}
			}
		}

		int right = n-1, left = 0;

		if(findPath(dist,right)) return right;
		while(left + 1 < right){
			int mid = left + ((right-left)>>1); // 注意括号 >> 优先级最低
			if(findPath(dist,mid)){
				left = mid; // while结束时 left 满足 其tmpCntSum <= cnt
			}else{
				right = mid; // while结束时 right 满足 其tmpCntSum > cnt
			}
		}
		return left;
    }
};
int main(){
	Solution solution;
	vector<vector<int>> edges = {{{1,0,0},{0,0,0},{0,0,1}}} ;
	// vector<int> price ={2,2,10,6};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	cout << solution.maximumSafenessFactor(edges)<< endl;
}