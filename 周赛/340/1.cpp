#include <vector>

using namespace std;
class Solution {
public:
    bool isZhiNum(int value){
        for(int i=2; i<value/2; i++){
            if(value%i==0){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(isZhiNum(nums[i][i]))
                ans = max(ans,nums[i][i]);
            if(isZhiNum(nums[i][n-1-i]))
                ans = max(ans,nums[i][n-1-i]); 
        }
        return ans;
    }
};

//质数求解超时