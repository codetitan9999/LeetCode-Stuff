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
    unordered_set<TreeNode*> vis;
public:
    TreeNode* f(TreeNode* root) {
        if(!root || (root->right && vis.count(root->right))) return NULL;

        vis.insert(root);

        root->right = f(root->right);
        root->left = f(root->left);
        return root;
    }
    TreeNode* correctBinaryTree(TreeNode* root) {
        vis.clear();
        f(root);
        return root;
        
        
    }
};