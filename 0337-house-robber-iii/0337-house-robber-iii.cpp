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
    int f(TreeNode* root , bool cond , map<pair<TreeNode*, bool>,  int> & dp) {
        if(!root) return 0;
        if(dp.count({root , cond})) return dp[{root,cond}];
        int nt = f(root->left , true, dp) + f(root->right , true, dp);
        int t = -1e9;
        if(cond) {
            t = root->val + f(root->left , false, dp) + f(root->right , false , dp);
        }
        return dp[{root, cond}] = max(t , nt);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        map<pair<TreeNode*, bool> , int> dp;
        return f(root , true, dp);
        
    }
};