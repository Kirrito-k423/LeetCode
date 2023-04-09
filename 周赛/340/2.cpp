#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
		//值map对应的index vector
		unordered_map<int, vector<int>> valueMap;
		vector<long long> answer(n);
		for(int i=0; i<n; i++){
			valueMap[nums[i]].push_back(i);
		}
		for(int i=0; i<n; i++){
			for(auto &x:valueMap[nums[i]]){
				answer[i] += abs(x-i);
			}
		}
		return answer;
    }
};

//暴力超时， 这种绝对值的处理有好几题了