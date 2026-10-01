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
    TreeNode* find(TreeNode* root) {
        while(root->left) root = root->left;
        return root;
    }
    TreeNode* remove(TreeNode* root) {
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode* next = find(root->right);
        TreeNode* right = root->right;
        next->left = root->left;
        delete root;
        return right;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return remove(root);
        TreeNode* curr = root;
        while(root) {
            if(root->val > key) {
                if(root->left && root->left->val == key) root->left = remove(root->left);
                else root= root->left;
            } else {
                if(root->right && root->right->val == key) root->right = remove(root->right);
                else root = root->right;
            }
        }
        return curr;
        
    }
};