#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findIndex(vector<int>& nums, int x){
        int l = 0, r = nums.size() - 1;
        while(l + 1< r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == x) return mid;
            if(nums[mid] > x) r = mid;
            else l = mid;
        }
        return r;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> queriesI(n);
        //统计第一个点
        long long sum_min = 0;
        for(int i = 1; i < n; ++i) {
            sum_min += nums[i] - nums[0];
        }
        //统计每个点的
        queriesI[0] = sum_min;
        for(int i = 1; i < n; ++i) {
            int plus = nums[i] - nums[i-1];
            sum_min += (i)*plus - (n-i)*plus;
            queriesI[i] = sum_min;
        }
        
        //op1： 存储查询过的
        unordered_map<int, long long> check;
        for(auto &x:queries){
            if(check.count(x)){
                ans.push_back(check[x]);
            }else{
                //查找x的位置
                long long tmp = 0;
                if(x<=nums[0]){
                    tmp = queriesI[0] + (nums[0]-x)*n;
                }else if(x>=nums[n-1]){
                    tmp = queriesI[n-1] + (x-nums[n-1])*n;
                }else{
                    //中间
                    //首先找到位于那两个index之间,<=index
                    int index = findIndex(nums,x);
                    tmp = queriesI[index] 
                        +(nums[index]-x)*(n-index) 
                        -(x-nums[index-1])*index;
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main(){
    Solution A;
    vector<int> grid = {3,1,6,8};
    vector<int> grid1 = {5};
    cout << A.minOperations(grid,grid1)[0] << endl;
}