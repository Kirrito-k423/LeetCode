#include <iostream>
#include <cstring>

using namespace std;
class Solution {
public:
    bool checkSelf(string &a, int left, int right){
        while(left < right){
            if(a[left]!= a[right])
                return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
    bool check(string & a, string &b){
        int n = a.size();
        int left = 0, right = n-1;
        while(left < right && a[left]==b[right]){
            left++;
            right--;
        }
        if(left>=right){
            return true;
        }
        return checkSelf(a, left, right)||checkSelf(b, left, right);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a,b)||check(b,a);
    }
};

int main(){
    Solution A;
    string a,b;
    cin >> a;
    cin >> b;
    cout << A.checkPalindromeFormation(a,b) << endl; 
}