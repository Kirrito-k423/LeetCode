#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        //dp(i,j)代表到达i，j需要的最短的步数
		int in = grid.size();
		int jn = grid[0].size();
		vector<vector<int>> dp(in, vector<int>(jn, __INT_MAX__-1));
		dp[0][0]=0;
		for(int j=0; j<jn; j++){
			priority_queue<int> smallJ;
			for(int i=0; i<in; i++){
				int cur = dp[i][j];
				//cur j
				for(int smallj=0; smallj<j; smallj++){
					if(j <= grid[i][smallj]+smallj){
						cur = min(cur,dp[i][smallj]+1);
					}
				}
				//cur i
				for(int smalli=0; smalli<i; smalli++){
					if(i <= grid[smalli][j]+smalli){
						cur = min(cur,dp[smalli][j]+1);
					}
				}
				dp[i][j]=cur;
			}
		}
		if(dp[in-1][jn-1]==__INT_MAX__-1)
			return -1;
		else
			return dp[in-1][jn-1]+1;
    }
};

//DP超时 O(mn(m+n))
//如何剪枝呢？简化单次规划的时间O(m+n) -> 反转DP方向 + 二分查找单调栈
	//由于求min，在push时构建递增的单调栈，后push元素要是能使用优先级最高的最小值，按题意最近, 所以能丢弃覆盖的元素（由于求min，丢弃覆盖的更大的元素）
	//由于新元素位于栈末尾，而且新元素的index小，所以index也是单调递减的) / 优先队列