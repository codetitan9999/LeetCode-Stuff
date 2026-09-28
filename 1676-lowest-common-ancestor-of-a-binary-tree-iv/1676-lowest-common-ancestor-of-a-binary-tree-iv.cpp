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
    TreeNode* f(TreeNode* root, set<TreeNode*> & st) {
        if(!root) return root;

        auto left = f(root->left , st);

        auto right = f(root->right , st);

        if(st.count(root)) return root;

        if(left && right) return root;

        if(left) return left;
        return right;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*> st(nodes.begin() , nodes.end());
        return f(root , st);
        
    }
};