#include "Tree.h"

template <class keyT, class valT>
class AVLTree_t : public Tree_t<keyT, valT> {
    long check_bf(Node_t<keyT, valT>* n) {
        // Checks balance factor values in tree.
        long hr, hl, h;
        hr = hl = 0;
        if(!n) return 0;
        hr = check_bf(n->right);
        hl = check_bf(n->left);
        if(hr > hl) h = hr;
        else h = hl;
        h += 1;
        long bf = hl - hr;
        assert(bf == n->meta);
        assert(bf < 2);
        assert(bf > -2);
        return h;
    }

    // Optional private functions.
    // These are here to guide you, but you can just ignore these.
    Node_t<keyT, valT>* balance(Node_t<keyT, valT>* a) {
        // Make tree balanced
    }

    Node_t<keyT, valT>* insert_internal(keyT key, valT value) {
        // Helper function for insert()
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
