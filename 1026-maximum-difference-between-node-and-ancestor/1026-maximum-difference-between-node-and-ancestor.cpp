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
    int ans = INT_MIN;
    pair<int,int> f(TreeNode* root) {
        if(!root) return {INT_MAX , INT_MIN};


        auto left = f(root->left);
        auto right = f(root->right);

        if(left.first != INT_MAX) {
            ans = max(ans , abs(left.first - root->val));
        }
        if(left.second != INT_MIN) {
            ans = max(ans , abs(left.second - root->val));
        }

        if(right.first != INT_MAX) {
            ans = max(ans , abs(right.first -root->val));
        }

        if(right.second != INT_MIN) {
            ans = max(ans , abs(right.second -root->val));
        }


        return {min(left.first , min(right.first , root->val)) ,max(left.second , max(right.second , root->val))};

    }
    int maxAncestorDiff(TreeNode* root) {
        f(root);
        return ans;
        
    }
};