

#include "../tsjCommonFunc.h"
using namespace std;

class Solution {
public:
    void combinationIteration(vector<vector<int>> &result, vector<int> &tmp, int begin, int k, int n){
        if(k<=0||n<=0){
            if(n==0){
                result.push_back(tmp);   
            }
            return;
        }   
        int end = min(n,9);
        for(int i=begin+1; i<=end; i++ ){
            tmp.push_back(i);
            cout << "k n i "<< k << " "<< n << " "<< i << " "<< endl;
            combinationIteration(result, tmp, i, k-1, n-i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        //从小到大遍历，
        //剪枝：
        int end = min(n,9);
        for(int i=1;  i<=end; i++){
            cout << "1k n i "<< k << " "<< n << " "<< i << " "<< endl;
            tmp.push_back(i);
            cout << " k n i "<< k << " "<< n << " "<< i << " "<< endl;
            combinationIteration(result, tmp, i, k-1, n-i);
            tmp.pop_back();
        }
        return result;
    }
};


int main(){
	Solution Solution;
    // string input1();
    // vector<int> input1 = {0,0,0,0};
    // TreeNode* right = new TreeNode(20, new TreeNode(15),new TreeNode(7));
    // TreeNode* root = new TreeNode(3,new TreeNode(9),right);
	Solution.combinationSum3(3, 7);
}