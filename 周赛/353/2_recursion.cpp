#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E3+10,M=210;


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        map<int,vector<int>> numPositionList;
		for(int i=0; i<nums.size(); i++) {
			if(numPositionList.count(nums[i])) {
				numPositionList[nums[i]].emplace_back(i);
			}else{
				numPositionList[nums[i]]=vector<int>{i};
			}
		}
		int result = -1;
		int tmp = 0;
		int n = nums.size();
		int maxJumpStep[N];
		memset(maxJumpStep,-1,sizeof(maxJumpStep));
		maxJumpStep[0]=0;
		for(int i=0; i<n; i++) {
			if(maxJumpStep[i]==-1) continue;
			int &pos = i;
			int &step = maxJumpStep[pos];
			long long lower = nums[pos]-(long long)target;
			long long upper = nums[pos]+(long long)target;
			for(auto &countPair:numPositionList){
				if(countPair.first > upper) break;
				if(countPair.first>=lower){
					// for(auto &nextPos: countPair.second){
					// 	if(nextPos>pos){
					// 		dfs(nextPos);
					// 	}
					// }
					auto & targetVector = countPair.second;
					auto nextPos = lower_bound(targetVector.begin(), targetVector.end(), pos+1);
					if(nextPos!=targetVector.end()){
						maxJumpStep[*nextPos] = max(maxJumpStep[*nextPos], step+1);
					}
				}

			}	
		}
		return maxJumpStep[n-1];
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<int> price ={1,3,6,4,1,2};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	cout << solution.maximumJumps(price, 2)<< endl;
}

// 为什么会超时呢？ 难道不是回溯法吗？