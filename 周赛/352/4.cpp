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
    int sumImbalanceNumbers(vector<int>& nums) {
        //1 <= nums[i] <= nums.length
        // 计数排序的 组合数
        int result = 0;
        int n = nums.size();
        for(int left=0; left<n-1; left++){
            set<int> count;
            int pre = 0;
            for(int right=left; right<n; right++){
                //add new
                if(count.count(nums[right])){
                    result += pre;
                    continue;
                }else{
                    count.insert(nums[right]);
                }
                
                //count add
                pre = 0;
                auto it = count.begin();
                while((next(it,1))!=count.end()){
                    if(*next(it,1)-*it > 1){
                        pre++;
                    }
                    it++;
                }
                result += pre;

            }
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