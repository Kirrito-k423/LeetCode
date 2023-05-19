#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> int2array(int num){
        vector<int> result;
        while(num){
            result.push_back(num%(-2));
            num /= (-2);
        }
        reverse(result.begin(), result.end());
        if(result.size()==0){return {0};}
        return result;
    }
    int arr2int(vector<int>& arr){
        int n = arr.size();
        int result = 0;
        int mult = 1;
        for(int i = 0; i < n; i++) {
            result += arr[n-1-i] * mult;
            mult *= (-2);
        }
        return result;
    }
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        return int2array(arr2int(arr1) + arr2int(arr2));
    }
};



int main(){
	Solution solution;
	vector<int> arr1 ={0};
	vector<int> arr2 ={1,1};
	solution.addNegabinary(arr1,arr2);
}