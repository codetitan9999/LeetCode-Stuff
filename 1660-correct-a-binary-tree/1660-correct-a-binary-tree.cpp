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
    TreeNode* f(TreeNode* root , int val) {
        if(!root || root->val == val) return NULL;

        root->left = f(root->left , val);
        root->right = f(root->right , val);

        return root;

    }
    TreeNode* correctBinaryTree(TreeNode* root) {


        queue<pair<TreeNode*, int>> q;

        q.push({root , -1});

        unordered_set<int> vis;
        int to_del = INT_MAX;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int p = q.front().second;
            
            q.pop();

            if(vis.count(node->val)) {
                to_del = p;
                break;
            }

            vis.insert(node->val);

            if(node->left) {
                q.push({node->left , node->val});
            }

            if(node->right) {
                q.push({node->right , node->val});
            }



        }

        f(root , to_del);
        return root;
        
    }
};