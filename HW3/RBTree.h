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

            if(t->left )
                st.push(t->left);
            if(t->right)
                st.push(t->right);
            delete t;
        }
    }
     void insert(T data)
     {
        auto* newNode = new Node<T>(data, RED);
        Node<T>* y = nullptr;
        Node<T>* x = root;

        while (x != nullptr) {
            y = x;
            if (newNode->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        newNode->parent = y;
        if (y == nullptr)
            root = newNode;
        else if (newNode->data < y->data)
            y->left = newNode;
        else
            y->right = newNode;

        insertFixup(newNode);
     }

    void leftRotate(Node<T>* x) {
        if (x == nullptr || x->right == nullptr)
            return;

        auto y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    //  right rotation
    void rightRotate(Node<T>* y) {
        if (y == nullptr || y->left == nullptr)
            return;

        auto x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node<T>* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                auto y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                auto y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

};

template<class T>
void printTree(const Node<T>* node,bool parent = false ,const std::string& prefix = "", bool isLeft = true) {
    if (!node) return;

    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");
    std::cout << node->data <<(node->color == RED ? " Red":" Nigga");

    if(parent && node->parent) std::cout<<", par: "<<node->parent->data;
    std::cout<<std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    if (node->left  || node->right ) {
        printTree(node->left, parent,newPrefix, true);
        printTree(node->right, parent,newPrefix, false);
    }
}
#endif //RBTREE_H
