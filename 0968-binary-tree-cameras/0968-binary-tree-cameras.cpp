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
    int cnt = 0;
    int f(TreeNode* root) {
        if(!root) return 2;
        // 1 for Has camera
        // 2 for covered
        // 0 for need camera

        int left = f(root->left);
        int right = f(root->right);

        if(left == 0 || right == 0) {
            cnt++;
            return 1;
        }

        if(left == 1 || right ==1) return 2;

        return 0;


    }
    int minCameraCover(TreeNode* root) {
        cnt = 0;

        if(f(root) == 0) cnt++;
        return cnt;
    }
};