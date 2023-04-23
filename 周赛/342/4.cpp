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
    int minOperations(vector<int>& nums) {
		//暴力最短序列
		//Step 1: 如果有1
		int n = nums.size();
		vector<int> judgeOne(nums.begin(),nums.end());
		sort(judgeOne.begin(),judgeOne.end());
		auto minValue = upper_bound(judgeOne.begin(), judgeOne.end(),1);
		if(minValue - judgeOne.begin()) 
			return n - (minValue - judgeOne.begin());

		//Step 2: 暴力区间
		int shortestGcdList = INT_MAX;
		for(int i=0; i<n-1; i++){
			//i 开始， 长度为j+1
			//判断[i,j]区间内多个元素的最大公约数 是否为 1
			//由于传递性，可以一个一个求。 见多个数的最大公约数：https://oi-wiki.org/math/number-theory/gcd
			int gcdResult = nums[i];
			for(int j=1; i+j<n; j++){
				gcdResult = __gcd(gcdResult,nums[i+j]);
				if(gcdResult==1){
					shortestGcdList = min(shortestGcdList,j+1);
					break;
				}
			}
		}
		if(shortestGcdList == INT_MAX)
			return -1;
		else{
			return n - 1 + (shortestGcdList-1);
		}
    }
};

// int main(){
// 	Solution solution;

// 	vector<int> price ={6,10,15};

// 	cout << solution.minOperations(price)<< endl;
// }

//垃圾思路

// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
// 		//分情况讨论
// 		//Step 1: 如果有1
// 		int n = nums.size();
// 		vector<int> judgeOne(nums.begin(),nums.end());
// 		sort(judgeOne.begin(),judgeOne.end());
// 		auto minValue = upper_bound(judgeOne.begin(), judgeOne.end(),1);
// 		if(minValue - judgeOne.begin()) 
// 			return n - (minValue - judgeOne.begin());

// 		//Step 2: 任意相邻gcd为1，答案为n
// 		for(int i=0; i<n-1; i++){
// 			if(gcd(nums[i],nums[i+1])==1)
// 				return n;
// 		}
// 		return 
//     }
// };
