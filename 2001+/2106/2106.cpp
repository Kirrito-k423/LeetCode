#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		// result 会比左k，右k，某情况下的全部 三者都大
		// bfs 走 i 步掉头，i<k/3
		// 区间和 使用 前缀和
		int n = fruits.size();
		int beginP = (*fruits.begin())[0];
		int endP = (*(fruits.end()-1))[0];
		vector<int> amount(endP - beginP + 1, 0);
		int nS = endP - beginP + 1;
		startPos -= beginP;
		if(startPos + k < 0){
			return 0;
		}else if(startPos<0 && startPos + k >= 0){
			k += startPos;
			startPos = 0;
		}
		if(startPos - k  > nS -1){
			return 0;
		}else if(startPos> nS -1 && startPos - k <= nS -1){
			k -= (startPos-(nS - 1));
			startPos = nS - 1;
		}

		int prefixSum = 0;
		int j = 0;
		for(int i = 0; i < n; i++) {
			int stepJ = fruits[i][0] - beginP;
			int upJ = fruits[i][1];
			for(; j < stepJ; j++) {
				amount[j] = prefixSum;
			}
			prefixSum += upJ;
			amount[j] = prefixSum;
		}

		int result = INT_MIN;
		if(startPos > k){
			result = max(result, amount[startPos] - amount[startPos - k]);
		}else{
			result = max(result, amount[startPos]);
		}

		if(startPos + k <= nS - 1){
			result = max(result, amount[startPos + k] - amount[startPos]);
		}else{
			result = max(result, amount[nS - 1] - amount[startPos]);
		}

		int maxStep = min(startPos, nS -1 - startPos)+nS - 1;
		if(k >= maxStep){
			result = max(result, amount[nS - 1]);
			return result;
		}

		// bfs 走 i 步掉头，i<k/3
		for(int i = 0; i <= k/3; i++){
			int minI = max(1, startPos - i);
			int maxI = min(nS -1 , startPos + (k-2*i));
			if(startPos - i > 0)
				result = max(result, amount[maxI]-amount[minI-1]);
			else
				result = max(result, amount[maxI]);
			minI = max(1, startPos - (k - 2*i));
			maxI = min(nS -1 , startPos + i);
			if(startPos - (k - 2*i) > 0)
				result = max(result, amount[maxI]-amount[minI-1]);
			else
				result = max(result, amount[maxI]);
		}
		return result;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}} ;
	vector<vector<int>> edges = {{200000,10000}} ;
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	// vector<int> price ={2,2,10,6};
	cout << solution.maxTotalFruits( edges, 200000,10000)<< endl;
}