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
    int maxD = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameter(root);
        return maxD;
    }

    int diameter(TreeNode* root) {
        if(!root) return 0;

        int heightL = diameter(root->left);
        int heightR = diameter(root->right);

        int diameter = heightL + heightR;
        if(diameter > maxD) maxD = diameter;

        return 1 + max(heightL, heightR); 
    }

};

/*
What is the difference to getting the height (1 + max(HeightL, HeightR))?
-> height is from root down (most levels)
-> diameter could be between any 2 points, e.g. check
     1
   /   \
  2     4  
 /       \
3         5

How to get 4 here?

1) For every node add together right height + left height (diameter)
2) If the CURRENT node has leftHeight + rightHeight > prev max (var tracked) then update

int diameter(TreeNode* root) {
    if(!root) return 0;

    int heightL = diameter(root->left);
    int heightR = diameter(root->right);

    int diameter = heightL + heightR;
    if(diameter > res) res = diameter;

    return 1 + max(heightL, heightR); 
}













*/
