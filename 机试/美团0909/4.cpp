#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define empty 'x'
int main() {
    int n, m;
	cin >> n >> m;
	// b 1,2,3,... 这样 a才会上升最慢
	int a = 1;
	int i;
	for(i=1; i<n; i++){
		a += i;
		if(a > m){
			break;
		}
	}
	if(a<=m){
		a = 1;
		cout << a << " ";
		for(int j=1; j<n; j++){
			a += j;
			cout << a << " ";
		}
	}else{
		int lasta = a - i;
		int rest_element = n - i;
		int left_space = m - lasta;
		// cout << rest_element << " " << left_space;
		if(rest_element <= left_space ){
			a = 1;
			cout << a << " ";
			int j;
			for(j=1; j<i; j++){
				a += j;
				cout << a << " ";
			}
			for(;j<n;j++){
				a += 1;
				cout << a << " ";
			}
		}else{
		
		}
	}
	//

}
// 64 位输出请用 printf("%lld")