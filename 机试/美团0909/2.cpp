#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp;
	cin >> n;
	vector<int> a(n);
	int i = 0;
	while(cin >> tmp){
		a[i++]=tmp;
	}
	// 前缀和 大于等于当前值的情况下，而且当前最大即为选择A。
	// answer 为 sum - 2A
	long long  preSum = a[0];
	int chooseBig = -1;
	for(i=1; i<n; i++){
		if(preSum >= a[i]){
			if(a[i] > chooseBig){
				chooseBig = a[i];
			}
		}
		preSum += a[i];
	}
	if(chooseBig == -1){
		cout << "-1" << endl;
	}else{
		cout << preSum-2*chooseBig << endl;
	}
}
// 64 位输出请用 printf("%lld")