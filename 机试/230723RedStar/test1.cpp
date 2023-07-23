#include <bits/stdc++.h>

using namespace std;

void main(){
	int n, m;
	while(cin >> n >> m) {
		int sum = 0;
		for(int i = 0; i <m; i++){
			sum += n;
			n = sqrt(n);
		}
		cout << sum << endl;
	}
	return 0;
}