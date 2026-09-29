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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true; // base case
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        cout << "Checking: " << root->val << "\n";

        if(root->val == 2) {
            cout << "Left height: " << left << ", Right height: " << right << "\n";
            cout << "abs(left - right) = " << abs(left - right) << "\n";
        }
        if(abs(left - right) > 1) balanced = false;

        isBalanced(root->left);
        isBalanced(root->right);

        return balanced;
    }
    int maxHeight(TreeNode* root) { 
        if(root == nullptr) return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
};
