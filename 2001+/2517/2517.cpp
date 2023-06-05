#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        //最小最大，二分答案
        sort(price.begin(),price.end());
        int left = 0; 
        int right = (*price.rbegin()-*price.begin())/(k-1);

        function<int(int)> availableNum = [&](int gap){
            int count = 0;
            auto it = price.begin();
            while(it!=price.end()){
                count++;
                auto it2 = lower_bound(it, price.end(), *it + gap);   
                it = it2;            
            }
            return count;
        };
        if(right==0) return 0;
        if(availableNum(right)>=k) return right;
        while(left + 1 < right){
            int mid = (left) + (right-left)/2;
            int tmp = availableNum(mid);
            if(tmp>=k){
                left = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }
};


int main(){
	Solution solution;
	// vector<vector<int>> edges = {{0,1},{1,2},{1,3}} ;
	// vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
	vector<int> price ={13,5,1,8,21,2};
	cout << solution.maximumTastiness(price, 3)<< endl;
}