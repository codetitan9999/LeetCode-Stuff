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
    int closestValue(TreeNode* root, double target) {

        double ans = 0 , diff = 1e9+7;

        TreeNode* curr = root;
        while(curr) {
            if((double)curr->val == target) return curr->val;
            double cdiff = fabs(target - curr->val);
            if(cdiff < diff) {
                diff = cdiff;
                ans = curr->val;
            } else if(cdiff == diff) {
                ans = min(ans , (double)curr->val);
            }

            if((double)(curr->val ) > target) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return ans;
        
    }
};