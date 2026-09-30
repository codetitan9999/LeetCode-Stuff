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
    bool f(TreeNode* root) {
        if(!root) return true;

        bool left = f(root->left);
        bool right = f(root->right);

        if(!left || !right) {
            return false;
        }
        if((root->left && root->left->val != root->val ) || (root->right && root->right->val != root->val)) return false;

        ans++;
        return true;

    }
    int countUnivalSubtrees(TreeNode* root) {
        f(root);
        return ans;
        
    }
};