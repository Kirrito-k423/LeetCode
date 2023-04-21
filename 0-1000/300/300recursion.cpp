
#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;



// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //递推
        int n = nums.size();
        vector<int> f(n,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) 
                    f[i] = max(f[i],f[j]);
            }
            f[i] += 1;
        }
        return *max_element(f.begin(),f.end());
    }
};