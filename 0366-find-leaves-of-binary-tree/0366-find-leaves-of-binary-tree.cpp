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
    int height(TreeNode* root , vector<vector<int>> & ans) {
        if(!root) return 0;
        ans.push_back({});
        int left = height(root->left , ans);
        int right = height(root->right , ans);

        int h = max(left , right) + 1;
        

        ans[h-1].push_back(root->val);


        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;

        int h = height(root , ans);

        int n = ans.size();

        for(int i = 0 ; i < n-h ; i++) ans.pop_back();


        return ans;


    }
};