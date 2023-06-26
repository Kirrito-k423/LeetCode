#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
private:
    int frontF(int num){
        while(num>=10){
            num = num/10;
        }
        return num;
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(auto i = 0; i<n ; i++){
            int front = frontF(nums[i]);
            for(auto j = i+1; j<n; j++){
                int back = nums[j]%10;
                if(gcd(front,back)==1){
                    // printf("%d %d\n",front,back);
                    result++;
                }
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