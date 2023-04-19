#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
// const int N=1E5+10,M=210;


int main(){
	int cnt;
	// int answer = 0;
	vector<int> inputList;
	while(cin >> cnt) {
		inputList.push_back(cnt);
	}
	inputList.erase(inputList.end()-1);//去除最后一个元素
	// int n = inputList.size();
	long long sum = accumulate(inputList.begin(), inputList.end(),0LL);
	if(sum <= cnt) {cout << "-1";return 0;}
	int maxR = *max_element(inputList.begin(), inputList.end());
	int left = 0, right = maxR;
	while(left + 1 < right) { 
		//由于无论是从left，right相差1、2、3、……开始
		//最终都会经过 left+1=right的阶段
		int mid = left + (right-left)/2;
		long long tmpCntSum = 0;
		for(auto &x: inputList){
			tmpCntSum += (x>mid)? mid : x;
		}
		if(tmpCntSum <= cnt){
			left = mid; // break left 满足 其tmpCntSum <= cnt
		}else{
			right = mid; // break right 满足 其tmpCntSum > cnt
		}
	}
	//求 满足求和小于cnt 的最大值：left
	cout << left << endl;


	// cout << answer << endl;
}