#include <bits/stdc++.h>

using namespace std;


//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode * left;
      TreeNode * right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
  };
//  */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
		// dfs 参数 (已有路径和) 如果叶节点大于limit返回true，
		// 中间节点的子节点返回false则删除该子节点。都返回flase，则返回false
		// root 节点也返回false 则 return nullptr

		function<bool(TreeNode*, int)> dfs = [&dfs, &limit](TreeNode * cur, int sum){
			if(cur->left == nullptr && cur->right == nullptr){
				if(sum + cur->val >= limit) return true;
				else return false;
			}
			bool leftBool = false;
			bool rightBool = false;
			if(cur->left != nullptr){
				leftBool = dfs(cur->left, sum + cur->val);
				if(!leftBool) cur->left=nullptr;
			}
			if(cur->right != nullptr){
				rightBool = dfs(cur->right, sum + cur->val);
				if(!rightBool) cur->right=nullptr;
			}
			if(leftBool == false && rightBool == false){
				return false;
			}
			return true;
		};
		if(dfs(root,0)){
			return root;
		}else{
			return nullptr;
		}
    }
};