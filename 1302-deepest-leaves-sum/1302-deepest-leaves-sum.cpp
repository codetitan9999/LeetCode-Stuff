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

    pair<int,int> f(TreeNode* root ) {
        if(!root) return {0 , 0};
        if(!root->left && !root->right) return {root->val , 1};

        auto left = f(root->left);
        auto right = f(root->right);


        if(left.second == right.second) return { left.first + right.first , 1 + left.second};

        if(left.second < right.second) return {right.first ,  1 + right.second};

        return {left.first, left.second+1};

    }
    int deepestLeavesSum(TreeNode* root) {

        auto ans = f(root);

        return ans.first;
        
    }
};