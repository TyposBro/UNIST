#ifndef TO_POSTFIX_H
#define TO_POSTFIX_H

#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;
bool abc(const char &op);
bool operators(const char &op);
int precedence(const char &op);
bool num(const char &op);
string add_space(const string &infix, int i, bool empty = true);
bool check_unary(const string &infix, int i);
string whitespace(const string &infix);
string simplify(const string &infix);

string to_postfix(const string &infix)
{
    Stack<char> s;
    string postfix;
    string my = whitespace(infix);
    my = simplify(my);

    for (int i = 0; i < my.length(); i++)
    {
        string foo(1, my[i]);
        char bar = my[i];
        // check for unary minus sign
        if (check_unary(my, i))
            postfix += my[i];

        else if (abc(my[i]))
        {
            if (abc(my[i + 1]))
            {
                postfix += my[i];
            }
            else
            {
                postfix += my[i] + add_space(my, i);
            }
        }
        else if (num(my[i]))
        {

            if (num(my[i + 1]))
            {
                postfix += my[i];
            }
            else if (s.empty() && i == my.length() - 1)
            {
                postfix += my[i];
            }
            else
            {
                postfix += my[i] + add_space(my, i);
            }
        }

        else if (my[i] == '(')
            s.push(my[i]);
        else if (my[i] == ')')
        {
            while (s.top() != '(' && !s.empty())
            {
                string c(1, s.top());
                postfix += c + add_space(my, i);
                s.pop();
            }
            if (s.top() == '(')
                s.pop();
        }
        else if (operators(my[i]))
        {

            if (s.empty())
                s.push(my[i]);
            else
            {
                if (precedence(my[i]) > precedence(s.top()))
                    s.push(my[i]);
                // else if (precedence(my[i]) == precedence(s.top()))
                //     s.push(my[i]);
                else
                {
                    while (!s.empty() && precedence(my[i]) <= precedence(s.top()))
                    {
                        string c(1, s.top());
                        postfix += c + add_space(my, i);
                        s.pop();
                    }
                    s.push(my[i]);
                }
            }
        }
    }

    while (!s.empty())
    {
        string c(1, s.top());
        s.pop();
        postfix += c;
        if (!s.empty())
            postfix += ' ';
    }

    return postfix;
}

bool abc(const char &op)
{

    return (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z');
}

bool operators(const char &op)
{

    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
};
int precedence(const char &op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
};

bool num(const char &op)
{

    return (op == '1' || op == '2' || op == '3' || op == '4' || op == '5' || op == '6' || op == '7' || op == '8' || op == '9' || op == '0' || op == '.');
};

string add_space(const string &infix, int i, bool empty /*= true*/)
{
    return " ";
};

bool check_unary(const string &infix, int i)
{
    // if (infix[i] == '-' && num(infix[i + 1]) && !num(infix[i - 1]))
    if (infix[i] == '-' && infix[i - 1] == ')')
        return false;

    else if (infix[i] == '-' && !num(infix[i - 1]))
        return true;

    // else if (i == 0 && infix[i] == '-')
    //     return true;
    else
        return false;
};

string whitespace(const string &infix)
{
    string result = "";
    for (int i = 0; i < infix.length(); i++)
    {

        if (infix[i] == ' ')
            continue;
        result += infix[i];
    }

    return result;
}

string simplify(const string &infix)
{
    string result = "";
    for (int i = 0; i < infix.length(); i++)
    {

        if (infix[i] == '-' && infix[i + 1] == '(')
        {
            result += "-1*";
            continue;
        }

        result += infix[i];
    }
    return result;
};

#endif // TO_POSTFIX_H
