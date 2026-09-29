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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        // BFS (level-order-traversal) => add last element
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> levelItems;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* front = q.front();
                q.pop();

                levelItems.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.push_back(levelItems.back());
        }

        return res;
    }
};