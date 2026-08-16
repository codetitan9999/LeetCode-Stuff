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
    struct Node {
        int maxValue;
        int minValue;
        int count;
        Node(int x, int y , int z) {
            maxValue = x;
            minValue = y;
            count = z;
        }
    };
    int ans = 0;
    Node f(TreeNode* root) {
        if(!root) {
            return Node(INT_MIN , INT_MAX , 0);
        }

        Node left = f(root->left);
        Node right = f(root->right);

        if(left.maxValue < root->val && right.minValue > root->val) {
            ans = max(ans , root->val + left.count + right.count);
            return Node(max(root->val , right.maxValue) , min(root->val , left.minValue) , root->val + left.count + right.count);
        }

        return Node(INT_MAX , INT_MIN , max(left.count , right.count));
    }
    int maxSumBST(TreeNode* root) {

        Node node = f(root);
        return ans;
        
    }
};