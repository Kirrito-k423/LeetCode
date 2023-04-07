#include <vector>
#include <limits.h> 
#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    long long memory[51][51];
    int subScore(int begin, int end, vector<int>& values) {
        long long ans = INT_MAX;
        int n = values.size();
        if(end == (begin+1)%n) return 0;
        for(int i = (begin + 1)%n; i != end; i=(i+1)%n) {
            memory[begin][i] = (memory[begin][i] == 0)?(subScore(begin, i, values)):(memory[begin][i]);
            memory[i][end] = (memory[i][end] == 0)?(subScore(i, end, values)):(memory[i][end]);
            long long current = 0;
            current += values[i] *  values[begin] * values[end];
            current += memory[begin][i] + memory[i][end];
            ans = min(ans, current);
        }
        return (int)ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        long long ans = INT_MAX;
        int n = values.size();
        memset(memory, 0, sizeof(memory));
        for(int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    memory[i][j] = (memory[i][j] == 0)?(subScore(i, j, values)):(memory[i][j]);
                    memory[j][k] = (memory[j][k] == 0)?(subScore(j, k, values)):(memory[j][k]);
                    memory[k][i] = (memory[k][i] == 0)?(subScore(k, i, values)):(memory[k][i]);
                    long long current = 0;
                    current += values[i] * values[j] * values[k];
                    current += memory[i][j] + memory[j][k] + memory[k][i];
                    ans = min(ans,current);
                }
            }
            
        }
        return (int)ans;
    }
};

int main(){
    Solution s;
    vector<int> values = {1,2,3};
    cout << s.minScoreTriangulation(values) << endl;
}