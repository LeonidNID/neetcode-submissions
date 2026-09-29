/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;aic.
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        
        if((p && !q || q && !p) || p->val != q->val) return false;

        while(p && q) {
            return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
        }
        return true;
    }

};
