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
    int ans = -1;
    int f1(TreeNode* root , int currLevel , int level) {
        if(!root) return 0;
        if(currLevel == level) return 1;
        return f1(root->left , currLevel+1 , level) + f1(root->right , currLevel+1 , level);
    }
    bool f2(TreeNode* root , int level , int curL , int & cnt , int mid) {
        if(!root) return false;

        if(f2(root->left , level , curL+1 , cnt , mid)) return true;
        if(curL == level) {
            if(cnt == mid) {
                ans = root->val;
                return true;
            }
            cnt++;
        }
        if(f2(root->right , level , curL+1 , cnt , mid)) return true;


        return false;
    }
    int levelMedian(TreeNode* root, int level) {

        int cnt = f1(root , 0 , level);
        if(cnt == 0) return -1;
        cout<<cnt<<endl;
        int mid = cnt / 2;
        int count = 0;
        f2(root , level , 0 , count , mid);

        return ans;


        
    }
};