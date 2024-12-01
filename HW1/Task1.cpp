#include <iostream>
#include <stack>

#include "BNode.h"

void shrj(const BNode* tree) {
    std::stack<const BNode*> stack;
    std::stack<const BNode*> stack_print;

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
    auto D = new BNode('D');
    auto B = new BNode('B',D);
    auto I = new BNode('I');
    auto G = new BNode('G');
    auto H = new BNode('H');
    auto F = new BNode('F',H,I);
    auto E = new BNode('E',nullptr,G);
    auto C = new BNode('C',E,F );
    BNode* tree = new BNode('A',B,C);

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