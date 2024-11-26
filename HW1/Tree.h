#ifndef BTREE_H
#define BTREE_H

struct BTree {
    BTree *left;
    BTree *right;
    char data;

    explicit BTree(char data , BTree *left = nullptr , BTree *right = nullptr): data(data), left(left), right(right) {}
};

struct TTree {
    TTree *left;
    TTree *parent;
    TTree *right;
    char data;

    explicit TTree(char data , TTree *parent = nullptr, TTree *left = nullptr , TTree *right = nullptr): data(data), left(left), parent(parent), right(right) {}
};
#endif //BTREE_H
