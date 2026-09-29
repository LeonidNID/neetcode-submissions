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
    int goodNodes(TreeNode* root) {
        return bfs(root);
    }

int bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, -100});
        int res = 0;
        
        while(!q.empty()) {
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first; 
                int maxParentVal = q.front().second; q.pop();

                if(node->val >= maxParentVal) res++;

                int newMaxParentVal = max(maxParentVal, node->val);

                if(node->left) q.push({node->left, newMaxParentVal});
                if(node->right) q.push({node->right, newMaxParentVal}); 
            }

        }

        return res;
    }
    
};

/*
n <= 1e5

        3X
      /   \
     1     4X
    /     / \   
   3     1   5X



int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        int maxParentElement = root->val;
        int newMaxElement = root->val;
        
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); q.pop();

                if(node->val >= maxParentElement) res++;

                newMaxElement = max(maxParentElement, node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }

            maxParentElement = newMaxElement;

        }

        return res;
    }
*/