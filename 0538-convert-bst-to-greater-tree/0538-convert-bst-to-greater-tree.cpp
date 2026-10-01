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
    int sum(TreeNode* root) {
        if(!root) return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        return root->val + left + right;
    }
    int f(TreeNode* root , int sum) {
        if(!root) return 0;

        int left = f(root->left , sum);
        int right = f(root->right , sum - root->val - left);
        int tot = left+right + root->val;

        root->val = sum - left;

        return tot;
    }
    TreeNode* convertBST(TreeNode* root) {
        int tot = sum(root);
        f(root , tot);
        return root;

        
    }
};