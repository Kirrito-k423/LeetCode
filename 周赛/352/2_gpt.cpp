#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;

std::vector<int> generatePrimes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    std::vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        vector<int> primes = generatePrimes(n);

        int left = 0;
        int right = primes.size() - 1;

        while (left <= right) {
            int sum = primes[left] + primes[right];
            if (sum == n) {
                result.push_back({primes[left], primes[right]});
                ++left;
                --right;
            } else if (sum < n) {
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};


// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	solution.findPrimePairs(10);
// }