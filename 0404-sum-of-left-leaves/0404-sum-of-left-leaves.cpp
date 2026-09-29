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
    int f(TreeNode* root , bool isLeft) {
        if(!root) return 0;

        if(!root->left && !root->right) {
            if(isLeft) return root->val;
            else return 0;
        }


        int left = f(root->left , true);
        int right = f(root->right , false);

        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root , false);
    }
};