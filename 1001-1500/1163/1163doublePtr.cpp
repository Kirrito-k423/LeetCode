#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
// const int N=1E5+10,M=210;


class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while(j<n){
            int k = 0;
            while(j + k < n && s[j + k]==s[i+k]) {
                k++;
            }
            if(j + k < n && s[j + k]>s[i + k]){
                int tmp = i;
                i = j;
                j = max(j+1,tmp+k+1);
            }else{
                j = j +k + 1;
            }
        }
        return s.substr(i,n-i);
    }
};




//难点在于：和前面匹配时，需要多个匹配，然后取最前的。
//超时：优先队列？ substr？
// int main(){
// 	Solution solution;
// 	string s = "cacacb";
// 	// string s = "leetcode";
// 	cout << solution.lastSubstring(s)<< endl;
// }