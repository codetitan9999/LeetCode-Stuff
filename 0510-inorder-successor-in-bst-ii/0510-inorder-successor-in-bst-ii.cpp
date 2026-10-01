/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* f(Node* node) {
        while(node->parent) {
            node = node->parent;
        }
        return node;
    }
    Node* inorderSuccessor(Node* node) {
        Node* root = f(node);

        Node* curr = root;
        Node* ans = NULL;


        while(curr) {
            if(curr->val > node->val) {
                ans = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return ans;
        
    }
};