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
    struct NodeVal {
        int count;
        int maxVal;
        int minVal;
        NodeVal(int c , int ma , int mi) {
            count = c;
            maxVal = ma;
            minVal = mi;
        }
    };
public:
    NodeVal f(TreeNode* root) {
        if(!root) return NodeVal(0 , INT_MIN , INT_MAX);

        NodeVal left = f(root->left);
        NodeVal right = f(root->right);

        if(left.maxVal < root->val && right.minVal > root->val) return NodeVal(left.count + right.count + 1 , max(root->val , right.maxVal) , min(root->val , left.minVal));

        return NodeVal(max(left.count , right.count) , INT_MAX , INT_MIN);
    }

    int largestBSTSubtree(TreeNode* root) {
        return f(root).count;
        
    }
};