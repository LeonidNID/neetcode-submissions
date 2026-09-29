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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // search p and q from root
        vector<TreeNode*> pathP = searchNode(root, p->val); // [5, 3, 1, 2]
        vector<TreeNode*> pathQ = searchNode(root, q->val); // [5, 8]

        vector<TreeNode*> big;
        vector<TreeNode*> small;
        if(pathP.size() >= pathQ.size()) {
            big = pathP;
            small = pathQ;
        } else {
            big = pathQ;
            small = pathP;            
        }

        for(int i = small.size() - 1; i >= 0; i--) {
            if(find(big.begin(), big.end(), small[i]) != big.end()) return small[i];
        }

        return nullptr;
    }

    vector<TreeNode*> searchNode(TreeNode* root, int target) {
        if(root == nullptr) return {};
        vector<TreeNode*> path;

        // search using BST property
        TreeNode* cur = root;
        while(cur) {
            path.push_back(cur); // Store Node Pointers because that's what we return
            if(target < cur->val) {
                cur = cur->left;
            } else if (target > cur->val) {
                cur = cur->right;
            } else {
                break; // Found
            }
        }

        return path;
    }
};


/*
Inorder traversal: 2,1,3,4,5,7,8,9

2 and 3:

5 -> 3 -> 1 -> 2
5 -> 3
*/