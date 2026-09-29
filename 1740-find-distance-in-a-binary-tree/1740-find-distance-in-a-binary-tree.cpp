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
    int d(TreeNode* root1 , int val) {
        if(!root1) return -1;
        if(root1->val == val) return 0;

        int left = d(root1->left , val);
        int right = d(root1->right , val);

        if(left == -1 && right == -1) return -1;

        if(left == -1) return right+1;
        return left+1;
    }
    TreeNode* fca(TreeNode* root , int p , int q) {

        if(!root) return root;


        auto left = fca(root->left , p , q);
        auto right = fca(root->right , p , q);

        if(root->val == p || root->val == q) return root;

        if(left && right) return root;


        if(left) return left;

        return right;
    }
    int findDistance(TreeNode* root, int p, int q) {

        TreeNode* lca = fca(root ,p , q);

        return d(lca ,p) + d(lca , q);

        
    }
};