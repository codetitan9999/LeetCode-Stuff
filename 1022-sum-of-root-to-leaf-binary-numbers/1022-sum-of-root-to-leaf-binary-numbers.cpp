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
    int sum = 0;
    void f(TreeNode* root , int val) {
        if(!root) return;
        val = (val << 1);
        val |= (root->val);
        if(!root->left && !root->right) {
            sum += val;
            return;
        }
        f(root->left , val);
        f(root->right , val);


    }
    int sumRootToLeaf(TreeNode* root) {
        f(root , 0);
        return sum;
      
        
    }
};