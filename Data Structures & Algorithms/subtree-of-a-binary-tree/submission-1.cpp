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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        return stringFlat(root).find(stringFlat(subRoot)) != string::npos;
    }

    std::string stringFlat(TreeNode* root) {
        std::string res = "";
        if(!root) return res;
        // Iterative traversal appending to res string
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if(node->left) s.push(node->left);
            res.push_back(node->val + '0');

            if(node->right) s.push(node->right);
        }
        res += "\n";
        cout << "Returning res = " << res << "\n";

        return res;
    }

};
