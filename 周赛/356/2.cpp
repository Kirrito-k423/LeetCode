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
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique_set(nums.begin(),nums.end());
        int unique_num = unique_set.size();
        int left=0, right=0;
        int ans = 0;
        unordered_map<int,int> count_sub_array;
        for(; right < nums.size(); right++){
            count_sub_array[nums[right]]++;
            while(count_sub_array.size()==unique_num){
                count_sub_array[nums[left]]--;
                if(count_sub_array[nums[left++]]==0){
                    count_sub_array.erase(nums[left-1]);
                }
            }
            ans += left;
        }
        return ans;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }