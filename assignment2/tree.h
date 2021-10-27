#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

using namespace std;

/*
 * Recursive binary tree structure for building expression tree
 *
 * Constructors: Tree(char, Tree*, Tree*) and Tree(string, Tree*, Tree*)
 *      pointers will be automatically set to NULL if omitted
 *
 * Destructor: recursively destruct whole tree
 *
 */

Queue<string> parser(const string &postfix);
bool isOperator(const string &op);

struct Tree
{
    string expr;
    Tree *left;
    Tree *right;

    explicit Tree(char h, Tree *l = NULL, Tree *r = NULL)
    {
        expr = string(1, h);
        left = l;
        right = r;
    }

    explicit Tree(const string &h = string(), Tree *l = NULL, Tree *r = NULL)
    {
        expr = h;
        left = l;
        right = r;
    }

    ~Tree()
    {
        delete left;
        delete right;
    }

    int size()
    {
        int size = 1;
        if (left != NULL)
        {
            size += left->size();
        }
        if (right != NULL)
        {
            size += right->size();
        }
        return size;
    }

    void print();

    double eval();

    // My Utils

    int height();
    void printLevel(int level);
};

// -------- implement below --------

void Tree::print()
{

    for (int i = 1; i <= height(); i++)
    {
        bool printNull = (i == height());
        this->printLevel(i);
    }
}

double Tree::eval()
{
}

Tree *build_expression_tree(const string &postfix)
{
    Queue<string> expQ = parser(postfix);
    Stack<Tree *> res;
    while (!expQ.empty())
    {
        if (isOperator(expQ.front()))
        {
            Tree *r = res.top();
            res.pop();

            Tree *l = res.top();
            res.pop();

            Tree *tree = new Tree(expQ.front(), l, r);
            res.push(tree);
        }
        else
        {
            res.push(new Tree(expQ.front()));
        }
        expQ.pop();
    }

    return res.top();
}

// My Utils
Queue<string> parser(const string &postfix)
{
    Queue<string> q;

    istringstream iss(postfix);
    string s;

    while (getline(iss, s, ' '))
    {
        string c = s;
        q.push(s);
    }

    return q;
};

bool isOperator(const string &op)
{
    return (op == "+" || op == "-" || op == "*" || op == "/" || op == "^");
};

int Tree::height()
{
    if (this == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = this->left->height();
        int rheight = this->right->height();

        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void Tree::printLevel(int level)
{
    if (this == NULL)
    {
        string str = "null,";
        cout << "null,";

        return;
    }
    if (level == 1)
    {
        string str = this->expr;
        cout << this->expr << ",";
    }
    else if (level > 1)
    {
        this->left->printLevel(level - 1);
        this->right->printLevel(level - 1);
    }
};

#endif // TREE_H
