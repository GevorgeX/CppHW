#ifndef BSTREE_H
#define BSTREE_H

#include <stack>
#include "../HW1/BNode.h"

template <class  T>
class BSTree
{
BNode<T>*root;
    public:
    const BNode<T>* gettop()
    {
        return root;
    }
    BSTree():root(nullptr){}
    ~BSTree()
    {
        if (!root) return;
        std::stack<BNode<T>*> st;

        st.push(root);
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            if(t == nullptr)
                continue;

            if(t->left)
                st.push(t->left);
            if(t->right)
                st.push(t->right);
            delete t;
        }
    }
    void insert(T data)
    {
        auto t = new BNode(data);
        if(!root)
        {
            root = t;
            return;
        }
        auto target = root;
        while (true)
        {

            if(data == target->data)
            {
                return;
            }

            if(data < target->data)
            {
                if(target->left != nullptr)
                {
                    target = target->left;
                }
                else
                {
                    target->left = t;
                    return;
                }
            }
            else
            {
                if(target->right != nullptr)
                {
                    target = target->right;
                }
                else
                {
                    target->right = t;
                    return;
                }
            }

        }

    }
    void remove(T data)
    {
        BNode<T>* parent = nullptr;
        auto target = root;
        while (true)
        {
            if(target == nullptr)
                throw std::runtime_error("No such element");

            if(data == target->data)
                break;

            parent = target;
            if(data < target->data)
                target = target->left;
            else
                target = target->right;
        }
        //case 1
        if(target->left == nullptr && target->right == nullptr)
        {
            if(parent->left == target)
                (parent)->left = nullptr;
            else
                parent->right = nullptr;
            delete target;
        }
        //case 2
        else if(target->left != nullptr && target->right == nullptr)
        {
            if(parent->left == target)
                parent->left = target->left;
            else
                parent->right = target->left;
            delete target;
        }
        else if(target->left == nullptr && target->right != nullptr)
        {
            if(parent->left == target)
                parent->left = target->right;
            else
                parent->right = target->right;
            delete target;
        }
        //case 3
        else
        {
            auto y = target->right;
            parent = target;
            while(y->left != nullptr)
            {
                parent = y;
                y = y->left;
            }
            auto t = y->data;
            remove(y->data);
            target->data = t;
        }
    }
};

template<class T>
void printTree(const BNode<T>* node, const std::string& prefix = "", bool isLeft = true) {
    if (!node) return;

    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");
    std::cout << node->data << std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    if (node->left || node->right) {
        printTree(node->left, newPrefix, true);
        printTree(node->right, newPrefix, false);
    }
}
#endif //BSTREE_H
