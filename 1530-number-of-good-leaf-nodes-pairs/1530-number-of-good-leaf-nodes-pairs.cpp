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
 *
 *  
 */
    

class Solution {
public:
    int cnt = 0;
    vector<int> f(TreeNode* root , int dist) {
        if(!root) return {};

        if(!root->left &&!root->right) return {1};

        auto left = f(root->left , dist);
        auto right = f(root->right , dist);
        for(auto l : left) {
            for(auto r : right) {
                if(l+r <= dist) cnt++;
            }
        }
        vector<int> full;
        for(int i = 0 ; i < left.size() ; i++) {
            left[i] += 1;
            full.push_back(left[i]);
        }
        for(int i = 0 ; i < right.size() ; i++) {
            right[i] += 1;
            full.push_back(right[i]);
        }

        return full;


    }

    int countPairs(TreeNode* root, int distance) {
        f(root , distance);
        return cnt;
        
    }
};