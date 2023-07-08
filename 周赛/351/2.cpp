#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
private:
    long long countSetBits(long long num) {
        long long count = 0;
        unsigned long long mask = 1;
        int moveCount = 0;
        while (num != 0) {
            if (num & mask) {
                if(moveCount<=60)
                    count++;
                else{
                    count += pow(2,(moveCount-60));
                }
            }
            moveCount++;
            num >>= 1;
        }

        return count;
    }

public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2+1 > num1) return -1;     
        int result = 0;
        long long tmp = num1;
        while(tmp > 0 && (countSetBits(tmp)>result
                || tmp < result)
            ) {
            tmp -= num2;
            // cout << __builtin_popcount(tmp) << endl;
            result++;
        }
        if(tmp <= 0) return -1;
        return result;
    }
};


// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }