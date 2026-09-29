/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* root, long minVal, long maxVal) {
        if(!root) return true;

        if(root->val < minVal || root->val > maxVal) return false;

        long maxL = root->val - 1;
        long minR = root->val + 1;


        return valid(root->left, minVal, maxL) && valid(root->right, minR, maxVal);
    }
};
