#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // 记录之前遍历过的负数元素
        set<int> showedMinus;
        set<int> showedPositive;
        for(auto &x :nums){
            if(x < 0){
                showedMinus.insert(x);
            }else{
                showedPositive.insert(x);
            }
        }
        if(showedPositive.size()>0)
            cout << "showing " << showedPositive.size() << endl;
            cout << *showedPositive.end() << endl;
            cout << *showedPositive.begin() << endl;
            cout << *--showedPositive.end() << endl;
            if(showedPositive.begin()==(--showedPositive.begin()))
                cout << "ops 1 " << endl;
            cout << *--showedPositive.begin() << endl;
            // if(showedPositive.begin()==showedPositive.rend())
            //     cout << "ops 2 " << endl;
            cout << *showedPositive.rend() << endl;//
            cout << *showedPositive.rbegin() << endl;
            cout << *--showedPositive.rend() << endl;
            if(showedPositive.rbegin()==(--showedPositive.rbegin()))
                cout << "ops 3 " << endl;
            if(showedPositive.rend()==(++showedPositive.rend()))
                cout << "ops 4 " << endl;
            cout << *--showedPositive.rbegin() << endl;
            cout << "ops end " << endl;
            for(set<int>::iterator it=--showedPositive.end(); it!=--showedPositive.begin(); it--){
                if(showedMinus.count(-(*it))){
                    return *it;
                }
            }
        return -1;
    }
};

int main(){
    Solution solution;
	vector<int> price ={-2,-3,-1,4};
	cout << solution.findMaxK(price)<< endl;
}