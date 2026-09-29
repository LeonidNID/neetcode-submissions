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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int> values(10001, 0); // O(1) addressing
        dfs(root, values);

        int counter = k;
        for(int i = 0; i <= 10000; i++) {
            if(values[i] > 0) {
                if(counter == 1) {
                    return i;
                } else {
                    counter--;
                }
            }
        }
        return -1;
    }

    void dfs(TreeNode* root, vector<int>& values) { // O(n)
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(!s.empty() || cur) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* node = s.top();
            s.pop();
            values[node->val]++; // Track element occuring

            cur = node->right;
        }
    }
};
