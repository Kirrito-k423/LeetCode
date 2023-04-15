// /**
//  * Definition for a binary tree node.

#include <queue>
#include <map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        //BFS , 每层的节点记录同父亲的节点

        queue<TreeNode*> Queue;
        queue<TreeNode*> tmpQueue;

        Queue.push(root);
        root->val =0;
        while (!Queue.empty()) {
            map<TreeNode*,long long> fatherNode;
            map<TreeNode*,TreeNode*> father;
            vector<TreeNode*> update;
            long long totalSum = 0;
            while (!Queue.empty()) 
            {
                TreeNode* cur = Queue.front();
                Queue.pop();
                if(cur->left){
                    fatherNode[cur] += cur->left->val;
                    father[cur->left]=cur;
                    totalSum += cur->left->val;
                    tmpQueue.push(cur->left);
                    update.push_back(cur->left);
                }
                if(cur->right){
                    fatherNode[cur] += cur->right->val;
                    father[cur->right]=cur;

                    totalSum += cur->right->val;
                    update.push_back(cur->right);
                    tmpQueue.push(cur->right);
                }
            }
            for(auto & up:update){
                up->val = totalSum - fatherNode[father[up]];
            }
            swap(Queue, tmpQueue);
        }
        return root;
    }
};