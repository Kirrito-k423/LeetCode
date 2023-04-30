#include <bits/stdc++.h>

using namespace std;

#define mnMax 100000
int mCount[mnMax];
int nCount[mnMax];

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        memset(mCount, 0, sizeof(mCount));
        memset(nCount, 0, sizeof(nCount));
		int m = mat.size();
		int n = mat[0].size();
		pair<int,int> *val2mn = (pair<int,int>*) malloc((1LL*m*n+1)*sizeof(pair<int,int>));
        // memset(val2mn, 0, 1LL*mnMax*mnMax*sizeof(pair<int,int>));
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				val2mn[mat[i][j]]=make_pair(i,j);
			}
		}
		for(int i = 0; i < m*n; i++){
			mCount[val2mn[arr[i]].first]++;
			nCount[val2mn[arr[i]].second]++;
			if(mCount[val2mn[arr[i]].first] == n){
				return i;
			}
			if(nCount[val2mn[arr[i]].second] == m){
				return i;
			}
		}
		free(val2mn);
		return -1;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> edges = {{{1,4},{2,3}}} ;
	vector<int> price ={1,3,4,2};
	cout << solution.firstCompleteIndex(price, edges)<< endl;
}
