#include "Tree.h"

#define BLACK 0
#define RED 1

template <class keyT, class valT>
class RBTree_t : public Tree_t<keyT, valT> {
    size_t check_rb(Node_t<keyT, valT>* n) {
        // Checks RB tree property
        size_t b, br, bl;
        br = bl = b = 1;
        assert(n);
        if(n && n->right) {
            br = check_rb(n->right);
            assert(n->meta == BLACK || n->right->meta == BLACK);
        }
        if(n && n->left) {
            bl = check_rb(n->left);
            assert(n->meta == BLACK || n->left->meta == BLACK);
        }
        b = br;
        if(n == this->root && br != bl) {
            //dump_subtree(this->root);
        }
        assert(n != this->root || br == bl);
        b = br;
        if(n->meta == BLACK) b += 1;
        if(n == this->root) assert(n->meta == BLACK);

        return b;
    }

    // Optional private functions.
    // These are here to guide you, but you can just ignore these.
    void balance(Node_t<keyT, valT>* n) {
        // Make tree balanced
    }

    void flip(Node_t<keyT, valT>* n) {
        // Flip the color of this node and all children
    }

    void remove_node(Node_t<keyT, valT>* n) {
        // Helper function for remove()
    }


public:
    void insert(keyT key, valT value) {
        // If there is no node that has the given key,
        // create a new one, place it in the right place, and store the value.
        // If there already is a node that has the given key,
        // update the value, rather than making a new one.
    }


    bool remove(keyT key) {
        // Find the node that has the given key and remove that node.
    }

};
