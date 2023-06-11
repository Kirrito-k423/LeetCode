#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> SetNum(nums.begin(),nums.end());
        if(SetNum.size()<=2){
            return -1;
        }else{
            auto it = SetNum.begin();
            it++;
            return *it;
        }
    }
};