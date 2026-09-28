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
    unordered_map<long long , long long> mp;
    int cnt = 0;
    void f(TreeNode* root , long long & sum , int tsum) {
        if(!root) return;
        sum += root->val;

        cnt += mp[sum - tsum];

        mp[sum]++;

        f(root->left , sum , tsum);
        f(root->right , sum , tsum);

        mp[sum]--;
        sum -= root->val;

    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        long long sum = 0;
        f(root , sum , targetSum);
        return cnt;
        
    }
};