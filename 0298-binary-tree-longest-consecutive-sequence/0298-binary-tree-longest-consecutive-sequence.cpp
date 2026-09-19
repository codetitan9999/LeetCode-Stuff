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
    int ans = 0;
    int f(TreeNode* root) {
        if(!root) return 0;

        int left = f(root->left);
        int right= f(root->right);

        int maxi = 1;

        if(root->left && root->left->val == root->val+1) {
            maxi = max(maxi , 1+left);
        }

        if(root->right && root->right->val == root->val +1) {
            maxi = max(maxi , 1+right);
        }
        ans = max(maxi , ans);
        return maxi;
    }
    int longestConsecutive(TreeNode* root) {
        f(root);
        return ans;
    }
};