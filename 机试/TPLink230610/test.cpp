#include <bits/stdc++.h>

using namespace std;

bool upList(vector<int> & nums){
    int n = nums.size();
    int flag = 0;
    for(int i = 1; i<n; i++){
        if(nums[i]>=nums[i-1])
            continue;
        flag++;
        if(i-2 < 0 || (i-2>=0 && nums[i-2]<=nums[i])){ // change the first one
            continue;
        } else if(i+1 > n-1 || (i+1 <= n-1 && nums[i-1]<=nums[i+1])){// change the second one
            continue;
        }else{
            return false;
        }
    }
    return (flag>1)?false:true;
}

int main(){
    // int a,b,c;
    // cin >> a >> b;

}