#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        //滑动窗口，加有效区间的长度
        //有效判断，维护map[值]个数
        map<int,int> count;
        int n = nums.size();
        long long result = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            // add right
            count[nums[right]]++;
            // push 2 avail
            while((*count.rbegin()).first - (*count.begin()).first > 2){
                count[nums[left]]--;
                if(count[nums[left]]==0){
                    count.erase(nums[left]);
                }
                left++;
            }
            result += right-left+1;
        }      
        return result;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }