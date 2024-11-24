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
    BTree* tree = new BTree('A',
        new BTree('B',
            new BTree('D')
            ),
        new BTree('C',
                new BTree('E',
                    nullptr,
                    new BTree('G')
                    ),
                new BTree('F',
                    new BTree('H'),
                    new BTree('I')
                    )
            )
        );

    shrj(tree);
}