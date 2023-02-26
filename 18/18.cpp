
#include "../tsjCommonFunc.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4 || nums.empty())
        {
            return result;
        }
        std::sort(nums.begin(),nums.end());

        auto i = nums.begin();
        if(*i > target && (*i >=0 || target >= 0)){
            return result;
        }

        for(i=nums.begin() ; i<nums.end()-3; i++){
            if(distance(nums.begin(),i)>0&&*i==*(i-1))//重复的数不重复// 问题在这里 i=0解引用出错
            {
                continue;
            }
            for(auto j=nums.end() ; j>i+2; j--){
                if(distance(j,nums.end())>0&&*j==*(j+1))
                {
                    continue;
                }
                vector<int>::iterator left = i+1;
                vector<int>::iterator right = j-1;
                while (left<right)
                {
                    if(*i+*left+*right+*j==target)
                    {
                        // result.clear();
                        // result.push_back(*i);
                        // result.push_back(*left);
                        // result.push_back(*right);
                        cout << *i << *left << *right << *j << endl;
                        result.push_back({*i,*left,*right,*j});
                        left++;
                        right--;
                        while(*right==*(right+1) && left<right)
                        {
                            right--;
                        }
                        while(*left==*(left-1) && left<right)
                        {
                            left++;
                        }
                    }
                    else if(*i+*left+*right+*j>target)
                    {
                        right--;
                    }
                    else if(*i+*left+*right+*j<target)
                    {
                        left++;
                    }
                }
            }
        }
        cout << "OK" << endl;
        return result;
    }
};

int main(){
	Solution Solution;
    // string input1();
    vector<int> input1 = {0,0,0,0};
	Solution.fourSum(input1,0);
}
