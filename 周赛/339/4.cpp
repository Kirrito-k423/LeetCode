#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        //边界
        vector<int> ans(n,-1);
        unordered_set<int> bannedSet(banned.begin(),banned.end());
        unordered_set<int> sets;
        for (int i = 0; i < n; ++i)
            if (i != p && !bannedSet.count(i))
                sets.insert(i);
        ans[p]=0;
        //从p开始 BFS 遍历 +-(k-1)
        queue<int> q;
        queue<int> tmp;
        q.push(p);
        int depth=1;
        while(!q.empty()){
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                //反转起始j
                for(int j=max(0,cur-(k-1));j<min(cur+1,n-(k-1)) ;j++){
                    int turnOverI = (j+k-1-cur)+j;
                    if(sets.count(turnOverI)){
                        sets.erase(turnOverI);
                        ans[turnOverI]=depth;
                        tmp.push(turnOverI);
                    }
                }
            }
            swap(q,tmp);
            depth++;
        }
        return ans;
    }
};