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
    priority_queue<pair<double , int>> pq;
    void f(TreeNode* root , int k , double target) {
        if(!root) return;

        double diff = abs((double)root->val - target);
        pq.push({diff , root->val});
        if(pq.size() > k) pq.pop();

        f(root->left , k , target);
        f(root->right , k , target);

    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        f(root , k , target);
     
        vector<int> ans;

        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};