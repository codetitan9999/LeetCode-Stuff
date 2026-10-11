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
    long long ans = 0;
    void f(TreeNode* root , TreeNode* parent , TreeNode* grandparent) {
        if(!root) return ;
        if(grandparent && grandparent->val%2==0) {
            ans += root->val;
        }
        f(root->left , root , parent);
        f(root->right , root , parent);

    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        f(root , NULL , NULL);
        return ans;
        
    }
};