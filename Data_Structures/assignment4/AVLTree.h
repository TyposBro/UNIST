#include "Tree.h"

template <class keyT, class valT>
class AVLTree_t : public Tree_t<keyT, valT>
{
    using Tree_t<keyT, valT>::get;
    using Tree_t<keyT, valT>::get_min;
    Node_t<keyT, valT> **root = get();
    long check_bf(Node_t<keyT, valT> *n)
    {
        // // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
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
    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    short height(Node_t<keyT, valT> *n)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (n == NULL)
            return 0;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        else
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            return n->height;
    }

    short max(short a, short b)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        return (a > b) ? a : b;
    }
    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    Node_t<keyT, valT> *newNode(keyT key, valT value, Node_t<keyT, valT> *parent = NULL)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *node = new Node_t<keyT, valT>();
        node->key = key;
        node->value = value;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        node->left = NULL;
        node->right = NULL;
        node->parent = parent;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        node->height = 1;

        return node;
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    short getBalance(Node_t<keyT, valT> *N)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (N == NULL)
            return 0;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        return height(N->left) - height(N->right);
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    Node_t<keyT, valT> *rightRotate(Node_t<keyT, valT> *n)

    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *temp = n->left;
        Node_t<keyT, valT> *subTree = temp->right;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        temp->right = n;
        n->left = subTree;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        temp->parent = n->parent;
        n->parent = temp;
        if (subTree)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            subTree->parent = n;
        }

        if (!temp->parent)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            *root = temp;
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

    Node_t<keyT, valT> *leftRotate(Node_t<keyT, valT> *n)
    {

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        Node_t<keyT, valT> *temp = n->right;
        Node_t<keyT, valT> *subTree = temp->left;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        temp->left = n;
        n->right = subTree;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        temp->parent = n->parent;
        n->parent = temp;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (subTree)
        {
            subTree->parent = n;
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (!temp->parent)
        {
            *root = temp;
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        n->height = max(height(n->left),
                        height(n->right)) +
                    1;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
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
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (node == NULL)
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            return (newNode(key, value, parent));

        if (key < node->key)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->left = insert_util(node->left, key, value, node);
        }
        else if (key > node->key)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->right = insert_util(node->right, key, value, node);
        }
        else
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        {
            node->value = value;
            return node;
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        node->height = 1 + max(height(node->left),
                               height(node->right));

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        short meta = getBalance(node);
        node->meta = meta;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta > 1 && key < node->left->key)
            return rightRotate(node);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta < -1 && key > node->right->key)
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            return leftRotate(node);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta > 1 && key > node->left->key)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio // +++++
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //// Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        return node;
    }

    Node_t<keyT, valT> *remove_util(Node_t<keyT, valT> *node, keyT key, bool *found)
    {
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (node == NULL)
            return node;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (key < node->key)
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->left = remove_util(node->left, key, found);
        else if (key > node->key)
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->right = remove_util(node->right, key, found);
        else
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            *found = true;
            if ((node->left == NULL) ||
                (node->right == NULL))
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                Node_t<keyT, valT> *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;
                free(temp);
            }
            else
            {
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                Node_t<keyT, valT> *temp = get_min(node->right);
                node->key = temp->key;
                // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
                node->value = temp->value;
                node->right = remove_util(node->right, temp->key, found);
            }
        }
        if (node == NULL)
            return node;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        node->height = 1 + max(height(node->left),
                               height(node->right));
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        int meta = getBalance(node);
        node->meta = meta;

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta > 1 &&
            getBalance(node->left) >= 0)

            return rightRotate(node);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta > 1 &&
            getBalance(node->left) < 0)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->left = leftRotate(node->left);
            return rightRotate(node); // success
        }

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta < -1 &&
            getBalance(node->right) <= 0)
            return leftRotate(node);

        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        if (meta < -1 &&
            getBalance(node->right) > 0)
        {
            // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
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
        bool found = false;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
        *root = remove_util(*root, key, &found);
        return found;
        // Lorem ipsum dolor sit amet consectetur adipisicing elit.Quo, animi similique quis corporis illo aperiam incidunt nemo quam !Laboriosam obcaecati at itaque.Sit neque consectetur sint vitae suscipit, tempora distinctio
    }
};