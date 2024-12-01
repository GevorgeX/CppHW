#include <iostream>
#include "BSTree.h"

int main()
{
    BSTree<int> t;
    t.insert(40); t.insert(20); t.insert(10); t.insert(30);
    t.insert(50); t.insert(60); t.insert(40); t.insert(70);
    t.insert(55);

    printTree(t.gettop());

    std::cout <<"----------------------" <<std::endl;
    t.remove(70);
    printTree(t.gettop());

    std::cout <<"----------------------" <<std::endl;
    t.remove(60);
    printTree(t.gettop());

    std::cout <<"----------------------" <<std::endl;
    t.remove(40);
    printTree(t.gettop());

}

