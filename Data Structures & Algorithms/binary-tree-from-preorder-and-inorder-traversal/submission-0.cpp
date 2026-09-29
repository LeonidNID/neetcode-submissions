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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode{preorder[0]};
        int midIdx = 0;
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        if(it != inorder.end()) {
            midIdx = it - inorder.begin();
        }

        // Recursively create left Subtree
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + midIdx + 1);
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + midIdx);
        root->left = buildTree(preorderLeft, inorderLeft);

        // Recursively create right Subtree
        vector<int> preorderRight(preorder.begin() + midIdx + 1, preorder.end());
        vector<int> inorderRight(inorder.begin() + midIdx + 1, inorder.end());
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};





















/*

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode{preorder[0]};
        int midIdx = 0;
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        if(it != inorder.end()) {
            midIdx = *it;
        }

        // Recursively create left Subtree
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + midIdx + 1);
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + midIdx);
        root->left = buildTree(preorderLeft, inorderLeft);

        // Recursively create right Subtree
        vector<int> preorderRight(preorder.begin() + midIdx + 1, preorder.end());
        vector<int> inorderRight(inorder.begin() + midIdx + 1, inorder.end());
        root->left = buildTree(preorderRight, inorderRight);

        return root;
    }
};
*/
