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
    pair<int,int> f(TreeNode* root) {
        if(!root) return {0, 0};

        auto left = f(root->left);
        auto right = f(root->right);

        int inc = 0 ;
        int dec = 0;

        if(root->left) {
            if(root->left->val == root->val+1) {
                inc = max(inc , left.first);

            }

            if(root->left->val == root->val-1) {
                dec = max(dec , left.second);

            }
        }

        if(root->right) {
            if(root->right->val == root->val +1) {
                inc = max(inc , right.first);

            }
            if(root->right->val == root->val-1) {
                dec = max(dec , right.second);

            }
        }

        ans = max(ans , inc + dec +1);

        return {inc+1 , dec+1};

    }
    int longestConsecutive(TreeNode* root) {
        f(root);
        return ans;
        
    }
};