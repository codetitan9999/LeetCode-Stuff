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
    vector<int> merge(vector<int> & a , vector<int> & b) {
        vector<int> ans;
        int i = 0, j = 0;
        int n = a.size() , m = b.size();

        while(i < n && j < m) {
            if(a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while(i < n) {
            ans.push_back(a[i++]);
        }
        while(j < m) {
            ans.push_back(b[j++]);
        }
        return ans;
    }

    void f(TreeNode* root , vector<int> & ans) {
        if(!root) return;

        f(root->left , ans);
        ans.push_back(root->val);
        f(root->right , ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1 , in2;
        f(root1 , in1);
        f(root2 , in2);

        return merge(in1 , in2);
    }
};