#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        int result = 0;
        int beginN = stoi(num1);
        int endN = stoi(num2);

        function<int(int)> iSum = [](int target){
            int sum = 0;
            int tenth = 1;
            while(target>0){
                sum += (target % 10);
                target = target/10;
            }
            return sum;
        };

        for(int i=beginN; i<=endN; i++){
            int sum = iSum(i);
            if((sum >= min_sum) && (sum <= max_sum)){
                result = (result+1) % MOD;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "1000000007";
    string num2 = "2000000014";
    int min_sum = 1;
    int max_sum = 400;

    int result = solution.count(num1, num2, min_sum, max_sum);
    cout << result << endl;

    return 0;
}