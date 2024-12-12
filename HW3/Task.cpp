#include "RBTree.h"

int main() {
    RBTree<int> t;

    t.insert(40); t.insert(20); t.insert(10); t.insert(30);
    t.insert(50); t.insert(60); t.insert(90); t.insert(70);
    t.insert(55); t.insert(15); t.insert(35); t.insert(45);
    printTree(t.gettop(), true);

}