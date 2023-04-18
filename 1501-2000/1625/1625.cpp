#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        //累加 -> A = A%(min(a,10-a))
        int mod = (min(a,10-a));
        //1==a%n || 1==n%a 
        int n=s.size();
        if(1==b%n || 1==b%a ){
            //偶数元素也能减小
            for(int i=1; i<n; i+=2){
                int p=n-1-i;
                s[p] = '0' + (s[p]-'0')%mod;
            }
        }
        //奇数元素减小
        for(int i=0; i<n; i+=2){
            int p=n-1-i;
            s[p] = '0' + (s[p]-'0')%mod;
        }
        string result = s;
        s = s + s;
        //轮转
        vector<int> vis(n);
        for(int i=0; vis[i]==0; i=(i+b)%n){
            vis[i]=1;
            string t = s.substr(i,n);
            result = min(result,t);
        }
        return result;
    }
};

int main(){
    Solution A;
    string S;
    int a,b;
    cin >> S;
    cin >> a;
    cin >> b;
    A.findLexSmallestString(S,a,b);

}