#include <bits/stdc++.h>
#include "default.h"
using namespace std;


struct dfsReturn{
    bool isAnswerSubTree;
    int subTreeSum;
    int maxSub;
    int minSub;
    dfsReturn(){isAnswerSubTree=true; subTreeSum=0; maxSub=INT_MIN;
                minSub=INT_MAX;};
    dfsReturn(bool isAnswerSubTree, int subTreeSum): isAnswerSubTree(isAnswerSubTree),subTreeSum(subTreeSum){};
};  

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int result = INT_MIN;
        function<dfsReturn(TreeNode*)> dfs = [&dfs,&result](TreeNode* node){ // return k > 0 if nodeK is answer tree
            //return 0 if nodeK is not answer
            dfsReturn rightSubTree = dfsReturn(); // 
            dfsReturn leftSubTree = dfsReturn();
            if(node->right!=nullptr){
                rightSubTree = dfs(node->right);
            }
            if(node->left!=nullptr){
                leftSubTree = dfs(node->left);
            }
            dfsReturn curNode = dfsReturn();
            bool isCurAnswer = rightSubTree.isAnswerSubTree && leftSubTree.isAnswerSubTree;
            if(isCurAnswer){
                bool leftOrder = (node->left!=nullptr)?((node->val > leftSubTree.maxSub)?1:0):1;
                bool rightOrder = (node->right!=nullptr)?((node->val < rightSubTree.minSub)?1:0):1;
                isCurAnswer = isCurAnswer && leftOrder && rightOrder;
            }
            curNode.isAnswerSubTree = isCurAnswer;
            if(isCurAnswer){
                int tmp = node->val + rightSubTree.subTreeSum + leftSubTree.subTreeSum;
                result = max(result,tmp);
                curNode.subTreeSum = tmp;
                curNode.minSub = (node->left!=nullptr)?(leftSubTree.minSub):node->val;
                curNode.maxSub = (node->right!=nullptr)?(rightSubTree.maxSub):node->val;
            }
            return curNode;

        };
        dfs(root);
        return max(0,result);
    }
};