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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* P = p , *Q = q;
        if(!p ||!q) return NULL;

        while(p != q) {
            if(!p) p = Q;
            else p = p->parent;

            if(!q) q = P;
            else q = q->parent;
        }
        return p;
        
    }
};