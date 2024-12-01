#include <iostream>
#include "BNode.h"

void shrj(BTNode<char>* root) {
    if (!root) return;

    BTNode<char>*current = root;
    BTNode<char>*prev = nullptr;
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
    auto* tree = new BTNode('A');
    auto* B = new BTNode('B');
    auto* C = new BTNode('C');
    auto* D = new BTNode('D');
    auto* E = new BTNode('E');
    auto* F = new BTNode('F');
    auto* G = new BTNode('G');
    auto* H = new BTNode('H');
    auto* I = new BTNode('I');

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