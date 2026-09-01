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
    int leftHeight(TreeNode* root) {
        int left = 0;
        while(root) {
            left++;
            root = root->left;
        }
        return left;
    }

    int rightHeight(TreeNode* root) {
        int right = 0;
        while(root) {
            right++;
            root = root->right;
        }
        return right;
    }
    int f(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1LL<<lh) -1;

        return 1 + f(root->left) + f(root->right);
    }
    int countNodes(TreeNode* root) {

        return f(root);
    }
};