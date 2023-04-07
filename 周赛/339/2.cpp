#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        unordered_map<int,int> countNum;
        int n = nums.size();
        int ansNum = 0;
        for(auto & num : nums){
            countNum[num]++;
            ansNum = max(ansNum,countNum[num]);
        }
        vector<vector<int>> ans(ansNum,vector<int>(0));
        for(auto it = countNum.begin(); it!= countNum.end(); ++it){
            int num = it->first;
            int count = it->second;
            int row = 0;
            while(count > 0){
                ans[row].push_back(num);
                count--;
                row++;
            }
        }
        return ans;
    }
};