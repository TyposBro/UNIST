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
    // Construct New Node with given keyT key, valT value
    Node_t<keyT, valT> *newNode(keyT key, valT value, Node_t<keyT, valT> *parent = NULL)
    {
        // Empty Node
        Node_t<keyT, valT> *node = new Node_t<keyT, valT>();
        // Assign Key with given gustom type
        node->key = key;
        // Assign Value with given gustom type
        node->value = value;
        // Assign left child to NULL
        node->left = NULL;
        // Assign right child to NULL
        node->right = NULL;
        // Assign Parent Pointer with given gustom type
        node->parent = parent;
        // Assign Meta Pointer to RED
        node->meta = RED;

        return node;
    }

    void insert(keyT key, valT value)
    {
        // If there is no node that has the given key,
        // create a new one, place it in the right place, and store the value.
        // If there already is a node that has the given key,
        // update the value, rather than making a new one.

        // Construct New Node with given keyT key, valT value
        Node_t<keyT, valT> *node = newNode(key, value);

        // Check if tree is empty
        if (this->root == NULL)
        {
            // Check if empty, make it Black
            node->meta = BLACK;
            // then make it root
            this->root = node;
        }
        else
        {
            // Search for the given KEY
            Node_t<keyT, valT> *temp = _search(key);

            // if KEY is found, check the value
            if (temp->key == key)
            {
                // if value is the same
                if (temp->value == value)
                    // do nothing
                    // return void
                    return;
                else
                {
                    // Update Value
                    temp->value = value;
                    // return void
                    return;
                }
            }

            // change parent to of the given node to temp
            node->parent = temp;
            // if key is less
            if (key < temp->key)
                // make node its left child
                temp->left = node;
            else
                // make node its right child
                temp->right = node;
            rr(node);
        }
    }

    // swap given colors of x1 and x2 of type Node_t<keyT, valT> *, Node_t<keyT, valT> *
    void color(Node_t<keyT, valT> *x1, Node_t<keyT, valT> *x2)
    {
        // assign meta of x1 to temporary meta
        short temp = x1->meta;
        // assign meta of x2 to x1
        x1->meta = x2->meta;
        // assign meta of x1 to x2
        x2->meta = temp;
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    void valueKey(Node_t<keyT, valT> *u, Node_t<keyT, valT> *v)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        valT val = u->value;
        u->value = v->value;
        v->value = val;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        valT key = u->key;
        u->key = v->key;
        v->key = key;
    }

    void left(Node_t<keyT, valT> *x)
    {
        // store right child of given node to p pointer
        Node_t<keyT, valT> *p = x->right;

        // if it's the same as root
        if (x == this->root)
            // change root to p
            this->root = p;
        // move the given node down relative to it's parent
        x->d(p);

        // assign p's left child to x's left child
        x->right = p->left;
        // if p's left child is empty
        if (p->left != NULL)
            // make given node p's left child's parent
            p->left->parent = x;
        p->left = x;
    }

    void right(Node_t<keyT, valT> *x)
    {
        // fenvrtbgr;hnjmk;.ljevnrslbgtkdhn fkj
        Node_t<keyT, valT> *p = x->left;

        // fweilgrtbh;gkmu:tmrslnh5tbrntkenjk/m
        if (x == this->root)
            this->root = p;

        x->d(p);

        // fvrkgbt.dfnyujm;l,nkymg/ fmgjmlfy/km /sbntrbk.gj dnktrjdbkdtn
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        !x->left = p->right;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (p->right != NULL)
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            p->right->parent = x;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        p->right = x;
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    void rr(Node_t<keyT, valT> *x)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (x == this->root)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            x->meta = BLACK;
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            return;
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *parent = x->parent, *gp = parent->parent,
                           // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                                                    *uncleSam = x->_uncle();

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (parent->meta != BLACK)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            if (uncleSam != NULL && uncleSam->meta == RED)
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                parent->meta = BLACK;
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                uncleSam->meta = BLACK;
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                gp->meta = RED;
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                rr(gp);
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            }
            else
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                if (parent->_isOnLeft())
                {
                    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                    if (x->_isOnLeft())
                    {
                        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                        color(parent, gp);
                    }
                    else
                    {
                        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                        left(parent);
                        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                        color(x, gp);
                    }

                    right(gp);
                }
                else
                {
                    if (x->_isOnLeft())
                    {
                        // for right left
                        right(parent);
                        color(x, gp);
                    }
                    else
                    {
                        color(parent, gp);
                    }

                    // for right right and right left
                    left(gp);
                }
            }
        }
    }

    Node_t<keyT, valT> *_successor(Node_t<keyT, valT> *x)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *temp = x;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        while (temp->left != NULL)
            temp = temp->left;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        return temp;
    }

    Node_t<keyT, valT> *_BSTreplace(Node_t<keyT, valT> *x)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (x->left != NULL and x->right != NULL)
            return _successor(x->right);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (x->left == NULL and x->right == NULL)
            return NULL;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (x->left != NULL)
            return x->left;
        else
            return x->right;
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    void _deleteNode(Node_t<keyT, valT> *v, bool *found)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *u = _BSTreplace(v);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        bool uvBlack = ((u == NULL or u->meta == BLACK) and (v->meta == BLACK));
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *parent = v->parent;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio

        if (u == NULL)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            if (v == this->root)
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                this->root = NULL;
            }
            else
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                if (uvBlack)
                {
                    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
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
        valueKey(u, v);
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
                if (sibling->rc())
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
