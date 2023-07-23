#include <bits/stdc++.h>

using namespace std;
const int NX = 200000;
int sum_array[NX];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		for(int i=0; i<n; i++){
			cin >> sum_array[i];
		}

		// force max
		int result = INT_MIN;
		for(int i=0; i<n; i++){
			int tmp = sum_array[i];
			sum_array[i] = x;
			for(int j=0; j<n; j++){
				int sum = 0;
				for(int k=j; k<n; k++){
					sum += sum_array[k];
					result = max(result, sum);
				}
			}
			sum_array[i] = tmp;
		}
		cout << result << endl;
	}
}