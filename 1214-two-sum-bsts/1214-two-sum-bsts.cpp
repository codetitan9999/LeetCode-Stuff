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

class BSTIterator {
    bool reverse;
    stack<TreeNode*> st;
    public:
    BSTIterator(TreeNode* root , bool isReverse) {
        reverse = isReverse;
        add(root);
        
    }

    void add(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* val = st.top();
        st.pop();
        if(reverse) {
            add(val->left);
        } else {
            add(val->right);
        }
        return val->val;
    }
    int curr() {
        return st.top()->val;
    }
    
};
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        BSTIterator * b1 = new BSTIterator(root1 , false);
        BSTIterator * b2 = new BSTIterator(root2 , true);
        
        while(b1->hasNext() && b2->hasNext()) {
            int val1 = b1->curr();
            int val2 = b2->curr();
            cout<<val1<<" "<<val2<<endl;
            if(val1 + val2 == target) return true;
            if(val1 + val2 < target) b1->next();
            else b2->next();

        }
        delete b1;
        delete b2;
        return false;
    }
};