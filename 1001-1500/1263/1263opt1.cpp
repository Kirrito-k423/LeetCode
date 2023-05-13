#include <bits/stdc++.h>

using namespace std;

struct moveState{
	pair<int,int> box;
	pair<int,int> player;
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
		//BFS找到的一定是最近的，但是要保证每步都可达
		//记录已经遍历的位置
		//判断人可达时，注意考虑箱子的位置(反向BFS)
		int dirs[4][2] = {1,0,-1,0,0,1,0,-1}; // 不能放外面， playerFrom2 识别不了 dirs

		int m = grid.size();
		int n = grid[0].size();
		bool passed[20][20][20][20] = {0};
		pair<int, int> target;
		pair<int, int> player;
		pair<int, int> BB;
		queue<moveState> step;
		queue<moveState> tmpStep;
		int flag = 0;
		for(int j=0; j<m; ++j){
			for(int i=0; i<n; ++i){
				if(grid[j][i] == 'S'){player={j,i};flag++;}
				if(grid[j][i] == 'T'){target={j,i};flag++;}
				if(grid[j][i] == 'B'){BB={j,i};flag++;}
				if(flag == 3)break;
			}
		}
		step.push({BB, player});
		function<bool(pair<int,int>,pair<int,int>,pair<int,int>)> playerFrom2 = [&dirs, &m, &n, &grid](pair<int,int> begin,pair<int,int> end,\
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
			auto check = [&](int x, int y){
				return x >= 0 && y >= 0 && x < n && y < m && passed[y][x]!='#';
			};
			while (!step.empty()) {
				while (!step.empty()) {
					pair<int,int> cur = step.front();
					if(cur==begin){
						return true;
					}
					int y = cur.first;
					int x = cur.second;
					step.pop();
					for(auto &[addx, addy]: dirs){
						int nextx = x + addx;
						int nexty = y + addy;
						if(!check(nextx, nexty)) continue;
						tmpStep.push({nexty, nextx});
						passed[nexty][nextx] = '#';
					}
				}
				swap(tmpStep, step);
			}
			return false;
		};
		int result = 0;
		auto check = [&](int x, int y){
			return x >= 0 && y >= 0 && x < n && y < m && grid[y][x]!='#';
		};
		while (!step.empty()) {
			while (!step.empty()) {
				moveState cur = step.front();
				if(cur.box==target){
					return result;
				}
				int y = cur.box.first;
				int x = cur.box.second;
				player = cur.player;
				step.pop();
				for(auto &[addx, addy]: dirs){
					int nextx = x + addx;
					int nexty = y + addy;
					int befx = x - addx;
					int befy = y - addy;
					if(!check(nextx, nexty)) continue;
					if(passed[nexty][nextx][x][y]==0 && playerFrom2(player,{befy,befx},cur.box)){
						tmpStep.push({make_pair(nexty,nextx), cur.box});
						passed[nexty][nextx][x][y]=1;
					} 
				}
				// if(y > 0 && grid[y-1][x]!='#' && passed[y-1][x][cur.box.first][cur.box.second]==0 && playerFrom2(player,{y+1,x},cur.box)){
				// 	tmpStep.push({make_pair(y-1,x), cur.box});
				// 	passed[y-1][x][cur.box.first][cur.box.second]=1;
				// } 
				// if(y < m-1 && grid[y+1][x]!='#' && passed[y+1][x][cur.box.first][cur.box.second]==0 && playerFrom2(player,{y-1,x},cur.box)){
				// 	tmpStep.push({make_pair(y+1,x), cur.box});
				// 	passed[y+1][x][cur.box.first][cur.box.second]=1;
				// } 
				// if(x > 0 && grid[y][x-1]!='#' && passed[y][x-1][cur.box.first][cur.box.second]==0 && playerFrom2(player,{y,x+1},cur.box)){
				// 	tmpStep.push({make_pair(y,x-1), cur.box});
				// 	passed[y][x-1][cur.box.first][cur.box.second]=1;
				// } 
				// if(x < n-1 && grid[y][x+1]!='#' && passed[y][x+1][cur.box.first][cur.box.second]==0 && playerFrom2(player,{y,x-1},cur.box)){
				// 	tmpStep.push({make_pair(y,x+1), cur.box});
				// 	passed[y][x+1][cur.box.first][cur.box.second]=1;
				// } 
			} 
			result++;
			swap(tmpStep, step);
		}
		return -1;
    }
};
// int main(){
// 	Solution solution;
// 	// vector<vector<char>> grid  = 
// 	// 		{{'#','.','.','#','T','#','#','#','#'},
// 	// 		{'#','.','.','#','.','#','.','.','#'},
// 	// 		{'#','.','.','#','.','#','B','.','#'},
// 	// 		{'#','.','.','.','.','.','.','.','#'},
// 	// 		{'#','.','.','.','.','#','.','S','#'},
// 	// 		{'#','.','.','#','.','#','#','#','#'}};

// vector<vector<char>> grid  = 
// {{'.','.','.','.','.','#','.','.','.','.','.','.'},
// {'.','.','.','.','#','.','.','.','.','.','.','.'},
// {'.','.','#','.','.','.','#','.','.','.','.','.'},
// {'.','.','.','.','#','.','#','#','S','#','.','.'},
// {'.','.','.','.','.','.','.','.','.','B','.','.'},
// {'.','.','.','.','.','.','.','.','.','.','.','#'},
// {'.','.','.','.','#','.','.','.','.','.','.','.'},
// {'#','.','#','.','#','.','#','.','#','.','.','.'},
// {'.','.','T','.','.','#','.','.','.','.','.','.'},
// {'.','.','#','.','#','#','#','.','.','.','.','.'},
// {'.','.','.','#','.','#','.','.','.','.','.','.'}};
// 	cout << solution.minPushBox(grid )<< endl;
// }

// 变种: 返回将箱子推到目标位置的最小 玩家移动 次数，