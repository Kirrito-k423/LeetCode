// /**
//  * Definition for a binary tree node.
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cstring> // memset
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <iostream> // std::cout endl
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





struct dpData{
    int min;
    int max;
    int curDelta;
};
class Solution {
public:
	dpData subTree(TreeNode *root){
		int maxDelta = 0;
        int curVal = root->val;
		int curMax = curVal;
		int curMin = curVal;
        if(root->left){
            dpData leftData = subTree(root->left);
			curMax = max(curMax,leftData.max);
			curMin = min(curMin,leftData.min);
			maxDelta = max(leftData.curDelta,maxDelta);
        }
         if(root->right){
            dpData rightData = subTree(root->right);
			curMax = max(curMax, rightData.max);
			curMin = min(curMin, rightData.min);
			maxDelta = max(rightData.curDelta,maxDelta);
        }
		int tmp = max(abs(curVal - curMax),abs(curVal - curMin));
		maxDelta = max(maxDelta,tmp);
		dpData returnData;
		returnData.min = curMin;
		returnData.max = curMax;
		returnData.curDelta = maxDelta;
        return returnData;
	}
    int maxAncestorDiff(TreeNode* root) {
        return subTree(root).curDelta;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	// vector<int> price ={2,2,10,6};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	TreeNode* c1 = new TreeNode(1);
	TreeNode* root = new TreeNode(8,c1,nullptr);
	cout << solution.maxAncestorDiff(root)<< endl;
}
