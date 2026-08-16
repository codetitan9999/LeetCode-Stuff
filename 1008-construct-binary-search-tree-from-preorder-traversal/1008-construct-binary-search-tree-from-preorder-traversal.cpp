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
    TreeNode* f(int & ind , int ub ,  vector<int>& preorder) {
        int n = preorder.size();
        if(ind >= n || preorder[ind] > ub) return NULL;

        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = f(ind , root->val , preorder);
        root->right = f(ind , ub , preorder);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int ind = 0;
        return f(ind ,INT_MAX, preorder);
        
    }
};