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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* ans = NULL;

        if(!root) return ans;

        queue<TreeNode*> q;

        q.push(root);


        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                
                if(ans == u) {
                    return node;
                }
                if(node == u) ans = node;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(ans == u) return NULL;
            
        } 
        return NULL;
    }
};