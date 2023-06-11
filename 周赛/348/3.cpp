#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long sum0 = accumulate(nums.begin(),nums.end(),0LL);
        int n = nums.size();
        function<long long(int)> dfs = [&x, &nums,&n](int index){
            long long tmp0 = min(nums[0],nums[n-1]);
            for(int i = 0; i <n-1; i++){ //注意方向，不要覆盖了
                nums[i] = min(nums[i],nums[i+1]);
            }
            nums[n-1]=tmp0;
            return (long)index * x + accumulate(nums.begin(),nums.end(),0LL);
        };
        long long result = sum0;
        for(int i = 1; long((long)i * x) < sum0 && i < n; i++){
            result = min(result,dfs(i));
        }      
        return result;
    }
};

// 15+150+56+69+214+203 = 707
// 15+56+56+69+203+15 = 414 +42 =456
// 15+56+56+69+15+15 = 414 +42 =456