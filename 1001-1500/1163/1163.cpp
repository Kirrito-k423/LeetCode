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
    void clear(priority_queue<int,vector<int>,greater<int>> &q) {
        priority_queue<int,vector<int>,greater<int>> empty;
        swap(empty,q);
    }
    string lastSubstring(string s) {
        string result;
        string candidate;
        // int resultPrt=0;
        priority_queue<int,vector<int>,greater<int>> resultPrtList;
        priority_queue<int,vector<int>,greater<int>> tmpResultPrt;
        int N = s.length();
        for(int i=0; i<N; i++) {
            if(result.length()){
                int flag = 1;
                resultPrtList.push(0);
                while(!resultPrtList.empty()) {
                    int resultPrt = resultPrtList.top();
                    resultPrtList.pop();
                    if(s[i]>result[resultPrt]){
                        //bigger to replace
                        result[resultPrt]=s[i];
                        result=result.substr(0,resultPrt+1);
                        clear(resultPrtList);
                        flag = 0;
                        break;
                    }else if(s[i]==result[resultPrt]){
                        //wait bigger to replace
                        tmpResultPrt.push(++resultPrt);
                    }
                }
                if(flag)
                    result.push_back(s[i]);
                swap(resultPrtList,tmpResultPrt);
                if(result.size()>1 && s[i]==result[0]){
                    //wait bigger to replace
                    resultPrtList.push(1);
                }
            }else{
                result.push_back(s[i]);
            }
        }
        return result;

    }
};

//难点在于：和前面匹配时，需要多个匹配，然后取最前的。
//超时：优先队列？ substr？
// int main(){
// 	Solution solution;
// 	// string s = "cacacb";
// 	string s = "leetcode";
// 	cout << solution.lastSubstring(s)<< endl;
// }