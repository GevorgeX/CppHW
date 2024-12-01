#ifndef BNODE_H
#define BNODE_H

struct BNode {
    BNode *left;
    BNode *right;
    char data;

    explicit BNode(char data , BNode *left = nullptr , BNode *right = nullptr): data(data), left(left), right(right) {}
};

struct BTNode {
    BTNode *left;
    BTNode *parent;
    BTNode *right;
    char data;

    explicit BTNode(char data , BTNode *parent = nullptr, BTNode *left = nullptr , BTNode *right = nullptr): data(data), left(left), parent(parent), right(right) {}
};
#endif //BNODE_H
