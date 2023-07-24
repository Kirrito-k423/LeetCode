#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> primes;
bool np[N+1];
int init = [](){
	for (int i = 2; i <= N; i++)
	{
		if(!np[i]){
			primes.push_back(i);
			for (int j = i; j <= N/i; j++){
				np[i*j] = true;
			}
		}
	}
	return 0;
}();

int main(){
	//return prime[n]*k
	int n = 0;
	int k = 0;
	while(cin >> n >> k){
		long long prime_sum = 0;
		for(int i = 0; i < n; i++){
			prime_sum += primes[i];
		}
		cout << prime_sum*k << endl;

	}
}

// 看错题目了，不是两两的最大公约数，是全部的最大公约数。