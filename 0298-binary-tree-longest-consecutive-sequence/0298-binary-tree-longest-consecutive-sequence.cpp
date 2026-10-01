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
    int maxi = 0;
    int f(TreeNode* root) {
        if(!root) return 0;
        int left = f(root->left);
        int right = f(root->right);

        int cnt = 0;

        if(root->left && root->left->val == root->val+1) {
            cnt = max(cnt , left);
        }

        if(root->right && root->right->val == root->val+1) {
            cnt = max(cnt , right);
        }
        maxi = max(maxi , cnt+1);

        return cnt+1;
    }
    int longestConsecutive(TreeNode* root) {
        f(root);
        return maxi;
        
    }
};