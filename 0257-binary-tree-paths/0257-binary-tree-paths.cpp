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
    bool isLeaf(TreeNode* root) {
        if(!root) return false;
        return (root->left == NULL) &&(root->right == NULL);
    }
    void f(TreeNode* root , string x ,  vector<string> & ans) {
        if(!root) return;
        if(isLeaf(root)) {
            x = x.length() ? (x + "->" + to_string(root->val)) : (x + to_string(root->val));
            ans.push_back(x);
            return;
        }


        f(root->left , x.length() ? (x + "->" + to_string(root->val)) : (x + to_string(root->val)) , ans);

        f(root->right , x.length() ? (x + "->" + to_string(root->val)) : (x + to_string(root->val)) , ans);


    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string x = "";

        f(root , x , ans);
        return ans;
        
    }
};