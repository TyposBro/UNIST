#include "Tree.h"

#define BLACK 0
#define RED 1

template <class keyT, class valT>
class RBTree_t : public Tree_t<keyT, valT>
{
    size_t check_rb(Node_t<keyT, valT> *n)
    {
        // Checks RB tree property
        size_t b, br, bl;
        br = bl = b = 1;
        assert(n);
        if (n && n->right)
        {
            br = check_rb(n->right);
            assert(n->meta == BLACK || n->right->meta == BLACK);
        }
        if (n && n->left)
        {
            bl = check_rb(n->left);
            assert(n->meta == BLACK || n->left->meta == BLACK);
        }
        b = br;
        if (n == this->root && br != bl)
        {
            // dump_subtree(this->root);
        }
        assert(n != this->root || br == bl);
        b = br;
        if (n->meta == BLACK)
            b += 1;
        if (n == this->root)
            assert(n->meta == BLACK);

        return b;
    }

    // Optional private functions.
    // These are here to guide you, but you can just ignore these.
    void balance(Node_t<keyT, valT> *n)
    {
        // Make tree balanced
    }

    void flip(Node_t<keyT, valT> *n)
    {
        // Flip the color of this node and all children
    }

    void remove_node(Node_t<keyT, valT> *n)
    {
        // Helper function for remove()
    }

public:
    bool rr = false;
    bool ll = false;
    bool lr = false;
    bool rl = false;

    Node_t<keyT, valT> *newNode(keyT key, valT value, Node_t<keyT, valT> *parent = NULL)
    {
        Node_t<keyT, valT> *node = new Node_t<keyT, valT>();
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = parent;
        node->meta = RED;

        return node;
    }

    void insert(keyT key, valT value)
    {
        // If there is no node that has the given key,
        // create a new one, place it in the right place, and store the value.
        // If there already is a node that has the given key,
        // update the value, rather than making a new one.
        Node_t<keyT, valT> *node = newNode(key, value);

        if (this->root == NULL)
        {
            node->meta = BLACK;
            this->root = node;
        }
        else
        {
            Node_t<keyT, valT> *temp = _search(key);

            if (temp->key == key)
            {
                if (temp->value == value)

                    return;
                else
                {
                    temp->value = value;
                    return;
                }
            }

            node->parent = temp;
            if (key < temp->key)
                temp->left = node;
            else
                temp->right = node;
            _fixRedRed(node);
        }
    }

    void _swapColors(Node_t<keyT, valT> *x1, Node_t<keyT, valT> *x2)
    {
        short temp;
        temp = x1->meta;
        x1->meta = x2->meta;
        x2->meta = temp;
    }

    void _swapValues(Node_t<keyT, valT> *u, Node_t<keyT, valT> *v)
    {
        valT val = u->value;
        u->value = v->value;
        v->value = val;
        valT key = u->key;
        u->key = v->key;
        v->key = key;
    }

    void left(Node_t<keyT, valT> *x)
    {
        // new parent will be node's right child
        Node_t<keyT, valT> *nParent = x->right;

        // update root if current node is root
        if (x == this->root)
            this->root = nParent;

        x->_moveDown(nParent);

        // connect x with new parent's left element
        x->right = nParent->left;
        // connect new parent's left element with node
        // if it is not null
        if (nParent->left != NULL)
            nParent->left->parent = x;

        // connect new parent with x
        nParent->left = x;
    }

    void right(Node_t<keyT, valT> *x)
    {
        // new parent will be node's left child
        Node_t<keyT, valT> *nParent = x->left;

        // update root if current node is root
        if (x == this->root)
            this->root = nParent;

        x->_moveDown(nParent);

        // connect x with new parent's right element
        x->left = nParent->right;
        // connect new parent's right element with node
        // if it is not null
        if (nParent->right != NULL)
            nParent->right->parent = x;

        // connect new parent with x
        nParent->right = x;
    }

    void _fixRedRed(Node_t<keyT, valT> *x)
    {
        // if x is root color it black and return
        if (x == this->root)
        {
            x->meta = BLACK;
            return;
        }

        Node_t<keyT, valT> *parent = x->parent, *gp = parent->parent,
                           *uncleSam = x->_uncle();

        if (parent->meta != BLACK)
        {
            if (uncleSam != NULL && uncleSam->meta == RED)
            {
                // uncleSam red, perform recoloring and recurse
                parent->meta = BLACK;
                uncleSam->meta = BLACK;
                gp->meta = RED;
                _fixRedRed(gp);
            }
            else
            {
                // Else perform LR, LL, RL, RR
                if (parent->_isOnLeft())
                {
                    if (x->_isOnLeft())
                    {
                        // for left right
                        _swapColors(parent, gp);
                    }
                    else
                    {
                        left(parent);
                        _swapColors(x, gp);
                    }
                    // for left left and left right
                    right(gp);
                }
                else
                {
                    if (x->_isOnLeft())
                    {
                        // for right left
                        right(parent);
                        _swapColors(x, gp);
                    }
                    else
                    {
                        _swapColors(parent, gp);
                    }

                    // for right right and right left
                    left(gp);
                }
            }
        }
    }

