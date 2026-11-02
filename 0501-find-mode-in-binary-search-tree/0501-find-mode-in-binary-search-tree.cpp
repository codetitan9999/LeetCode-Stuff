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
    int ans = 0;
    unordered_map<int,int> mp;
    void f(TreeNode* root) {
        if(!root) return;
        mp[root->val]++;
        ans = max(ans , mp[root->val]);
        f(root->left);
        f(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        f(root);

        vector<int> res;
        for(auto [val , f] : mp) {
            if(f == ans) res.push_back(val);
        }
        return res;
        
    }
};