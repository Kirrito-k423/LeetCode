#include <vector>
using namespace std;
#include <algorithm>
#include <queue>
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int,vector<int>,greater<int> >q;
        int n = reward1.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            q.push(reward1[i]-reward2[i]);
            if(q.size()>k){
                q.pop();
            }
            ans += reward2[i];
        }
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};