#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <stack>

enum Color {RED, BLACK};

template <class T>
struct Node {
    Node *left;
    Node *parent;
    Node *right;
    T data;
    Color color;
    explicit Node(T data ,Color color, Node *parent = nullptr, Node *left = nullptr , Node *right = nullptr): data(data), color(color), left(left), parent(parent), right(right) {}
};

template <class  T>
class RBTree
{
    Node<T>*root;
public:
    static Node<T>* nil;

    const Node<T>* gettop()
    {
        return root;
    }
    RBTree():root(nullptr){}
    ~RBTree()
    {
        if (!root) return;
        std::stack<Node<T>*> st;

        st.push(root);
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            if(t == nullptr)
                continue;

            if(t->left != nil)
                st.push(t->left);
            if(t->right != nil)
                st.push(t->right);
            delete t;
        }
    }
     void insert(T data)
     {
         if(!root)
         {
             root = new Node<T>(data, BLACK, nullptr,nil,nil);
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
                 if(target->left != nil)
                 {
                     target = target->left;
                 }
                 else
                 {
                     target->left = new Node<T>(data, RED, target,nil,nil);
                     insertFixup(target->left);
                     return;
                 }
             }
             else
             {
                 if(target->right != nil)
                 {
                     target = target->right;
                 }
                 else
                 {
                     target->right = new Node<T>(data, RED, target, nil,nil);
                     insertFixup(target->right);
                     return;
                 }
             }
         }
     }

    void rightRotate(Node<T>* target) {
        auto parent = target->parent;
        auto brother = target->left;
        if(parent == nullptr) {
            root = brother;
            brother->parent = nullptr;
        }
        else {
            if(parent->left == target) {
                parent->left = brother;
            }
            else {
                parent->right = brother;
            }
            brother -> parent = parent;
        }

        target->left = brother->right;
        target->left->parent = target;

        brother->right = target;
        target->parent = brother;
    }

    void leftRotate(Node<T>* target) {
        auto parent = target->parent;
        auto brother = target->right;
        if(parent == nullptr) {
            root = brother;
            brother->parent = nullptr;
        }
        else {
            if(parent->left == target) {
                parent->left = brother;
            }
            else {
                parent->right = brother;
            }
            brother -> parent = parent;
        }

        target->right = brother->left;
        target->right->parent = target;

        brother->left = target;
        target->parent = brother;
    }

    void insertFixup(Node<T> *x) {
        while (x->parent->color == RED) {
            if (x->parent == x->parent->parent->left) {
                auto y = x->parent->parent->right;
                if (y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->right) {
                        x = x->parent;
                        leftRotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    rightRotate(x->parent->parent);
                }
            } else {
                auto y = x->parent->parent->left;
                if (y->color == RED) {
                    x->parent->color = BLACK;
                    y->color = BLACK;
                    x->parent->parent->color = RED;
                    x = x->parent->parent;
                } else {
                    if (x == x->parent->left) {
                        x = x->parent;
                        rightRotate(x);
                    }
                    x->parent->color = BLACK;
                    x->parent->parent->color = RED;
                    leftRotate(x->parent->parent);
                }
            }
        }
        this->root->color = BLACK;
    }

};

template <class  T>
Node<T>* RBTree<T>::nil = new Node<T>(0,BLACK);
template<class T>
void printTree(const Node<T>* node,bool parent = false ,const std::string& prefix = "", bool isLeft = true) {
    if (!node) return;

    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");
    std::cout << node->data <<(node->color == RED ? " Red":" Nigga");

    if(parent && node->parent) std::cout<<", par: "<<node->parent->data;
    std::cout<<std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    if (node->left != RBTree<T>::nil || node->right != RBTree<T>::nil) {
        printTree(node->left, parent,newPrefix, true);
        printTree(node->right, parent,newPrefix, false);
    }
}
#endif //RBTREE_H
