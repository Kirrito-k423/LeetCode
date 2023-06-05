#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        //有相同的就可以删除
        set<char> charSet(s.begin(),s.end());
        return charSet.size();
    }
};