#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int people[n];
        memset(people, 0, sizeof(people));
        int cur=0;
        int multiple=1;
        while(people[cur]==0){
            people[cur]=1;
            cur=(cur+k*multiple)%n;
            multiple++;
        }
        vector<int> result;
        for(int i=0; i<n; i++) {
            if(people[i]==0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};