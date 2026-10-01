class Solution {
public:
    Node* inorderSuccessor(Node* node) {

        // Case 1: Right subtree exists
        if (node->right) {
            Node* curr = node->right;

            while (curr->left)
                curr = curr->left;

            return curr;
        }

        // Case 2: Move upward
        while (node->parent && node == node->parent->right) {
            node = node->parent;
        }

        return node->parent;
    }
};