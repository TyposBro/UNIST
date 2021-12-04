#ifndef __TREE_H__
#define __TREE_H__
#include <sstream>
#include <cassert>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

template <class keyT, class valT>
struct Node_t
{
    keyT key;
    valT value;
    Node_t<keyT, valT> *parent, *left, *right;
    short meta; // AVL: balance factor, RB: color
};

/*
 * This struct is used for search to return two items.
 */
template <class valT>
struct Return_t
{
    valT value;
    bool valid;
};

template <class keyT, class valT>
class Tree_t
{

protected:
    Node_t<keyT, valT> *root;

    // returns matching or a parent with empty child
    Node_t<keyT, valT> *search_subtree(Node_t<keyT, valT> *root, keyT key) const
    {
        if (key == root->key)
            return root;
        else if (key < root->key)
        {
            if (root->left)
                return search_subtree(root->left, key);
            else
                return root;
        }
        else
        {
            if (root->right)
                return search_subtree(root->right, key);
            else
                return root;
        }
    }

    Node_t<keyT, valT> *get_min(Node_t<keyT, valT> *root)
    {
        if (root->left)
            return get_min(root->left);
        else
            return root;
    }

    void remove_node(Node_t<keyT, valT> *n)
    {
        if (n->left && n->right)
        {
            Node_t<keyT, valT> *r = get_min(n->right);
            n->key = r->key;
            n->value = r->value;
            remove_node(r);
        }
        else if (n->left)
        {
            n->left->parent = n->parent;
            if (n->parent)
            {
                if (n == n->parent->left)
                    n->parent->left = n->left;
                else
                    n->parent->right = n->left;
            }
            if (n == root)
            {
                root = n->left;
                n->left->parent = nullptr;
            }
            delete n;
        }
        else if (n->right)
        {
            n->right->parent = n->parent;
            if (n->parent)
            {
                if (n == n->parent->left)
                    n->parent->left = n->right;
                else
                    n->parent->right = n->right;
            }
            if (n == root)
            {
                root = n->right;
                n->right->parent = nullptr;
            }
            delete n;
        }
        else
        {
            if (n->parent)
            {
                if (n == n->parent->left)
                    n->parent->left = nullptr;
                else
                    n->parent->right = nullptr;
            }
            if (n == root)
                root = nullptr;
            delete n;
        }
    }

public:
    Tree_t<keyT, valT>()
    {
        this->root = nullptr;
    }

    void free_subtree(Node_t<keyT, valT> *r)
    {
        if (r->left)
            free_subtree(r->left);
        if (r->right)
            free_subtree(r->right);
        delete r;
        return;
    }

    ~Tree_t<keyT, valT>()
    {
        if (root)
            free_subtree(root);
    }

    int size(Node_t<keyT, valT> *n)
    {
        if (!n)
        {
            return 0;
        }
        else
        {
            int val = 1;
            if (n->left)
            {
                val += size(n->left);
            }
            if (n->right)
            {
                val += size(n->right);
            }

            return val;
        }
    }

    Node_t<keyT, valT> *insert_internal(keyT key, valT value, short meta = 0)
    {
        Node_t<keyT, valT> *ret;
        if (!root)
        {
            root = new Node_t<keyT, valT>({key, value, nullptr, nullptr, nullptr, meta});
            ret = root;
            return ret;
        }
        Node_t<keyT, valT> *n = search_subtree(root, key);
        if (n->key == key)
        {
            n->value = value;
            ret = n;
        }
        else if (n->key > key)
        {
            assert(n->left == nullptr);
            n->left = new Node_t<keyT, valT>({key, value, n, nullptr, nullptr, meta});
            ret = n->left;
        }
        else
        {
            assert(n->right == nullptr);
            n->right = new Node_t<keyT, valT>({key, value, n, nullptr, nullptr, meta});
            ret = n->right;
        }
        return ret;
    }

    void insert(keyT key, valT value)
    {
        insert_internal(key, value);
        assert(check_order());
    }

    bool remove(keyT key)
    {
        if (!root)
            return false;
        Node_t<keyT, valT> *n = search_subtree(root, key);
        if (n && n->key == key)
        {
            remove_node(n);
            assert(check_order());
            return true;
        }
        else
            return false;
    }

    Return_t<valT> search(keyT key)
    {
        if (!root)
            return {valT(), false};
        Node_t<keyT, valT> *n = search_subtree(root, key);
        if (n && n->key == key)
            return {n->value, true};
        else
            return {valT(), false};
    }

    bool check_order_subtree(Node_t<keyT, valT> *root)
    {
        bool ret = true;
        if (root->left)
        {
            ret &= root->key > root->left->key;
            ret &= check_order_subtree(root->left);
        }
        if (root->right)
        {
            ret &= root->key < root->right->key;
            ret &= check_order_subtree(root->right);
        }
        return ret;
    }

    bool check_order(void)
    {
        if (root)
            return check_order_subtree(root);
        else
            return true;
    }

    string to_string(Node_t<keyT, valT> *n)
    {
        if (!n)
            return string("EMPTY");
        stringstream ret;
        ret << "<" << n->key << "," << n->value << "> (" << n->meta << ")";
        return ret.str();
    }

    string to_string_pre_order(Node_t<keyT, valT> *root)
    {
        stringstream ret;
        if (root)
        {
            ret << to_string(root) << endl;
            if (root->left)
                ret << to_string_pre_order(root->left);
            if (root->right)
                ret << to_string_pre_order(root->right);
        }
        return ret.str();
    }

    string to_string_pre_order(void)
    {
        return to_string_pre_order(root);
    }

    string to_string_level_order()
    {
        int count = size(root);
        stringstream ret;
        queue<Node_t<keyT, valT> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node_t<keyT, valT> *curr = q.front();
            q.pop();

            ret << to_string(curr) << endl;

            if (!curr)
            {
                continue;
            }

            if (--count == 0)
            {
                break;
            }

            q.push(curr->left);
            q.push(curr->right);
        }

        return ret.str();
    }

    void dump(Node_t<keyT, valT> *n)
    {
        cout << to_string(n) << endl;
    }

    void dump_subtree(Node_t<keyT, valT> *root, string prefix = string(""))
    {
        if (!root)
            return;
        cout << prefix << to_string(root) << endl;
        ;
        if (root->left)
            dump_subtree(root->left, prefix + string("l-"));
        if (root->right)
            dump_subtree(root->right, prefix + string("r-"));
    }

    void rotate(Node_t<keyT, valT> *n, bool direction)
    {
        // Implement rotation here
        if (direction)
        {
            // Rotate Clockwise
            if (n->left)
            {
                Node_t<keyT, valT> *temp = n->left;
                Node_t<keyT, valT> *subTree = temp->right;
                temp->right = n;
                n->left = subTree;

                // change parents
                temp->parent = n->parent;
                n->parent = temp;
                if (subTree)
                {
                    subTree->parent = n;
                }
                n = temp;
                if (!n->parent)
                {
                    root = n;
                }

                return;
            }
        }
        if (n->right)
        {
            Node_t<keyT, valT> *temp = n->right;
            Node_t<keyT, valT> *subTree = temp->left;
            temp->left = n;
            n->right = subTree;

            // change parents
            temp->parent = n->parent;
            n->parent = temp;
            if (subTree)
            {
                subTree->parent = n;
            }

            n = temp;
            if (!n->parent)
            {
                root = n;
            }
            return;
        }
    }
};
#endif
