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
    TreeNode* f(int preStart , int preEnd , int inStart , int inEnd , vector<int> & preorder , unordered_map<int,int> & inMap) {
        if(preStart > preEnd) return NULL;
        int numsLeft = inMap[preorder[preStart]] - inStart;

        TreeNode * root = new TreeNode(preorder[preStart]);
        root->left = f(preStart+1 , preStart + numsLeft ,inStart , inMap[preorder[preStart]] -1,  preorder , inMap);
        root->right = f(preStart + numsLeft +1 , preEnd ,inMap[preorder[preStart]] +1 , inEnd , preorder , inMap);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for(int i = 0 ; i < inorder.size() ; i++) {
            inMap[inorder[i]] = i;
        }
        return f(0 , preorder.size()-1 , 0 , inorder.size()-1,  preorder , inMap);

    }
};