    Node_t<keyT, valT> *_successor(Node_t<keyT, valT> *x)
    {
        Node_t<keyT, valT> *temp = x;

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }

    Node_t<keyT, valT> *_BSTreplace(Node_t<keyT, valT> *x)
    {
        // when node have 2 children
        if (x->left != NULL and x->right != NULL)
            return _successor(x->right);

        // when leaf
        if (x->left == NULL and x->right == NULL)
            return NULL;

        // when single child
        if (x->left != NULL)
            return x->left;
        else
            return x->right;
    }

    void _deleteNode(Node_t<keyT, valT> *v, bool *found)
    {
        Node_t<keyT, valT> *u = _BSTreplace(v);

        // True when u and v are both black
        bool uvBlack = ((u == NULL or u->meta == BLACK) and (v->meta == BLACK));
        Node_t<keyT, valT> *parent = v->parent;

        if (u == NULL)
        {
            // u is NULL therefore v is leaf
            if (v == this->root)
            {
                // v is root, making root null
                this->root = NULL;
            }
            else
            {
                if (uvBlack)
                {
                    // u and v both black
                    // v is leaf, fix double black at v
                    _fixDoubleBlack(v);
                }
                else
                {
                    // u or v is red
                    if (v->_sibling() != NULL)
                        // sibling is not null, make it red"
                        v->_sibling()->meta = RED;
                }

                // delete v from the tree
                if (v->_isOnLeft())
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            delete v;
            *found = true;
            return;
        }

        if (v->left == NULL or v->right == NULL)
        {
            // v has 1 child
            if (v == this->root)
            {
                // v is root, assign the value of u to v, and delete u
                v->value = u->value;
                v->left = v->right = NULL;
                delete u;
            }
            else
            {
                // Detach v from tree and move u up
                if (v->_isOnLeft())
                {
                    parent->left = u;
                }
                else
                {
                    parent->right = u;
                }
                delete v;
                *found = true;
                u->parent = parent;
                if (uvBlack)
                {
                    // u and v both black, fix double black at u
                    _fixDoubleBlack(u);
                }
                else
                {
                    // u or v red, color u black
                    u->meta = BLACK;
                }
            }
            return;
        }

        // v has 2 children, swap values with successor and recurse
        _swapValues(u, v);
        _deleteNode(u, found);
    }

    void _fixDoubleBlack(Node_t<keyT, valT> *x)
    {
        if (x == this->root)
            return;

        Node_t<keyT, valT> *sibling = x->_sibling(), *parent = x->parent;
        if (sibling == NULL)
        {
            // No sibiling, double black pushed up
            _fixDoubleBlack(parent);
        }
        else
        {
            if (sibling->meta == RED)
            {
                // Sibling red
                parent->meta = RED;
                sibling->meta = BLACK;
                if (sibling->_isOnLeft())
                {
                    // left case
                    right(parent);
                }
                else
                {
                    // right case
                    left(parent);
                }
                _fixDoubleBlack(x);
            }
            else
            {
                // Sibling black
                if (sibling->_hasRedChild())
                {
                    // at least 1 red children
                    if (sibling->left != NULL and sibling->left->meta == RED)
                    {
                        if (sibling->_isOnLeft())
                        {
                            // left left
                            sibling->left->meta = sibling->meta;
                            sibling->meta = parent->meta;
                            right(parent);
                        }
                        else
                        {
                            // right left
                            sibling->left->meta = parent->meta;
                            right(sibling);
                            left(parent);
                        }
                    }
                    else
                    {
                        if (sibling->_isOnLeft())
                        {
                            // left right
                            sibling->right->meta = parent->meta;
                            left(sibling);
                            right(parent);
                        }
                        else
                        {
                            // right right
                            sibling->right->meta = sibling->meta;
                            sibling->meta = parent->meta;
                            left(parent);
                        }
                    }
                    parent->meta = BLACK;
                }
                else
                {
                    // 2 black children
                    sibling->meta = RED;
                    if (parent->meta == BLACK)
                        _fixDoubleBlack(parent);
                    else
                        parent->meta = BLACK;
                }
            }
        }
    }
    Node_t<keyT, valT> *_search(keyT n)
    {
        Node_t<keyT, valT> *temp = this->root;
        while (temp != NULL)
        {
            if (n < temp->key)
            {
                if (temp->left == NULL)
                    break;
                else
                    temp = temp->left;
            }
            else if (n == temp->key)
            {
                break;
            }
            else
            {
                if (temp->right == NULL)
                    break;
                else
                    temp = temp->right;
            }
        }

        return temp;
    }

    bool remove(keyT key)
    {
        // Find the node that has the given key and remove that node.
        bool found = false;
        if (this->root == NULL)
            return false;
        Node_t<keyT, valT> *v = _search(key);
        if (v->key != key)
            return false;

        _deleteNode(v, &found);

        return found;
    }
};
