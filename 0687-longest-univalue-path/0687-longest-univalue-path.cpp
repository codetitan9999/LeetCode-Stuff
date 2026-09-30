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
    int res = 0;
    int f(TreeNode* root) {
        if(!root) return 0;

        int l = f(root->left);
        int r = f(root->right);

        int maxi = 0;
        int val = 0;

        if(root->left && root->left->val == root->val) {
            maxi = max(maxi , l);
            val += l;
        }
        if(root->right && root->right->val == root->val) {
            maxi = max(maxi , r);
            val += r;
        }
        res = max(res , val+1);
        return maxi+1;

    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        f(root);
        return res-1;
        
    }
};