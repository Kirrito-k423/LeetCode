#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define empty 'x'
int n, m;

bool check(int step){
	int a = 1;
	int i;
	for(i=1; i<=step; i++){
		a += i;
		if(a>m){
			return false;
		}
	}
	for(;i<n;i++){
		a += 1;
		if(a>m){
			return false;
		}
	}
	return true;
}

void printPass(int step){
	int a = 1;
	cout << a << " ";
	int i;
	for(i=1; i<=step; i++){
		a += i;
		cout << a << " ";
	}
	for(;i<n;i++){
		a += 1;
		cout << a << " ";
	}
}
int main() {

	cin >> n >> m;
	// b 1,2,3,... 这样 a才会上升最慢
	// 二分答案， 
	int left = 1, right = n-1;

	if(check(right)){
		printPass(right);
		return 0;
	}

	while(left + 1 < right){
		int mid = (left + right)/2;
		if(check(mid)){
			left = mid;
		}else{
			right = mid;
		}
	}
	printPass(left);

}
// 64 位输出请用 printf("%lld")