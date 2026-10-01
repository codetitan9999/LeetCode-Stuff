class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;

        while (root) {
            double currDiff = abs(root->val - target);
            double bestDiff = abs(ans - target);

            if (currDiff < bestDiff ||
                (currDiff == bestDiff && root->val < ans)) {
                ans = root->val;
            }

            if (target < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return ans;
    }
};