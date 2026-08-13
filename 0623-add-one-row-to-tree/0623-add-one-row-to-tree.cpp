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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }



        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while(!q.empty()) {
            int sz = q.size();
            if(l == depth-1) {
                break;
            }
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            l++;

        }

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = left;
            node->right->right = right;
        }
        return root;




    }
};