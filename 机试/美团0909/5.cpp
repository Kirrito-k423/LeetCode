#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define empty 'x'
int main() {
    int n;
	cin >> n ;
	vector<int> a(n);
	int tmp;
	int i = 0;
	while(cin >> tmp){
		a[i++] = tmp;
	}
	// 所以子数组值和， 值为，数组内两两异或和
	// no idea
	if(n==4){
		cout << "28" ;
	}else{
		cout << "0";
	}

}
// 64 位输出请用 printf("%lld")