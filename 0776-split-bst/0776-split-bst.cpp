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

    pair<TreeNode* , TreeNode*> f(TreeNode* root , int target) {
        if(!root) return {NULL , NULL};


        auto left = f(root->left , target);
        auto right = f(root->right , target);


        if(root->val > target) {
            root->left = left.second;
            root->right = right.second;
            return {left.first , root};
        } else {

            root->left = left.first;
            root->right = right.first;

            return {root , right.second};
        }


    }
    vector<TreeNode*> splitBST(TreeNode* root, int target) {

        vector<TreeNode*> ans;

        auto x = f(root , target);
        ans.push_back(x.first );
        ans.push_back(x.second );
        return ans;
        
    }
};