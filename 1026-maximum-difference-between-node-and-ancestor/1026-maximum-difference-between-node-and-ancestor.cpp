class Solution {
public:
    int f(TreeNode* root, int mn, int mx) {
        if (!root) return mx - mn;

        mn = min(mn, root->val);
        mx = max(mx, root->val);

        return max(
            f(root->left, mn, mx),
            f(root->right, mn, mx)
        );
    }

    int maxAncestorDiff(TreeNode* root) {
        return f(root, root->val, root->val);
    }
};