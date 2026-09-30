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
    unordered_map<int , int> height;
    unordered_map<int,int> depth;
    vector<int> best1;
    vector<int> best2;
    int f(TreeNode* root , int d) {
        if(!root) return 0;
        depth[root->val] = d;
        int l = f(root->left , d+1);
        int r = f(root->right , d+1);
        int h = max(l, r) +1;

        height[root->val] = h;

        if(h > best1[d]) {
            best2[d] = best1[d];
            best1[d] = h;
        } else if(h > best2[d]) {
            best2[d] = h;
        }

        return h;

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        best1.resize(1e5+7 , 0);
        best2.resize(1e5+7 , 0);

        f(root , 1);
        vector<int> ans;
        for(auto it : queries) {
            int d = depth[it];
            int h = height[it];
            if(h == best1[d]) {
                ans.push_back( d-2 + best2[d]);
            } else {
                ans.push_back(height[root->val]-1);
            }
        }
        return ans;

    }
};