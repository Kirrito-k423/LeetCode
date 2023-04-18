#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ansRow = 0;
		int ansCount = 0;
		int m = mat.size();
		int n = mat[0].size();
		for(int i=0; i<m; i++) {
			vector<int> &line = mat[i];
			int tmp = 0;
			for(auto & x: line) {
				if(x==1){
					tmp++;
				}
			}
			if(tmp>ansCount){
				ansCount=tmp;
				ansRow=i;
			}
		}
		vector<int> ans;
		ans.push_back(ansRow);
		ans.push_back(ansCount);
		return ans;
    }
};