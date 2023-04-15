#include <vector>

using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result;
        long long maxPrefixI = INT_MIN;
        long long prefixSum = 0;
        for(auto &num : nums){
            maxPrefixI = max(maxPrefixI,(long long)num);
            result.push_back(prefixSum + num+maxPrefixI);
            prefixSum += num+maxPrefixI;
        }
        return result;
    }
};