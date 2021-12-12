#include "Tree.h"

template <class keyT, class valT>
class AVLTree_t : public Tree_t<keyT, valT>
{
    using Tree_t<keyT, valT>::get;
    using Tree_t<keyT, valT>::get_min;
    Node_t<keyT, valT> **root = get();
    long check_bf(Node_t<keyT, valT> *n)
    {
        // Checks balance factor values in tree.
        long hr, hl, h;
        hr = hl = 0;
        if (!n)
            return 0;
        hr = check_bf(n->right);
        hl = check_bf(n->left);
        if (hr > hl)
            h = hr;
        else
            h = hl;
        h += 1;
        long bf = hl - hr;
        assert(bf == n->meta);
        assert(bf < 2);
        assert(bf > -2);
        return h;
    }

    // Optional private functions.
    // These are here to guide you, but you can just ignore these.
    Node_t<keyT, valT> *balance(Node_t<keyT, valT> *a)
    {
        // Make tree balanced
    }

    Node_t<keyT, valT> *insert_internal(keyT key, valT value)
    {
        // Helper function for insert()
    }

    void remove_node(Node_t<keyT, valT> *n)
    {
        // Helper function for remove()
    }

public:
    // Utils
    short height(Node_t<keyT, valT> *n)
    {
        if (n == NULL)
            return 0;
        else
            return n->height;
    }

    short max(short a, short b)
    {
        return (a > b) ? a : b;
    }

    Node_t<keyT, valT> *newNode(keyT key, valT value, Node_t<keyT, valT> *parent = NULL)
    {
        Node_t<keyT, valT> *node = new Node_t<keyT, valT>();
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = parent;
        node->height = 1;

        return node;
    }
    short getBalance(Node_t<keyT, valT> *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node_t<keyT, valT> *rightRotate(Node_t<keyT, valT> *n, bool LL)

    {
        Node_t<keyT, valT> *temp = n->left;
        Node_t<keyT, valT> *subTree = temp->right;

        // perform rotation
        temp->right = n;
        n->left = subTree;

        // change parents
        temp->parent = n->parent;
        n->parent = temp;
        if (subTree)
        {
            subTree->parent = n;
        }

        if (!temp->parent)
        {

            *root = temp;
        }
        else if (LL)
        {
            // LL temp->parent->left = temp;

            temp->parent->left = temp;
        }
        else
        {
            temp->parent->right = temp;
        }

        // Update heights
        n->height = max(height(n->left),
                        height(n->right)) +
                    1;
        temp->height = max(height(temp->left),
                           height(temp->right)) +
                       1;
        n->meta = getBalance(n);
        temp->meta = getBalance(temp);

        // Return new root
        return temp;
    }

    Node_t<keyT, valT> *leftRotate(Node_t<keyT, valT> *n, bool LL)
    {
        Node_t<keyT, valT> *temp = n->right;
        Node_t<keyT, valT> *subTree = temp->left;

        // Perform rotation
        temp->left = n;
        n->right = subTree;

        // change parents
        temp->parent = n->parent;
        n->parent = temp;
        if (subTree)
        {
            subTree->parent = n;
        }

        // n = temp;
        if (!temp->parent)
        {
            *root = temp;
        }
        else if (LL)
        {
            temp->parent->right = temp;
        }
        else
        {
            temp->parent->left = temp;
        }

        // Update heights
        n->height = max(height(n->left),
                        height(n->right)) +
                    1;
        temp->height = max(height(temp->left),
                           height(temp->right)) +
                       1;

        n->meta = getBalance(n);
        temp->meta = getBalance(temp);
        // Return new root
        return temp;
    }

    Node_t<keyT, valT> *insert_util(Node_t<keyT, valT> *node, keyT key, valT value, Node_t<keyT, valT> *parent = NULL)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return (newNode(key, value, parent));

        if (key < node->key)
        {

            node->left = insert_util(node->left, key, value, node);
        }
        else if (key > node->key)
        {

            node->right = insert_util(node->right, key, value, node);
        }
        else // Equal keys are not allowed in BST
        {
            node->value = value;
            return node;
        }

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left),
                               height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        short meta = getBalance(node);
        node->meta = meta;

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (meta > 1 && key < node->left->key)
            return rightRotate(node, true);

        // Right Right Case
        if (meta < -1 && key > node->right->key)
            return leftRotate(node, true);

        // Left Right Case
        if (meta > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left, false);
            return rightRotate(node, false);
        }

        // Right Left Case
        if (meta < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right, false);
            return leftRotate(node, false);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    Node_t<keyT, valT> *remove_util(Node_t<keyT, valT> *node, keyT key)
    {
        // Standard BST delete
        if (node == NULL)
            return node;
        if (key < node->key)
            node->left = remove_util(node->left, key);
        else if (key > node->key)
            node->right = remove_util(node->right, key);
        else
        {
            if ((node->left == NULL) ||
                (node->right == NULL))
            {
                Node_t<keyT, valT> *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;
                free(temp);
            }
            else
            {
                Node_t<keyT, valT> *temp = get_min(node->right);
                node->key = temp->key;
                node->parent = temp->parent;
                node->value = temp->value;
                node->right = remove_util(node->right, temp->key);
            }
        }
        if (node == NULL)
            return node;

        int meta = getBalance(node);
        node->meta = meta;

        if (meta > 1 &&
            getBalance(node->left) >= 0)
            return rightRotate(node, true);

        // Left Right Case
        if (meta > 1 &&
            getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left, false);
            return rightRotate(node, false);
        }

        // Right Right Case
        if (meta < -1 &&
            getBalance(node->right) <= 0)
            return leftRotate(node, true);

        // Right Left Case
        if (meta < -1 &&
            getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right, false);
            return leftRotate(node, false);
        }

        return node;
    }

    // MAIN
    void insert(keyT key, valT value)
    {
        // If there is no node that has the given key,
        // create a new one, place it in the right place, and store the value.
        // If there already is a node that has the given key,
        // update the value, rather than making a new one.

        *root = insert_util(*root, key, value, *root);
    }

    bool remove(keyT key)
    {
        *root = remove_util(*root, key);
        // Find the node that has the given key and remove that node.
    }
};