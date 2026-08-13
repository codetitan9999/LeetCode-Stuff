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
    TreeNode* f(int postStart , int postEnd , int inStart , int inEnd , unordered_map<int, int> & inMap , vector<int> & postOrder) {
        if(postStart  > postEnd) return NULL;

        int inRoot = inMap[postOrder[postEnd]];
        int numsLeft = inRoot - inStart;
        TreeNode* root = new TreeNode(postOrder[postEnd]);
        root->left = f(postStart , postStart + numsLeft -1 , inStart , inRoot-1 , inMap , postOrder);
        root->right = f(postStart + numsLeft , postEnd-1 , inRoot+1 , inEnd , inMap , postOrder);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> inMap;
        for(int i = 0. ; i < inorder.size() ; i++) {
            inMap[inorder[i]] = i;
        }
        int n = inorder.size();
        return f(0 , n-1 , 0 , n-1 , inMap , postorder);

        
    }
};