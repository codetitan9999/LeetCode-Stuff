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
    priority_queue<int , vector<int> , greater<int>> pq;
    pair<int , int> f(TreeNode* root , int k) {
        if(!root) return {0, 0};

        auto left = f(root->left , k );
        auto right = f(root->right , k) ;
        if(left.first == -1 || right.first == -1) return {-1 , 0};

        if(left.first == right.first) {
            pq.push(left.second + right.second +1);
            if(pq.size() > k) pq.pop();
            return {left.first+1 , left.second + right.second + 1};
        } 

        return {-1 , 0};
    }


    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        f(root , k);
        return pq.size() == k ? pq.top() : -1;
        
    }
};