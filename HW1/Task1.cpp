#include <iostream>
#include <stack>

#include "Tree.h"

void shrj(const BTree* tree) {
    std::stack<const BTree*> stack;
    std::stack<const BTree*> stack_print;

    stack.push(tree);

    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();
        if (current->left != nullptr)
            stack.push(current->left);
        if (current->right != nullptr)
            stack.push(current->right);
        stack_print.push(current);
    }

    while (!stack_print.empty()) {
        auto current = stack_print.top();
        stack_print.pop();
        std::cout << current->data << " ";
    }
}

int main(){
    auto D = new BTree('D');
    auto B = new BTree('B',D);
    auto I = new BTree('I');
    auto G = new BTree('G');
    auto H = new BTree('H');
    auto F = new BTree('F',H,I);
    auto E = new BTree('E',nullptr,G);
    auto C = new BTree('C',E,F );
    BTree* tree = new BTree('A',B,C);

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