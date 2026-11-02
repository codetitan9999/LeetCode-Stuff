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
public:
    stack<TreeNode*> st;
    int index;
    vector<int> history;
    BSTIterator(TreeNode* root) {
        add(root);
        index = -1;
        
    }
    
    bool hasNext() {

        return !st.empty() || index < history.size()-1;
        
    }
    
    int next() {
        if(index != history.size() -1) {
            index++;
            return history[index];
        }

        TreeNode* val = st.top();
        st.pop();
        history.push_back(val->val);
        index++;
        add(val->right);
        return val->val;
    }
    
    bool hasPrev() {

        
        return index > 0;
    }
    
    int prev() {
        index--;
        return history[index];
    }
    void add(TreeNode* root) {
        while(root) {
            st.push(root);
            root= root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */