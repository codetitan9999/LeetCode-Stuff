class Solution {
public:
    
    TreeNode* f(int & index , vector<int> & pre , int ub, int lb) {
        if(index == pre.size()) return NULL;
        if(pre[index] > ub || pre[index] < lb) return NULL;

        TreeNode* root = new TreeNode(pre[index++]);

        root->left = f(index , pre , root->val , lb);
        root->right = f(index , pre , ub , root->val);

        return root;


    }
    bool verifyPreorder(vector<int>& preorder) {
        int index = 0;
        f(index , preorder , INT_MAX , INT_MIN);
        return  index == preorder.size();
        
    }
};