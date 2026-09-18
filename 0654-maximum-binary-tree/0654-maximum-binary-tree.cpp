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
    TreeNode* f(int low , int high , vector<int> & nums) {
        if(low > high) return NULL;
        int maxi = low;
        for(int i = low ; i <= high ; i++) {
            if(nums[i] > nums[maxi]) {
                maxi = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxi]);

        root->left = f(low , maxi-1 , nums);
        root->right = f(maxi+1 , high , nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(0 , nums.size() -1 , nums);
        
    }
};