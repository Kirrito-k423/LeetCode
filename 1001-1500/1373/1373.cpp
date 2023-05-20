#include "1373.h"




int main(){
	Solution solution;
	TreeNode* node1 =new TreeNode(-2);
	TreeNode* node2 =new TreeNode(-5);
	TreeNode* node3 =new TreeNode(-4, node1, node2);
	// TreeNode* node4 =new TreeNode(1, nullptr, node3);

	cout << solution.maxSumBST(node3)<< endl;
}