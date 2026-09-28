/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool foundP = false;
    bool foundQ = false;
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        auto left = f(root->left , p , q);
        auto right = f(root->right , p , q);


        if(root == p) {
            foundP = true;
            return root;
        }
        if(root == q) {
            foundQ = true;
            return root;
        }


        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = f(root , p , q);

        if(!foundP || !foundQ) return NULL;

        return ans;

    

        
        
    }
};