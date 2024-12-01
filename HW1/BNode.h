#ifndef BNODE_H
#define BNODE_H

template <class T>
struct BNode {
    BNode *left;
    BNode *right;
    T data;

    explicit BNode(T data , BNode *left = nullptr , BNode *right = nullptr): data(data), left(left), right(right) {}
};

template <class T>
struct BTNode {
    BTNode *left;
    BTNode *parent;
    BTNode *right;
    T data;

    explicit BTNode(T data , BTNode *parent = nullptr, BTNode *left = nullptr , BTNode *right = nullptr): data(data), left(left), parent(parent), right(right) {}
};
#endif //BNODE_H
