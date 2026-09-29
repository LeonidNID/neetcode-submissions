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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        std::stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            std::swap(top->left, top->right);
            if(top->left) s.push(top->left);
            if(top->right) s.push(top->right);
        }

        return root;
    }
};
