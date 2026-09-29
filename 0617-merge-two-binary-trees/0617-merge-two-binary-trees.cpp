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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;

        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* root = new TreeNode(val);

        root->left = mergeTrees( (root1 ? root1->left : root1) , (root2 ? root2->left: root2));

        root->right = mergeTrees( (root1? root1->right : root1) , (root2 ? root2->right : root2));

        return root;
        
    }
};