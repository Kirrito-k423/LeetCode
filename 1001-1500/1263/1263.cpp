#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
		//BFS找到的一定是最近的，但是要保证每步都可达
		//记录已经遍历的位置
		//判断人可达时，注意考虑箱子的位置(反向BFS)
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<char> > passed(grid.begin(), grid.end());
		pair<int, int> target;
		pair<int, int> player;
		queue<pair<int,int>> step;
		queue<pair<int,int>> tmpStep;
		int flag = 0;
		for(int j=0; j<m; ++j){
			for(int i=0; i<n; ++i){
				if(grid[j][i] == 'S'){player={j,i};flag++;}
				if(grid[j][i] == 'T'){target={j,i};flag++;}
				if(grid[j][i] == 'B'){step.push({j,i});flag++;}
				if(flag == 3)break;
			}
		}
		function<bool(pair<int,int>,pair<int,int>,pair<int,int>)> playerFrom2 = [&m, &n, &grid](pair<int,int> begin,pair<int,int> end,\
					pair<int,int> box){
			int endy = end.first; int endx = end.second;
			int beginy = begin.first; int beginx = begin.second;
			if(endx < 0 || endx > n-1 || endy < 0 || endy > m-1 || grid[endy][endx]=='#'){
				return false;
			}
			vector<vector<char> > passed(grid.begin(), grid.end());
			passed[box.first][box.second] = '#';
			queue<pair<int,int>> step;
			queue<pair<int,int>> tmpStep;
			step.push(end);
			while (!step.empty()) {
				while (!step.empty()) {
					pair<int,int> cur = step.front();
					if(cur==begin){
						return true;
					}
					int y = cur.first;
					int x = cur.second;
					step.pop();
					if(y > 0 && passed[y-1][x]!='#' ){
						tmpStep.push({y-1,x});
						passed[y-1][x]='#';
					} 
					if(y < m-1 && passed[y+1][x]!='#'){
						tmpStep.push({y+1,x});
						passed[y+1][x]='#';
					} 
					if(x > 0 && passed[y][x-1]!='#' ){
						tmpStep.push({y,x-1});
						passed[y][x-1]='#';
					} 
					if(x < n-1 && passed[y][x+1]!='#'){
						tmpStep.push({y,x+1});
						passed[y][x+1]='#';
					} 
				}
				swap(tmpStep, step);
			}
			return false;
		};
		int result = 0;
		while (!step.empty()) {
			while (!step.empty()) {
				pair<int,int> cur = step.front();
				if(cur==target){
					return result;
				}
				int y = cur.first;
				int x = cur.second;
				step.pop();
				if(y > 0 && passed[y-1][x]!='#' && playerFrom2(player,{y+1,x},cur)){
					tmpStep.push({y-1,x});
					passed[y-1][x]='#';
				} 
				if(y < m-1 && passed[y+1][x]!='#' && playerFrom2(player,{y-1,x},cur)){
					tmpStep.push({y+1,x});
					// passed[y+1][x]='#';
				} 
				if(x > 0 && passed[y][x-1]!='#' && playerFrom2(player,{y,x+1},cur)){
					tmpStep.push({y,x-1});
					// passed[y][x-1]='#';
				} 
				if(x < n-1 && passed[y][x+1]!='#' && playerFrom2(player,{y,x-1},cur)){
					tmpStep.push({y,x+1});
					passed[y][x+1]='#';
				} 
				player = cur;
			} 
			result++;
			swap(tmpStep, step);
		}
		return -1;
    }
};
int main(){
	Solution solution;
	vector<vector<char>> grid  = 
			{{'#','.','.','#','T','#','#','#','#'},
			{'#','.','.','#','.','#','.','.','#'},
			{'#','.','.','#','.','#','B','.','#'},
			{'#','.','.','.','.','.','.','.','#'},
			{'#','.','.','.','.','#','.','S','#'},
			{'#','.','.','#','.','#','#','#','#'}};

	cout << solution.minPushBox(grid )<< endl;
}

// 变种: 返回将箱子推到目标位置的最小 玩家移动 次数，