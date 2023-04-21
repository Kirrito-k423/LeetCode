
#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //递推
        int n = nums.size();
        vector<int> f(n,0);
        vector<int> aux(n,INT_MAX);
        for(int i=0; i<n; i++) {
            vector<int>::iterator it = lower_bound(aux.begin(),aux.end(),nums[i]);
            if(it != aux.begin()) {
                f[i]=(it)-aux.begin();
                *it = nums[i];
            }else{
                *it = min(*it,nums[i]);
            }
            f[i] += 1;
        }
        return *max_element(f.begin(),f.end());
    }
};

int main(){
	Solution solution;
	vector<int> price ={10,9,2,5,3,7,101,18};
	cout << solution.lengthOfLIS(price)<< endl;
}