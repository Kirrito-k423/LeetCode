#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkUnionK(vector<int>& tryNums, int k){
        int n=tryNums.size();
        if(n==0) return false;
        if(n==1) return true;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(tryNums[i]-tryNums[j])==k)
                    return false;
            }
        }
        return true;

    }
    void checkSub(vector<int>& tryNums, int i, int & result, vector<int>& nums, int k){
        int n=nums.size();
        if(i==n) {
            if(checkUnionK(tryNums, k)){
                result++;
            }
            return;
        }
        checkSub(tryNums, i+1, result, nums, k);
        tryNums.push_back(nums[i]);
        checkSub(tryNums, i+1, result, nums, k);
        tryNums.pop_back();
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> tryNums;
        int result=0;
        checkSub(tryNums, 0, result, nums, k);
        return result;
    }
};

int main(){
    Solution A;
    vector<int> grid = {295,294,291};
    cout << A.beautifulSubsets(grid, 52) << endl;
}