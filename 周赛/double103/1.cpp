#include <vector>

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        return (maxVal + (maxVal + k - 1))*k/2;
    }
};