#include <iostream>
#include <stack>

#include "Tree.h"

void shrj(TTree* root) {
    if (!root) return;

    TTree *current = root;
    TTree *prev = nullptr;
    while (current) {
        if (prev == current->parent) {
            if (current->left) {
                prev = current;
                current = current->left;
            } else if (current->right) {
                prev = current;
                current = current->right;
            } else {
                // Лист
                std::cout << current->data << " ";
                prev = current;
                current = current->parent;
            }
        }
        else if (prev == current->left) {
            if (current->right) {
                prev = current;
                current = current->right;
            } else {
                std::cout << current->data << " ";
                prev = current;
                current = current->parent;
            }
        }
        else if (prev == current->right) {
            std::cout << current->data << " ";
            prev = current;
            current = current->parent;
        }
    }
}

int main(){
    TTree* tree = new TTree('A');
    TTree* B = new TTree('B');
    TTree* C = new TTree('C');
    TTree* D = new TTree('D');
    TTree* E = new TTree('E');
    TTree* F = new TTree('F');
    TTree* G = new TTree('G');
    TTree* H = new TTree('H');
    TTree* I = new TTree('I');

    tree->left = B;
    B->parent = tree;
    B->left = D;
    D->parent = B;
    tree->right = C;
    C->parent = tree;
    C->left = E;
    E->parent = C;
    C->right = F;
    F->parent = C;
    E->right = G;
    G->parent = E;
    F->right = H;
    H->parent = F;
    F->right = I;
    I->parent = F;

    shrj(tree);

    delete D;
    delete B;
    delete I;
    delete G;
    delete H;
    delete F;
    delete E;
    delete C;
    delete tree;
}